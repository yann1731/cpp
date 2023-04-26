#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
# include <map>
# include <unordered_map>
# include <algorithm>
# include <iostream>
# include <exception>
# include <fstream>

using std::map;
using std::unordered_map;
using std::string;
using std::cout;
using std::endl;
using std::exception;

// • Each line in this file must use the following format: "date | value".
// • A valid date will always be in the following format: Year-Month-Day.
// • A valid value must be either a float or a positive integer between 0 and 1000.
class BitcoinExchange
{
private:
    BitcoinExchange();
    map<string, float> _bitcoinRate;
    string _bufferInputFile;
    string _bufferData;
    void checkDate(std::string& date);
    void checkVal(std::string& val);
public:
    BitcoinExchange(char **argv);
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange& rhs);
    void storeData(void);
    void compareVal(void);
private:
    class NumberTooLarge: public exception {
        const char* what() const throw();
    };
    class InvalidDate: public exception {
        const char* what() const throw();
    };
    class NegativeNumber: public exception {
        const char* what() const throw();
    };
    class CouldNotOpenFile: public exception {
        const char* what() const throw();
    };
    class BadValue: public exception {
        const char* what() const throw();
    };
    class NumberTooSmall: public exception {
        const char* what() const throw();
    };
};

#endif 