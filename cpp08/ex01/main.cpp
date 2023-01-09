#include "Span.hpp"

int main(void)
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        Span newSpan(10);
        Span shitSpan(2);

        shitSpan.addNumber(2);
        shitSpan.addNumber(4);
    
        srand(time(NULL));

        for (int i = 0; i < 10; i++)
        {
            newSpan.addNumber(rand() % 100);
        }
        std::cout << newSpan.longestSpan() << std::endl;
        std::cout << newSpan.shortestSpan() << std::endl;
        std::cout << shitSpan.longestSpan() << std::endl;
        shitSpan.addNumber(6);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}