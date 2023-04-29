#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv) {
    try
    {
        readToBuffer(argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
}

void PmergeMe::readToBuffer(char **argv) {
    _buffer = argv[1];
}