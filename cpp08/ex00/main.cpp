#include "easyfind.hpp"

int main(void)
{
    std::vector<int> vec1;

    for (int i = 0; i < 26; i++)
        vec1.push_back(i);

    easyfind<std::vector<int> >(vec1, 4);
    return 0;
}