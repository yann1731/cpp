#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename A>
void iter(A *array, size_t len, void (*f)(A&))
{
    for (size_t i = 0; i < len; i++)
        (*f)(array[i]);
}

#endif