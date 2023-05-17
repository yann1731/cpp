#include "easyfind.hpp"
#include <stack>

int main(void)
{
    std::vector<int> vec1;
	
    for (int i = 0; i < 26; i++)
        vec1.push_back(i);

    easyfind<std::vector<int> >(vec1, 4);

	try {
		easyfind<std::vector<int> >(vec1, 65);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
    return 0;
}