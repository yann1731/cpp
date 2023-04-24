#ifndef DATA_HPP
#define DATA_HPP
# include <iostream>

struct Data
{
    Data();
    ~Data();
	double posx;
	double posy;
	double dirx;
	double diry;
	int hp;
	int mp;
};

std::ostream& operator<<(std::ostream& out, const Data& rhs);

#endif