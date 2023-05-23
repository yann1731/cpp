#include "RPN.hpp"

RPN::RPN(char **argv) {
    _buffer = argv[1];
    try
    {
        this->check();
        this->split();
        this->doMath();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

RPN::~RPN() {

}

void RPN::check(void) {
    int trigger = 0;
    string set = "0123456789+-/*";
    for (string::iterator it = _buffer.begin(); it < _buffer.end(); it++) {
        if (isspace(*it))
            trigger = 0;
        if (!isspace(*it)) {
            if (trigger == 1)
                throw NotAValidDigit();
            if (set.find(*it) == string::npos)
                throw InvalidCharacter();
            trigger = 1;
        }
    }
}

void RPN::split(void) {
    for (string::reverse_iterator it = _buffer.rbegin(); it < _buffer.rend(); it++) {
        if (!isspace(*it))
            _c.push(*it);
    }
}

void RPN::doMath(void) {
    string operators = "+-/*";
    stack<int> emptyStack;
    int val1;
    int val2;
    int result;
    while (_c.size()) {
        if (operators.find(_c.top()) == string::npos) {
            emptyStack.push(_c.top() - 48);
            _c.pop();
        }
        if (_c.size() == 0)
            throw InvalidOperation();
        if (operators.find(_c.top()) != string::npos) {
            if (emptyStack.size() < 2)
                throw InvalidOperation();
            val1 = emptyStack.top();
            emptyStack.pop();
            val2 = emptyStack.top();
            emptyStack.pop();
            switch(_c.top()) {
                case('+'):
                    result = val2 + val1;
                    _c.pop();
                    emptyStack.push(result);
                    break;
                case('-'):
                    result = val2 - val1;
                    _c.pop();
                    emptyStack.push(result);
                    break;
                case('/'):
                    result = val2 / val1;
                    _c.pop();
                    emptyStack.push(result);
                    break;
                case('*'):
                    result = val2 * val1;
                    _c.pop();
                    emptyStack.push(result);
                    break;
            }
        }
    }
    result = emptyStack.top();
    if (emptyStack.size() > 1)
        throw InvalidOperation();
    cout << result << endl;
}

void RPN::printStack(void) {
    size_t count = _c.size();
    for (size_t i = 0; i < count; i++) {
        cout << _c.top() << endl;
        _c.pop();
    }
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