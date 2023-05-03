#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv) {
    try
    {
        this->readToBuffer(argv);
        this->splitArgs();
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
}

PmergeMe::~PmergeMe(void) {

}

void PmergeMe::readToBuffer(char **argv) {
    _buffer = argv[1];
    
}

void PmergeMe::splitArgs(void) {
	std::size_t start = string::npos;
	std::size_t stop = string::npos;
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
            else if (tmpInt == 0 && tmpString.size() == 1 && tmpString[0] == '0')
                _sequence.push_back(tmpInt);
            else
                tmpString.clear();
    }
}

void PmergeMe::printArgs(void) {
    for (std::size_t i = 0; i < _args.size(); i++) {
        cout << _args.at(i) << " ";
    }
    cout << endl;
}