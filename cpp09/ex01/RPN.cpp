#include "RPN.hpp"

RPN::RPN(char **argv) {
    _buffer = argv[1];
    this->check();
}

RPN::~RPN() {

}

void RPN::check(void) {
    string tmp;
    string set = "0123456789+-/*";
    std::size_t start = string::npos;
    std::size_t stop = string::npos;
    for (string::iterator it = _buffer.begin(); it < _buffer.end(); it++) {
        if (!isspace(*it) && start == string::npos)
            start = it - _buffer.begin();
        if ((isspace(*it) || it + 1 == _buffer.end()) && start != string::npos) {
            if (it + 1 == _buffer.end())
                stop = it + 1 - _buffer.begin();
            else
                stop = it - _buffer.begin();
        }
        if (start != string::npos && stop != string::npos) {
            tmp = _buffer.substr(start, stop - start);
            cout << "tmp: " << tmp << endl;
            if (tmp.size() != 1)
                throw NotAValidDigit();
            if (set.find(tmp[0]) == string::npos)
                throw InvalidCharacter();
            start = string::npos;
            stop = string::npos;
        }
    }
}

void RPN::split(void) {

}

const char* RPN::NotAValidDigit::what() const throw() {
    return "Error: invalid digit or operand";
}

const char* RPN::NotAValidOperand::what() const throw() {
    return "Error: invalid operand";
}

const char* RPN::InvalidOperation::what() const throw() {
    return "Error: invalid operation";
}

const char* RPN::InvalidCharacter::what() const throw() {
    return "Error: invalid character";
}