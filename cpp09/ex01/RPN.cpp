#include "RPN.hpp"

RPN::RPN(char **argv) {
    _buffer = argv[1];
    cout << _buffer << endl;
}

RPN::~RPN() {

}

const char* RPN::NotAValidDigit::what() const throw() {
    return "Error: invalid digit";
}

const char* RPN::NotAValidOperand::what() const throw() {
    return "Error: invalid operand";
}

const char* RPN::InvalidOperation::what() const throw() {
    return "Error: invalid operation";
}