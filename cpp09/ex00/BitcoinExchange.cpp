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

    while (_bufferData.size() != 0) {
        
    }
}

void BitcoinExchange::storeInput(void) {

}

const char* BitcoinExchange::NumberTooLarge::what() const throw() {
    return "Error: Number is too large";
}

const char* BitcoinExchange::InvalidDate::what() const throw() {
    return "Error: Date given is invalid";
}

const char* BitcoinExchange::NegativeNumber::what() const throw() {
    return "Error: Number is negative";
}

const char* BitcoinExchange::CouldNotOpenFile::what() const throw() {
    return "Error: Could not open file";
}

