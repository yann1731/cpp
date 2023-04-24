#pragma once
#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <exception>
#include <iomanip>

class Convert
{
private:
    std::string literal;
    char charType;
    int intType;
    float floatType;
    double doubleType;
    int type;
    bool pseudoLiteral;
    void findType(void);
    bool checkChar(void);
    bool checkInt(void);
    bool checkFloat(void);
    bool checkDouble(void);
    void doConversion(void);
    void doPrint(void);
    void checkForPseudoLiteral(void);
    void handlePseudoLiteral(void);
public:
    Convert();
    Convert(const std::string &literal);
    Convert(const Convert &src);
    ~Convert();
    Convert &operator=(const Convert &src);
    void convertLiteral(void);
    class BadInput: public std::exception
    {
        const char *what() const throw();
    };
    class ThisIsVeryWrong: public std::exception
    {
        const char *what() const throw();
    };
};

#endif