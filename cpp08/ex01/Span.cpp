#include "Span.hpp"
#include <numeric>

Span::Span() {}

Span::Span(unsigned int n): _vec(0), _n(n) {}

Span::Span(const Span &other)
{
    _vec = other._vec;
}

Span::~Span() {}

Span &Span::operator=(const Span &rhs)
{
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

std::vector<int>::iterator &Span::addNnumber(std::vector<int>::iterator &begin, std::vector<int>::iterator &end, std::vector<int>::iterator &it)
{
    if (_vec.size() < static_cast<std::size_t>(std::distance(begin, end)))
        throw ContainerTooSmall();
    it = _vec.insert(it, begin, end);
    return (it);
}

int Span::shortestSpan(void)
{
    if (_vec.size() <= 1)
        throw ContainerTooSmall();
    std::vector<int> vecCopy = _vec;
    std::sort(vecCopy.begin(), vecCopy.end());
    std::adjacent_difference(vecCopy.begin(), vecCopy.end(), vecCopy.begin());
    std::transform(vecCopy.begin(), vecCopy.end(), vecCopy.begin(), static_cast<int(*)(int)>(&std::abs));
    return (*std::min_element(vecCopy.begin() + 1, vecCopy.end()));

    // for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
    // {
    //     for (std::vector<int>::iterator it2 = _vec.begin(); it2 != _vec.end(); it2++)
    //     {
    //         if (it != it2)
    //         {
    //             if (*it > *it2)
    //             {
    //                 if ((*it - *it2) < smallest)
    //                     smallest = *it - *it2;
    //             }
    //         }
    //     } 
    // }
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