#include "Fixed.hpp"

// class Fixed
// {
// private:
//     int _value;
//     static const int _fractional_bits = 8;
// public:
//     Fixed();
//     Fixed(const Fixed &fixed);
//     Fixed &operator=(const Fixed &fixed);
//     ~Fixed();
//     int getRawBits(void) const;
//     void setRawBits(int const raw);
// };

Fixed::Fixed(): _value(0)
{
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

int Fixed::getRawBits(void) const
{
    return (_value);
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}