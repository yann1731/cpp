#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void)
{
    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(17);
    std::cout << "value of last value in mstack: " << mstack.top() << std::endl;
	cout << "Size of mstack before pop_back: " << mstack.size() << endl;
    mstack.pop();
    std::cout << "size of mstack after pop_back: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(100);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
	cout << "printing content of mstack using iterators" << endl;
    while (it != ite)
    {
    	std::cout << *it << std::endl;
    	++it;
    }
    return 0;    
}