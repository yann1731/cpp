#include <stack>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

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

    MutantStack &operator=(const MutantStack<T> &rhs)
    {
        this->c = rhs.c;
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