#include "Convert.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Need to enter 1 argument" << std::endl;
    }
    else
    {
        (void) argv;
        char a = 'A';
        std::cout << (int) a << std::endl;
         std::cout << (float) a << std::endl;
          std::cout << (double) a << std::endl;
    }
}