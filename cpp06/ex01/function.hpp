#ifndef FUNCTION_HPP
#define FUNCTION_HPP
# include <iostream>

struct Data
{
	double posx;
	double posy;
	double dirx;
	double diry;
	int hp;
	int mp;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif