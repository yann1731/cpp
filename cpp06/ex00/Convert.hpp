#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

class Convert
{
private:
    std::string literal;
    char charType;
    int intType;
    float floatType;
    double doubleType;
    int type;
public:
    Convert();
    Convert(const std::string &literal);
    Convert(const Convert &src);
    ~Convert();
    Convert &operator=(const Convert &src);
    void convertLiteral(void);
    void findType(void);
    bool checkChar(void);
    bool checkInt(void);
    bool checkFloat(void);
    bool checkDouble(void);
};

#endif