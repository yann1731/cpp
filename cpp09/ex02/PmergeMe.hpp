#pragma once
# include <iostream>
# include <exception>


using std::cerr;
using std::cout;
using std::endl;
using std::exception;

class PmergeMe {
private:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& rhs);
public:
    PmergeMe(char **argv);
    ~PmergeMe();
    class InvalidNumber: public exception {
        const char* what() const throw();
    };
};