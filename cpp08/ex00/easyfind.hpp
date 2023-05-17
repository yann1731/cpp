#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <vector>
# include <exception>
# include <iostream>

template <typename T>
void easyfind(T container, int toFind)
{
    if (find(container.begin(), container.end(), toFind) != container.end())
        std::cout << "Found value in container" << std::endl;
    else
        std::cerr << "Error: Didn't find value in the container" << std::endl;
}

#endif