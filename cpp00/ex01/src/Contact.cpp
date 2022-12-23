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

void Contact::setLastName(std::string lastName)
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
    std::cin.clear();
    while (this->_firstName.empty())
    {
        std::cout << "Enter your first name" << std::endl;
        std::getline(std::cin, this->_firstName);
        std::cin.clear();
    }
    while (this->_lastName.empty())
    {
        std::cout << "Enter your last name" << std::endl;
        std::getline(std::cin, this->_lastName);
        std::cin.clear();
    }
    while (this->_nickName.empty())
    {
        std::cout << "Enter your nickname" << std::endl;
        std::getline(std::cin, this->_nickName);
        std::cin.clear();
    }
    while (this->_phoneNumber.empty())
	{
    	std::cout << "Enter your phone number" << std::endl;
        std::getline(std::cin, this->_phoneNumber);
    	std::cin.clear();
	}
    while (this->_darkestSecret.empty())
	{
    	std::cout << "Enter your darkest secret" << std::endl;
		std::getline(std::cin, this->_darkestSecret);
    	std::cin.clear();
	}
}

void Contact::displayContactInfo(int index)
{
    std::cout << std::right << std::setw(10) << index + 1 << "|";
    if (this->_firstName.length() > 9)
        std::cout << std::right << std::setw(10) << this->_firstName.substr(0, 9) << ".|";
    else
        std::cout << std::right << std::setw(10) << this->_firstName << "|";
    if (this->_lastName.length() > 9)
        std::cout << std::right << std::setw(10) << this->_lastName.substr(0, 9) << ".|";
    else
        std::cout << std::right << std::setw(10) << this->_lastName << "|";
    if (this->_nickName.length() > 9)
        std::cout << std::right << std::setw(10) << this->_nickName.substr(0, 9) << "|" << std::endl;
    else
        std::cout << std::right << std::setw(10) << this->_nickName << std::endl;
}

void Contact::displaySingleContact(void)
{
    std::cout << this->_firstName << std::endl;
    std::cout << this->_lastName << std::endl;
    std::cout << this->_nickName << std::endl;
    std::cout << this->_phoneNumber << std::endl;
    std::cout << this->_darkestSecret << std::endl;
}

bool Contact::isEmpty(void) const
{
    if (_firstName.empty())
        return (true);
    else
        return (false);
}