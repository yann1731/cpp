#include "whatever.hpp"

int main(void)
{
	int a = 6;
	int b = 10;
	int c = 10;

	std::cout << min<int>(b, a) << std::endl;
	std::cout << max<int>(b, a) << std::endl;
}