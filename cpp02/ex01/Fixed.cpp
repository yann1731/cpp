#include "Fixed.hpp"

// class Fixed
// {
// private:
//     int _value;
//     static const int _fractional_bits = 8;
// public:
//     Fixed();
//     Fixed(const int param);
//     Fixed(const float param);
//     Fixed(const Fixed &fixed);
//     void operator=(const Fixed &fixed);
//     ~Fixed();
//     float toFloat(void) const;
//     int toInt(void) const;
//     int getRawBits(void) const;
//     void setRawBits(int const raw);
// };

Fixed::Fixed(): _value(0)
{
}

Fixed::Fixed(const int param)
{
    _value = param << _fractional_bits;
}

Fixed::Fixed(const float param)
{
    _value = param * (1 << _fractional_bits);
}

Fixed::Fixed(const Fixed &fixed)
{
    _value = fixed._value;
}

void Fixed::operator= (const Fixed &fixed)
{
    _value = fixed._value;
}

Fixed::~Fixed ()
{
}

float Fixed::toFloat(void) const
{
    return (float(_value) / float((1 << _fractional_bits)));
}

int Fixed::toInt(void) const
{
    return (_value >> _fractional_bits);
}

int Fixed::getRawBits(void) const
{
    return (_value);
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}