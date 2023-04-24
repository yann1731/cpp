#include "function.hpp"

int main(void)
{
	Data *ptr = new Data;
	uintptr_t deser = 0;

	std::cout << *ptr << std::endl;

	deser = serialize(ptr);

	ptr = NULL;

	std::cout << deser << std::endl;

	ptr = deserialize(deser);

	std::cout << *ptr << std::endl;

	delete ptr;
}