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
         {
             contactList[i].displayContactInfo(i);
         }
     }
}

void PhoneBook::search(void)
{
    int index;
    this->displayContactList();
    std::cout << "Enter the index" << std::endl;
    std::cin >> index;
    switch (index)
    {
        case 1:
            contactList[index - 1].displaySingleContact();
            break;
        case 2:
            contactList[index - 1].displaySingleContact();
            break;
        case 3:
            contactList[index - 1].displaySingleContact();
            break;
        case 4:
            contactList[index - 1].displaySingleContact();
            break;
        case 5:
            contactList[index - 1].displaySingleContact();
            break;
        case 6:
            contactList[index - 1].displaySingleContact();
            break;
        case 7:
            contactList[index - 1].displaySingleContact();
            break;
        case 8:
            contactList[index - 1].displaySingleContact();
            break;
        default:
            std::cout << "Bad index" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            break;
    }
}

void PhoneBook::addNewEntry(void)
{
    int index = _index % 8;
    contactList[index].createNewContact();
    _index++;
}