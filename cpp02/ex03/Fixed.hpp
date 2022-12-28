#ifndef FIXED_HPP
#define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
private:
	int numberValue;
	static const int fractionalBits = 8;
public:
	Fixed (void);
	Fixed (const int n);
	Fixed (const float n);
	Fixed (const Fixed& fixed);
	~Fixed (void);
	static Fixed& max(Fixed& fixedOne, Fixed& fixedTwo);
	static Fixed& max(const Fixed& fixedOne, const Fixed& fixedTwo);
	static Fixed& min(Fixed& fixedOne, Fixed& fixedTwo);
	static Fixed& min(const Fixed& fixedOne, const Fixed& fixedTwo);
	void setNumberValue (int n);
	int getNumberValue (void);
	void operator= (const Fixed& fixed);
	bool operator> (const Fixed& fixed);
	bool operator< (const Fixed& fixed);
	bool operator>= (const Fixed& fixed);
	bool operator<= (const Fixed& fixed);
	bool operator== (const Fixed& fixed);
	bool operator!= (const Fixed& fixed);
	Fixed operator+ (const Fixed& fixed);
	Fixed operator- (const Fixed& fixed);
	Fixed operator* (const Fixed& fixed);
	Fixed operator/ (const Fixed& fixed);
	Fixed operator++ ();
	Fixed operator++ (int);
	Fixed operator-- ();
	Fixed operator-- (int);
	float toFloat (void) const;
	int toInt (void) const;
};

std::ostream& operator<< (std::ostream& out, const Fixed& fixed);

#endif