#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0; 
}

// int main(void)
// {
//     Span newSpan(10);

//     srand(time(NULL));

//     for (int i = 0; i < 10; i++)
//     {
//         newSpan.addNumber(rand() % 100);
//     }
//     std::cout << newSpan.longestSpan() << std::endl;
//     std::cout << newSpan.shortestSpan() << std::endl;
//     return 0;
// }