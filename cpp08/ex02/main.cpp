#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void)
{
    std::list<int> mstack;
    mstack.push_back(10);
    mstack.push_back(17);
    std::cout << "value of last value in mstack: " << mstack.back() << std::endl;
	cout << "Size of mstack before pop_back: " << mstack.size() << endl;
    mstack.pop_back();
    std::cout << "size of mstack after pop_back: " << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    //[...]
    mstack.push_back(100);
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
	cout << "printing content of mstack using iterators" << endl;
    while (it != ite)
    {
    	std::cout << *it << std::endl;
    	++it;
    }
    return 0;    
}

// int main(void)
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//     std::cout << *it << std::endl;
//     ++it;
//     }
//     std::stack<int> s(mstack);
//     return 0;    

//     return 0;
// }