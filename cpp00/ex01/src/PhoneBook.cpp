#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    _index = 0;
    return ;
}

PhoneBook::~PhoneBook()
{
    return ;
}

void PhoneBook::displayContactList(void)
{
     for (int i = 0; i < 8; i++)
     {
         if (!contactList[i].isEmpty())
			 contactList[i].displayContactInfo();
     }
}

void PhoneBook::addNewEntry(void)
{
    int index = _index % 8;
    contactList[index].createNewContact();
    _index++;
}