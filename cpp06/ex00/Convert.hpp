#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <iostream>
#include <cmath>

class Convert
{
private:
    std::string literal;
public:
    Convert();
    Convert(const std::string &literal);
    Convert(const Convert &src);
    Convert();
    Convert &operator=(const Convert &src);
};

#endif