#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv, int argc) {
    try
    {
        benchmarkUtils.start();
        if (argc == 2) {
            this->readToBuffer(argv);
            this->splitArgs();
        }
        else {
            int tmpInt;
            for (int i = 1; i < argc; ++i) {
                tmpInt = atoi(argv[i]);
                if (tmpInt < 0) {
                    cerr << "Error" << endl;
                    exit(1);
                }
                else if (tmpInt > 0)
                    _unsortedSequence.push_back(tmpInt);
                else if (tmpInt == 0 && strlen(argv[i]) == 1 && argv[i][0] == '0') {
                    cout << "Entered else if checking for 0" << endl;
                    _unsortedSequence.push_back(tmpInt);
                }
                else {
                    cerr << "Error" << endl;
                    exit(1);
                }
            }
        }
        benchmarkUtils.stop();
        benchmarkUtils.setTimeDataManagement(benchmarkUtils.timeStamp());
        benchmarkUtils.start();
		this->splitIntoPairs(_VPairs);
        this->mergeInsertSort(_VPairs);
        benchmarkUtils.stop();
        benchmarkUtils.setTimeVector(benchmarkUtils.timeStamp());
        cout << "Before: ";
        for (size_t i = 0; i < _unsortedSequence.size(); ++i) {
            cout << _unsortedSequence[i] << " ";
            if (i == 5) {
                cout << "[...]" << endl;
                break ;
            }
        }
        if (_unsortedSequence.size() <= 5)
            cout << endl;
        cout << "After: ";
        for (size_t i = 0; i < _sortedSequence.size(); ++i) {
            cout << _sortedSequence[i] << " ";
            if (i == 5) {
                cout << "[...]" << endl;
                break ;
            }
        }
        if (_unsortedSequence.size() <= 5)
            cout << endl;
        _sortedSequence.clear();
        _leftOver.clear();
        benchmarkUtils.start();
        this->splitIntoPairs(_DPairs);
        this->mergeInsertSort(_DPairs);
        benchmarkUtils.stop();
        benchmarkUtils.setTimeDeque(benchmarkUtils.timeStamp());
        cout << "Time to process " << _unsortedSequence.size() << " elements in std::deque: " << (benchmarkUtils.getTimeDataManagement() + benchmarkUtils.getTimeDeque()) << " usecs" << endl;
        cout << "Time to process " << _unsortedSequence.size() << " elements in std::vector: " << (benchmarkUtils.getTimeDataManagement() + benchmarkUtils.getTimeVector()) << " usecs" << endl;
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
            else {
                cerr << "Error" << endl;
                exit(1);
            }
			start = string::npos;
			stop = string::npos;
		}
	}
    if (start != string::npos) {
        tmpString = _buffer.substr(start, stop - start);
            tmpInt = atoi(tmpString.c_str());
            if (tmpInt > 0)
                _unsortedSequence.push_back(tmpInt);
            else if (tmpString.size() == 1 && tmpString[0] == '0')
                _unsortedSequence.push_back(tmpInt);
            else {
                cerr << "Error" << endl;
                exit(1);
            }
    }
}

void PmergeMe::insert() {
        while (_leftOver.size() != 0) {
            vector<int>::iterator it = std::lower_bound(_sortedSequence.begin(), _sortedSequence.end(), _leftOver.at(0));
            _sortedSequence.insert(it, _leftOver.at(0));
            _leftOver.erase(_leftOver.begin());
        }
        if (_even == false) {
            vector<int>::iterator it = std::lower_bound(_sortedSequence.begin(), _sortedSequence.end(), _orphan);
            _sortedSequence.insert(it, _orphan);
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