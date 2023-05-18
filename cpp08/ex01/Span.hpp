#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
public:
    Span(unsigned int n);
    Span(const Span &rhs);
    ~Span();
    Span &operator=(const Span &rhs);
    void addNumber(int n);
    std::vector<int>::iterator &addNnumber(std::vector<int>::iterator &begin, std::vector<int>::iterator &end, std::vector<int>::iterator &it);
    int shortestSpan(void);
    int longestSpan(void);
    void displayContent(void) const;
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
private:
    std::vector<int> _vec;
    unsigned int _n;
    Span();
};

#endif