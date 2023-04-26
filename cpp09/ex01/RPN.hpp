#pragma once
# include <iostream>
# include <stack>
# include <exception>

using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::exception;

class RPN {
private:
    stack<char> _c;
    string _buffer;
    RPN(const RPN& other);
    RPN& operator=(const RPN& rhs);
    RPN();
    void check(void);
    void split(void);
public:
    RPN(char **argv);
    ~RPN();

    class NotAValidDigit: public exception {
        const char* what() const throw();
    };
    class NotAValidOperand: public exception {
        const char* what() const throw();
    };
    class InvalidOperation: public exception {
        const char* what() const throw();
    };
    class InvalidCharacter: public exception {
        const char* what() const throw();
    };
};