#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc == 2) {
        PmergeMe pMerge(argv);
    }
    else {
        std::cerr << "Program needs 1 argument only" << std::endl;
        return 1;
    }
    
    return 0;
}