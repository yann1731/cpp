#include "Fixed.hpp"

Fixed::Fixed ()
{
	numberValue = 0;
}

Fixed::Fixed (const int n)
{
	numberValue = (n << fractionalBits);
}

Fixed::Fixed (const float n)
{
	numberValue = (n * (1 << fractionalBits));
}

Fixed::Fixed (const Fixed& fixed)
{
	numberValue = fixed.numberValue;
}

Fixed::~Fixed (void)
{
}

void Fixed::setValue(float value)
{
	numberValue = value;
}

Fixed& Fixed::max (Fixed& fixedOne, Fixed& fixedTwo)
{
	if (fixedOne > fixedTwo)
		return (fixedOne);
	else
		return (fixedTwo);
}

Fixed& Fixed::max (const Fixed& fixedOne, const Fixed& fixedTwo)
{
	if ((Fixed&) fixedOne > (Fixed&) fixedTwo)
		return ((Fixed&) fixedOne);
	else
		return ((Fixed&) fixedTwo);
}

Fixed& Fixed::min (Fixed& fixedOne, Fixed& fixedTwo)
{
	if (fixedOne < fixedTwo)
		return (fixedOne);
	else
		return (fixedTwo);
}

Fixed& Fixed::min (const Fixed& fixedOne, const Fixed& fixedTwo)
{
	if ((Fixed&) fixedOne < (Fixed&) fixedTwo)
		return ((Fixed&) fixedOne);
	else
		return ((Fixed&) fixedTwo);
}

void Fixed::setNumberValue (int n)
{
	numberValue = n;
}

int	Fixed::getNumberValue (void)
{
	return (numberValue);
}

Fixed &Fixed::operator= (const Fixed& fixed)
{
	this->numberValue = fixed.numberValue;
	return (*this);
}

std::ostream& operator<< (std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool Fixed::operator> (const Fixed& fixed)
{
	return (toFloat() > fixed.toFloat());
}

bool Fixed::operator< (const Fixed& fixed)
{
	return (toFloat() < fixed.toFloat());
}

bool Fixed::operator>= (const Fixed& fixed)
{
	return (toFloat() >= fixed.toFloat());
}

bool Fixed::operator<= (const Fixed& fixed)
{
	return (toFloat() <= fixed.toFloat());
}

Fixed Fixed::operator+ (const Fixed& fixed)
{
	Fixed returnFixed(toFloat() + fixed.toFloat());
	return (returnFixed);
}

Fixed Fixed::operator- (const Fixed& fixed)
{
	Fixed returnFixed(toFloat() - fixed.toFloat());
	return (returnFixed);
}

Fixed Fixed::operator* (const Fixed& fixed)
{
	Fixed returnFixed(toFloat() * fixed.toFloat());
	return (returnFixed);
}

Fixed Fixed::operator/ (const Fixed& fixed)
{
	Fixed returnFixed(toFloat() / fixed.toFloat());
	return (returnFixed);
}

bool Fixed::operator== (const Fixed& fixed)
{
	return (toFloat() == fixed.toFloat());
}

bool Fixed::operator!= (const Fixed& fixed)
{
	return (toFloat() != fixed.toFloat());
}

Fixed Fixed::operator++ ()
{
	numberValue++;
	return (*this);
}

Fixed Fixed::operator++ (int)
{
	Fixed tmp(*this);
	numberValue++;
	return (tmp);
}

Fixed Fixed::operator-- ()
{
	numberValue--;
	return (*this);
}

Fixed Fixed::operator-- (int)
{
	Fixed tmp(*this);
	numberValue--;
	return (tmp);
}

float Fixed::toFloat (void) const
{
	return ((float) numberValue / (float)(1 << Fixed::fractionalBits));
}

int Fixed::toInt (void) const
{
	return ((int) numberValue >> fractionalBits);
}