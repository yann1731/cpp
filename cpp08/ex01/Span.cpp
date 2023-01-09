#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n): _n(n) {}

Span::Span(const Span &rhs)
{
    _n = rhs._n;
    _vec = rhs._vec;
}

Span::~Span() {}

Span &Span::operator=(const Span &rhs)
{
    _n = rhs._n;
    _vec = rhs._vec;
    return *this;
}

void Span::addNumber(int n)
{
    if (_vec.size() >= _n)
        throw VectorFull();
    else
        _vec.push_back(n);
}

int Span::shortestSpan(void)
{
    if (_vec.size() <= 1)
        throw ContainerTooSmall();
    int smallest = 1000;

    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
    {
        for (std::vector<int>::iterator it2 = _vec.begin(); it2 != _vec.end(); it2++)
        {
            if (it != it2)
            {
                if (*it > *it2)
                {
                    if ((*it - *it2) < smallest)
                        smallest = *it - *it2;
                }
            }
        } 
    }
    return smallest;
}

int Span::longestSpan(void)
{
    if (_vec.size() <= 1)
        throw ContainerTooSmall();
    int longest;

    longest = *(std::max_element(_vec.begin(), _vec.end())) - *(std::min_element(_vec.begin(), _vec.end()));
    return longest;
}

void Span::displayContent(void) const
{
    int i = 0;
    for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); it++)
    {
        std::cout << _vec[i] << " ";
        i++;
    }
}