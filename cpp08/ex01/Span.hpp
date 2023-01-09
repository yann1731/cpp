#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
private:
    size_t _n;
    std::vector<int> _vec;
    Span();
public:
    Span(unsigned int n);
    Span(const Span &rhs);
    ~Span();
    Span &operator=(const Span &rhs);
    void addNumber(int n);
    int shortestSpan(void);
    int longestSpan(void);
    class VectorFull: public std::exception
    {
        const char *what() const throw()
        {
            return "Exception: Vector is full";
        }
    };
    class ContainerTooSmall: public std::exception
    {
        const char *what() const throw()
        {
            return "Exception: Container is too small";
        }
    };
};

#endif