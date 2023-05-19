#pragma once
# include <iostream>
# include <exception>
# include <fstream>
# include <vector>
# include <deque>

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::string;
using std::vector;
using std::size_t;
using std::deque;

class PmergeMe {
public:
    PmergeMe(char **argv);

    ~PmergeMe();
    class InvalidNumber: public exception {
        const char* what() const throw();
    };
    class OpenFail: public exception {
        const char* what() const throw();
    };

private:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& rhs);
    string _buffer;
    vector<string> _args;
    vector<int> _sequence;
	int _orphan;
	bool _even;
    vector<std::pair<int, int> > _VPairs;
    deque<std::pair<int, int> > _DPairs;
    
    void readToBuffer(char **argv);
    void splitArgs();
    void printArgs();
    void sort();
    void splitIntoPairs();
    void displaySequence();
	void checkPair();
	void displayPairs();
};