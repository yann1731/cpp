#include "Contact.hpp"

class PhoneBook
{
    public:
    PhoneBook();
    ~PhoneBook();
    void displayContactList(void);
    void addNewEntry(void);
    private:
    Contact contactList[8];
    int _index;
};