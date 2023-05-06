#pragma once
# include <iostream>
# include <exception>
# include <fstream>
# include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::string;
using std::vector;
using std::size_t;

class PmergeMe {
private:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& rhs);
    string _buffer;
    vector<string> _args;
    vector<int> _sequence;
	int _orphan;
	bool _even;
    vector<std::pair<int, int> > _pairs;
    void readToBuffer(char **argv);
    void splitArgs();
    void printArgs();
    void sort();
    void splitIntoPairs();
    void displaySequence();
	void checkPair();
	void displayPairs();
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