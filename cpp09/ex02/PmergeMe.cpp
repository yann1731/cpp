#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv, int argc) {
    try
    {
        if (argc == 2) {
            this->readToBuffer(argv);
            this->splitArgs();
        }
        else {
            int tmpInt;
            for (int i = 1; i < argc; ++i) {
                tmpInt = atoi(argv[i]);
            if (tmpInt > 0)
                _unsortedSequence.push_back(tmpInt);
            else if (tmpInt == 0 && strlen(argv[i]) == 1 && argv[i][0] == '0')
                _unsortedSequence.push_back(tmpInt);
            }
        }
		this->splitIntoPairs(_DPairs);
		this->displayPairs(_DPairs);
        this->mergeInsertSort(_DPairs);
        this->mergeInsertSort(_VPairs);
        this->merge(_VPairs);
        cout << "Sorted sequence: ";
        for (size_t i = 0; i < _sortedSequence.size(); ++i) {
            cout << _sortedSequence.at(i) << " ";
        }
        cout << std::endl;
        cout << "leftOver: ";
        for (size_t i = 0; i < _leftOver.size(); ++i) {
            cout << _leftOver.at(i) << " ";
        }
        cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
}

PmergeMe::~PmergeMe() {

}

void PmergeMe::checkPair() {

}

void PmergeMe::readToBuffer(char **argv) {
    _buffer = argv[1];
}

void PmergeMe::splitArgs() {
	size_t start = string::npos;
	size_t stop = string::npos;
    int tmpInt;
    string tmpString;
	for (string::iterator it = _buffer.begin(); it != _buffer.end(); it++) {
		if (!isblank(*it) && start == string::npos)
			start = it - _buffer.begin();
		if ((*it == ' ' || *it == '	') && start != string::npos)
			    stop = it - _buffer.begin();
		if (start != string::npos && stop != string::npos) {
            tmpString = _buffer.substr(start, stop - start);
            tmpInt = atoi(tmpString.c_str());
            if (tmpInt > 0)
                _unsortedSequence.push_back(tmpInt);
            else if (tmpInt == 0 && tmpString.size() == 1 && tmpString[0] == '0')
                _unsortedSequence.push_back(tmpInt);
            else
                tmpString.clear();
			start = string::npos;
			stop = string::npos;
		}
	}
    if (start != string::npos) {
        tmpString = _buffer.substr(start, stop - start);
            tmpInt = atoi(tmpString.c_str());
            if (tmpInt != 0)
                _unsortedSequence.push_back(tmpInt);
            else if (tmpString.size() == 1 && tmpString[0] == '0')
                _unsortedSequence.push_back(tmpInt);
            else
                tmpString.clear();
    }
}

// $> ./PmergeMe 3 5 9 7 4
// Before: 3 5 9 7 4
// After: 3 4 5 7 9
// Time to process a range of 5 elements with std::[..] : 0.00031 us
// Time to process a range of 5 elements with std::[..] : 0.00014 us
// $> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
// Before: 141 79 526 321 [...]
// After: 79 141 321 526 [...]
// Time to process a range of 3000 elements with std::[..] : 62.14389 us
// Time to process a range of 3000 elements with std::[..] : 69.27212 us


void PmergeMe::displaySequence() {
	for (vector<int>::iterator it = _unsortedSequence.begin(); it != _unsortedSequence.end(); ++it) {
		cout << *it << " ";
	}
	if (!_even)
		cout << _orphan;
	cout << endl;
}

void PmergeMe::printArgs() {
    for (size_t i = 0; i < _args.size(); i++) {
        cout << _args.at(i) << " ";
    }
    cout << endl;
}