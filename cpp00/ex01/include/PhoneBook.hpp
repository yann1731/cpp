#include "Contact.hpp"

class PhoneBook
{
    public:
    PhoneBook();
    ~PhoneBook();
    void search(void);
    void add(void);
    void displayContactList(void);
    void addNewEntry(void);
    private:
    Contact contactList[8];
};