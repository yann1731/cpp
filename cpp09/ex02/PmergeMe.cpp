#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv) {
    try
    {
        this->readToBuffer(argv);
        this->splitArgs();
		this->splitIntoPairs();
		this->displayPairs();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
}

PmergeMe::~PmergeMe() {

}

void PmergeMe::splitIntoPairs() {
    if (_sequence.size() % 2 == 0) {
        for (size_t i = 0; i < (_sequence.size()/2); i += 2) {
            _pairs.push_back(std::make_pair(_sequence[i], _sequence[i + 1]));
        }
		_even = true;
	}
	else {
		for (size_t i = 0; i < (_sequence.size()/2) - 1; i += 2) {
			_pairs.push_back(std::make_pair(_sequence[i], _sequence[i + 1]));
		}
		_orphan = _sequence.back();
		_even = false;
	}
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
                _sequence.push_back(tmpInt);
            else if (tmpInt == 0 && tmpString.size() == 1 && tmpString[0] == '0')
                _sequence.push_back(tmpInt);
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
                _sequence.push_back(tmpInt);
            else if (tmpString.size() == 1 && tmpString[0] == '0')
                _sequence.push_back(tmpInt);
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
	for (vector<int>::iterator it = _sequence.begin(); it != _sequence.end(); ++it) {
		cout << *it << " ";
	}
	if (!_even)
		cout << _orphan;
	cout << endl;
}

void PmergeMe::displayPairs() {
	for (size_t i = 0; i < _pairs.size(); i++) {
		cout << _pairs[i].first << " " << _pairs[i].second << endl;
	}
	if (!_even)
		cout << "Orphan: " << _orphan << endl;
}

void PmergeMe::printArgs() {
    for (size_t i = 0; i < _args.size(); i++) {
        cout << _args.at(i) << " ";
    }
    cout << endl;
}