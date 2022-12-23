#include "../include/PhoneBook.hpp"

int main(void)
{
    PhoneBook myPhoneBook;
    
    std::string input;
	while (1)
	{
        std::cout << "Please enter a command: ";
		std::cin >> input;
		if (input.compare("ADD") == 0)
        {
            std::cin.clear();
            std::cin.ignore(50000, '\n');
			myPhoneBook.addNewEntry();
        }
		else if (input.compare("SEARCH") == 0)
			myPhoneBook.search();
		else if (input.compare("EXIT") == 0)
			exit(0);
		else
			std::cout << "Not a valid command. Enter either ADD, SEARCH, EXIT" << std::endl;
	}
}