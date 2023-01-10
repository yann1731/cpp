#include <stack>
#include <algorithm>
#include <iostream>

template <typename T>
class MutantStack: public std::stack<T>
{
public:
    MutantStack()
    {
    }

    MutantStack(const MutantStack<T> &rhs)
    {
        *this = rhs;
    }

    ~MutantStack()
    {
    }

    MutantStack &operator=(const MutantStack &rhs)
    {
        *this = rhs;
        return *this;
    }
    
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin(void)
    {
        return this->c.begin();
    }
    iterator end(void)
    {
        return this->c.end();
    }
};