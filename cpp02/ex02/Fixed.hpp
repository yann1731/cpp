#ifndef FIXED_HPP
#define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
private:
    int _value;
    static const int _fractional_bits = 8;
public:
    Fixed();
    Fixed(const int param);
    Fixed(const float param);
    Fixed(const Fixed &fixed);
    void operator=(const Fixed &fixed);
    ~Fixed();
    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif