#include "Span.hpp"

int main(void)
{
    try
    {
        Span sp = Span(5);
        Span newSp(5);
        Span shitSpan(2);
        sp.addNumber(6);
        sp.addNumber(1);
        sp.addNumber(17);
        sp.addNumber(10);
        sp.addNumber(30);
        sp.displayContent();
        newSp = sp;
        std::cout << std::endl;
        newSp.displayContent();
        std::cout << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << newSp.shortestSpan() << std::endl;
        std::cout << newSp.longestSpan() << std::endl;

        Span newSpan(10);
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
        Span bigSpan(10000);
        for (int i = 0; i < 10000; i++)
            bigSpan.addNumber(rand() % 10000000000);
        std::cout << bigSpan.longestSpan() << std::endl;
        std::cout << bigSpan.shortestSpan() << std::endl;
        shitSpan.addNumber(6);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}