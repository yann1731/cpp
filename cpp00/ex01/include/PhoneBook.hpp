#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook
{
    public:
    PhoneBook();
    ~PhoneBook();
    void displayContactList(void);
    void addNewEntry(void);
    void search(void);
    private:
    Contact contactList[8];
    int _index;
};

#endif