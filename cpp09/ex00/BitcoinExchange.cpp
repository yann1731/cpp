#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(char **argv) {
    std::fstream file;
    file.open(argv[1]);
    if (file.fail())
        throw CouldNotOpenFile();
    std::getline(file, this->_bufferInputFile, '\0');
    file.close();
    file.open("data.csv");
    if (file.fail())
        throw CouldNotOpenFile();
    std::getline(file, _bufferData, '\0');
    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    this->_bitcoinRate = other._bitcoinRate;
    this->_bufferData = other._bufferData;
    this->_bufferInputFile = other._bufferInputFile;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
    this->_bitcoinRate = rhs._bitcoinRate;
    this->_bufferData = rhs._bufferData;
    this->_bufferInputFile = rhs._bufferInputFile;
    return *this;
}

void BitcoinExchange::storeData(void) {
    std::pair<string, string> newPair;
    string date;
    string rate;
    size_t comma;
    size_t nl;
    float convertedRate;

    _bufferData = _bufferData.substr(_bufferData.find('\n') + 1); //to skip the first line of the .csv file
    while (_bufferData.size() != 0) {
        comma = _bufferData.find(',');
        nl = _bufferData.find('\n');
        date = _bufferData.substr(0, comma);
        rate = _bufferData.substr(comma + 1, nl - comma);
        convertedRate = std::stof(rate);
        _bitcoinRate.insert(std::make_pair(date, convertedRate));
        _bufferData = _bufferData.substr(nl + 1);
    }
}

void BitcoinExchange::compareVal(void) {
    string date;
    string val;
    string newLine;
    while (_bufferInputFile.size()) {
        newLine = _bufferInputFile.substr(0, _bufferInputFile.find('\n'));
        _bufferInputFile = _bufferInputFile.substr(_bufferInputFile.find('\n') + 1);
        while (newLine.find(" ") != string::npos) {
            newLine.erase(newLine.find(" "), 1);
        }
            date = newLine.substr(0, newLine.find('|'));
            val = newLine.substr(newLine.find('|') + 1);
        try
        {
            checkDate(date);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << "=> " << newLine << '\n';
            exit(1);
        }
        try
        {
            checkVal(val);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            exit(1);
        }
        float valueToMultiply = std::atof(val.c_str());
        size_t count = _bitcoinRate.count(date);
        if (count == 1) {
            float value = _bitcoinRate.at(date);  //2011-01-03 => 3 = 0.9
            cout << date << " => " << valueToMultiply << " = " << (valueToMultiply * value) << endl;
        }
        else {
            map<string, float>::iterator it = _bitcoinRate.lower_bound(date);
            if (it != _bitcoinRate.begin())
                cout << date << " => " << valueToMultiply << " = " << (valueToMultiply * it->second) << endl;
            else
                std::cerr << "Error: date is out of range => " << date << endl;
        }
        if (_bufferInputFile.find('\n') == string::npos)
            break;
    }
}

void BitcoinExchange::checkDate(std::string& date) {
    int year; // 2009-2022, %4 to check for leap year
    int month; //31 day months: 1-3-5-7-8-10-12, 30 day months: 4-6-9-11, 28 || 29: 02
    int day;
    string yearStr;
    string monthStr;
    string dayStr;
    size_t firstDash = date.find('-');
    size_t secondDash = date.rfind('-');

    if (firstDash == string::npos || secondDash == string::npos || (firstDash == secondDash)) {
        throw InvalidDate();
    }
    yearStr = date.substr(0, firstDash);
    monthStr = date.substr(firstDash + 1, 2);
    dayStr = date.substr(secondDash + 1, 2);
    year = std::atoi(yearStr.c_str());
    month = std::atoi(monthStr.c_str());
    day = std::atoi(dayStr.c_str());
    if (!year || !month || !day)
        throw InvalidDate();
    if (month < 1 || month > 12)
        throw InvalidDate();
    if (day < 1 || day > 31)
        throw InvalidDate();
    if (month == 2 && day > 29)
        throw InvalidDate();
    if (month == 2 && year % 4 != 0 && day == 29)
        throw InvalidDate();
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30)
            throw InvalidDate();
    }
}

void BitcoinExchange::checkVal(std::string& val) {
    float convertedVal = std::atof(val.c_str());
    if (!convertedVal) {
        if (val.size() != 1 || val[0] != '0')
            throw BadValue();
    }
    if (convertedVal < 0.0f)
        throw NumberTooSmall();
    if (convertedVal > 1000.0f)
        throw NumberTooLarge();
}

const char* BitcoinExchange::NumberTooLarge::what() const throw() {
    return "Error: Number is too large";
}

const char* BitcoinExchange::InvalidDate::what() const throw() {
    return "Error: bad input";
}

const char* BitcoinExchange::NegativeNumber::what() const throw() {
    return "Error: Number is negative";
}

const char* BitcoinExchange::CouldNotOpenFile::what() const throw() {
    return "Error: Could not open file";
}

const char* BitcoinExchange::BadValue::what() const throw() {
    return "Error: could not convert value";
}

const char* BitcoinExchange::NumberTooSmall::what() const throw() {
    return "Error: number too small";
}