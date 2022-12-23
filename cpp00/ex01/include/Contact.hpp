#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>
#include <iomanip>


// The contact fields are: first name, last name, nickname, phone number, and
// darkest secret. A saved contact can’t have empty fields.
class Contact
{
    public:
    Contact ();
    Contact (std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
    ~Contact ();
    std::string getFirstName(void) const;
    std::string getLastName(void) const;
    std::string getNickName(void) const;
    std::string getPhoneNumber(void) const;
    std::string getDarkestSecret(void) const;
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setNickName(std::string nickName);
    void setPhoneNumber(std::string phoneNumber);
    void setDarkestSecret(std::string darkestSecret);
    void createNewContact(void);
    void displayContactInfo(int index);
    void displaySingleContact(void);
    void clearContact(void);
    bool isEmpty(void) const;
    private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkestSecret;
};

#endif