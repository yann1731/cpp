#pragma once
# include <iostream>
# include <exception>
# include <fstream>


using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::string;

class PmergeMe {
private:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& rhs);
    string _buffer;
    void readToBuffer(char **argv);
public:
    PmergeMe(char **argv);

    ~PmergeMe();
    class InvalidNumber: public exception {
        const char* what() const throw();
    };
    class OpenFail: public exception {
        const char* what() const throw();
    };
};