#include "../include/PhoneBook.hpp"

int main(void)
{
    Contact newContact;

    std::cout << newContact.isEmpty() << std::endl;
    newContact.createNewContact();
    std::cout << newContact.getFirstName() << std::endl;
    return (0);
}