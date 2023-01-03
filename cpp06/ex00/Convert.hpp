#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <iostream>
#include <cmath>
#include <string>

class Convert
{
private:
    std::string literal;
    char charType;
    int intType;
    float floatType;
    double doubleType;
public:
    Convert();
    Convert(const std::string &literal);
    Convert(const Convert &src);
    ~Convert();
    Convert &operator=(const Convert &src);
    void convertLiteral(void);
    void findType(void);
};

#endif