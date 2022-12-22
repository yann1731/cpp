#include "../include/Contact.hpp"

Contact::Contact()
{
    return ;
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
    _firstName = firstName;
    _lastName = lastName;
    _nickName = nickName;
    _phoneNumber = phoneNumber;
    _darkestSecret = darkestSecret;
}

Contact::~Contact()
{
    return ;
}

std::string Contact::getFirstName(void) const
{
    return (_firstName);
}

std::string Contact::getLastName(void) const
{
    return (_lastName);
}

std::string Contact::getNickName(void) const
{
    return (_nickName);
}

std::string Contact::getPhoneNumber(void) const
{
    return (_phoneNumber);
}

std::string Contact::getDarkestSecret(void) const
{
    return (_darkestSecret);
}

void Contact::setFirstName(std::string firstName)
{
    _firstName = firstName;
}

void Contact::setLasttName(std::string lastName)
{
    _lastName = lastName;
}

void Contact::setNickName(std::string nickName)
{
    _nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
    _phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
    _darkestSecret = darkestSecret;
}

void Contact::createNewContact(void)
{
    while (this->_firstName.empty())
    {
        std::cout << "Enter the first name of the new contact: ";
        std::cin >> this->_firstName;
    }
    while (this->_lastName.empty())
    {
        std::cout << "Enter the last name of the new contact: ";
        std::cin >> this->_lastName;
    }
    while (this->_nickName.empty())
    {
        std::cout << "Enter the nickname of the new contact: ";
        std::cin >> this->_nickName;
    }
    while (this->_phoneNumber.empty())
    {
        std::cout << "Enter the phone number of the new contact: ";
        std::cin >> this->_phoneNumber;
    }
    while (this->_darkestSecret.empty())
    {
        std::cout << "Enter the darkest secret of the new contact: ";
        std::cin >> this->_darkestSecret;
    }
}

bool Contact::isEmpty(void) const
{
    if (_firstName.empty())
        return (true);
    else
        return (false);
}