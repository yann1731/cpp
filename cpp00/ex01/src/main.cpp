#include "../include/PhoneBook.hpp"

int main(void)
{
    PhoneBook myPhoneBook;
	std::string input;
	while (1)
	{
		std::cin >> input;
		if (input.compare("ADD"))
			myPhoneBook.addNewEntry();
		else if (input.compare("SEARCH"))
			myPhoneBook.displayContactList();
		else if (input.compare("EXIT"))
			exit(0);
		else
			std::cin.clear();
	}
}