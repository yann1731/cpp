#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n): _n(n) {}

Span::Span(const Span &rhs)
{
    _n = rhs._n;
    std::copy(rhs.vec1.begin(), rhs.vec1.end(), this->vec1.begin());
}

Span::~Span() {}

Span &Span::operator=(const Span &rhs)
{
    _n = rhs._n;
    std::copy(rhs.vec1.begin(), rhs.vec1.end(), this->vec1.begin());
    return *this;
}

void Span::addNumber(int n)
{
    if (vec1.size() >= _n)
        throw VectorFull();
    else
        vec1.push_back(n);
}

int Span::shortestSpan(void)
{
    if (vec1.size() <= 1)
        throw ContainerTooSmall();
    unsigned int smallest;

    for (std::vector<int>::iterator it = vec1.begin(); it != vec1.end(); it++)
    {
        for (std::vector<int>::iterator it2 = vec1.begin(); it2 != vec1.end(); it2++)
        {
            if (it != it2)
            {
                if (static_cast<unsigned int>(*it - *it2) < smallest)
                    smallest = *it - *it2;
            }
        } 
    }
    return smallest;
}

int Span::longestSpan(void)
{
    if (vec1.size() <= 1)
        throw ContainerTooSmall();
    int longest;

    longest = *(std::max_element(vec1.begin(), vec1.end())) - *(std::min_element(vec1.begin(), vec1.end()));
    return longest;
}