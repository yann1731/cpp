#include "RPN.hpp"

int main(int argc, char** argv) {
    
    if (argc == 2) {
        RPN operation(argv);
        // operation.operate(); for later
    }
    else
        std::cerr << "Program needs 1 argument of the reverse polish notation form" << endl;

    return 0;
}