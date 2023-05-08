#include "iter.hpp"

void addOne(int &num)
{
	num++;
}

void printString(std::string &str)
{
    std::cout << str;
}

int main(void)
{
	try {
		int a[12];
		std::string str[5] = {"Hello ", "Comment ", "Ca ", "Vas ", "Okbyela"};

		for (int i = 0; i < 12; i++)
			a[i] = i + 1;
		for (int i = 0; i < 12; i++)
			std::cout << a[i] << std::endl;

		iter(a, 12, &addOne);

		for (int i = 0; i < 12; i++)
			std::cout << a[i] << std::endl;

		iter(str, 5, &printString);
	}
	catch (const std::exception& e) {
		cerr << e.what() << endl;
	}


    return 0;
}