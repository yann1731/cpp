#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <vector>
# include <exception>
# include <iostream>

template <typename T>
void easyfind(T container, int toFind)
{
    for(typename T::iterator it = container.begin(); it != container.end(); it++)
    {
        if (*it == toFind)
        {
            std::cout << "Found value in container" << std::endl;
            return ;
        }
    }
    class NotFoundException: public std::exception
    {
        const char *what() const throw()
        {
            return "Exception: Value not found";
        }
    };
    throw NotFoundException();
}

#endif