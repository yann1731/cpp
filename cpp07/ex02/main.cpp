#include "Array.hpp"

int main(void)
{
    Array<int> array(10);
    Array<char> string(5);

    string[0] = 'H';
    string[1] = 'e';
    string[2] = 'l';
    string[3] = 'l';
    string[4] = 'o';

    Array<char> strCopy = string;
    Array<int> newArr;


    array[1] = 2;
    array[0] = 3;
    
    newArr = array;

    std::cout << array.size() << std::endl;
    std::cout << array[1] << " " << array[0] << std::endl;
    std::cout << newArr[1] << " " << newArr[0] << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << string[i];
        if (i == 4)
            std::cout << std::endl;
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << strCopy[i];
        if (i == 4)
            std::cout << std::endl;
    }

    try
    {
        array[11];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
};