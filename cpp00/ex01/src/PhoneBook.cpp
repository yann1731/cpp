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
            displayContact();
            break;
        case 2:
            displayContact();
            break;
        case 3:
            displayContact(lameBook.contactList[2]);
            break;
        case 4:
            displayContact(lameBook.contactList[3]);
            break;
        case 5:
            displayContact(lameBook.contactList[4]);
            break;
        case 6:
            displayContact(lameBook.contactList[5]);
            break;
        case 7:
            displayContact(lameBook.contactList[6]);
            break;
        case 8:
            displayContact(lameBook.contactList[7]);
            break;
        default:
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