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
    this->_toComp = other._toComp;
    this->_bufferData = other._bufferData;
    this->_bufferInputFile = other._bufferInputFile;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
    this->_bitcoinRate = rhs._bitcoinRate;
    this->_toComp = rhs._toComp;
    this->_bufferData = rhs._bufferData;
    this->_bufferInputFile = rhs._bufferInputFile;
    return *this;
}

void BitcoinExchange::storeData(void) {
    std::pair<string, string> newPair;
    string date;
    string rate;
    std::size_t comma;
    std::size_t nl;
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
    // std::pair<string, float> compPair;
    string date;
    string val;
    // float convertedVal;
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
        if (_bufferInputFile.find('\n') == string::npos)
            break;
    }
}

void BitcoinExchange::checkDate(std::string& date) {
    int year; // 2009-2022
    int month;
    int day;
    string yearStr;
    string monthStr;
    string dayStr;
    std::size_t firstDash = date.find('-');
    std::size_t secondDash = date.rfind('-');

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
    if (year < 2009 || year > 2022)
        throw InvalidDate();
    
}

void BitcoinExchange::checkVal(std::string& val) {
    (void) val;
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

