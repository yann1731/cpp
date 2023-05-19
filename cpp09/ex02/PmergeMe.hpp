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
    PmergeMe(char **argv, int argc);

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
    vector<int> _unsortedSequence;
    vector<int> _sortedSequence;
    vector<int> _leftOver;
	int _orphan;
	bool _even;
    vector<std::pair<int, int> > _VPairs;
    deque<std::pair<int, int> > _DPairs;
    
    // pre-sort argument validation
    void readToBuffer(char **argv);
    void splitArgs();
    void printArgs();
    void displaySequence();
	void checkPair();

    // sorting
    template <typename T>
    void mergeInsertSort(T &container) {
        (void) container;
    }

    template <typename T>
    void displayPairs(const T &container) {
	    for (size_t i = 0; i < container.size(); i++) {
		    cout << "[" << container[i].first << ", " << container[i].second << "]";
	    }
        cout << endl;
	    if (!_even)
		    cout << "Orphan: " << _orphan << endl;
    }

    template <typename T>
    void splitIntoPairs(T &container) {
        if (_unsortedSequence.size() % 2 == 0) {
            for (size_t i = 0; i < (_unsortedSequence.size()); i += 2) {
                container.push_back(std::make_pair(_unsortedSequence[i], _unsortedSequence[i + 1]));
            }
		    _even = true;
	    }
	    else {
		    for (size_t i = 0; i < (_unsortedSequence.size()) - 1; i += 2) {
			    container.push_back(std::make_pair(_unsortedSequence[i], _unsortedSequence[i + 1]));
		    }
		    _orphan = _unsortedSequence.back();
		    _even = false;
	    }
    }

    template <typename T>
    void merge(T &container) {
        if (container.size() == 0)
            return;
        else {
            if (container.at(0).first >= container.at(0).second) {
            vector<int>::iterator it = std::lower_bound(_sortedSequence.begin(), _sortedSequence.end(), container.at(0).first);
            _sortedSequence.insert(it, container.at(0).first);
            _leftOver.push_back(container.at(0).second);
            }
            else {
                vector<int>::iterator it = std::lower_bound(_sortedSequence.begin(), _sortedSequence.end(), container.at(0).second);
                _sortedSequence.insert(it, container.at(0).second);
                _leftOver.push_back(container.at(0).first);
            }
            container.erase(container.begin());
            merge(container);
        }
    }
};