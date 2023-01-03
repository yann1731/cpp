#include "Convert.hpp"

// class Convert
// {
// private:
//     std::string literal;
// public:
//     Convert();
//     Convert(const std::string &literal);
//     Convert(const Convert &src);
//     Convert();
//     Convert &operator=(const Convert &src);
// };

Convert::Convert()
{
}

Convert::Convert(const std::string &literal): literal(literal), charType(0), intType(0), floatType(0), doubleType(0), type(0)
{
}

Convert::Convert(const Convert &src): literal(src.literal), charType(0), intType(0), floatType(0), doubleType(0), type(0)
{
}

Convert::~Convert()
{
}

Convert &Convert::operator=(const Convert &src)
{
	this->literal = src.literal;
	this->charType = src.charType;
	this->intType = src.intType;
	this->floatType = src.floatType;
	this->doubleType = src.doubleType;
	return *this;
}

void Convert::convertLiteral(void)
{
	
}

void Convert::findType(void)
{
	if (checkChar() == true)
		type = 1;
	else if (checkInt() == true)
		type = 2;
	else if (checkFloat() == true)
		type = 3;
	else if(checkDouble() == true)
		type = 4;
	else
		type = 0;
	std::cout << type << std::endl;
}

bool Convert::checkChar(void)
{
	const char *ptr = literal.c_str();
	if (literal.length() < 1 || literal.length() > 1)
		return false;
	if (isprint(ptr[0]))
		return true;
	return false;
}

bool Convert::checkInt(void)
{
	const char *ptr = literal.c_str();
	bool minus = false;
	if (ptr[0] == '-')
	{
		if (!isdigit(ptr[1]))
			return false;
		minus = true;
	}
	for (int i = 0; ptr[i]; i++)
	{
		if (ptr[i] == '-' && minus == true)
		{
			i++;
			minus = false;
		}
		if (!isdigit(ptr[i]))
			return false;
	}
	return true;
}

bool Convert::checkFloat(void)
{
	const char *ptr = literal.c_str();
	int dot = 0;
	bool trigger = false;
	bool minus = false;
	if (literal.length() <= 1)
		return false;
	if (ptr[0] == '-')
	{
		if (!isdigit(ptr[1]) && ptr[1] != '.')
			return false;
		minus = true;
	}
	if (ptr[0] == '.' && ptr[1] == 'f')
		return false;
	if (ptr[0] == '-' && !isdigit(ptr[1]))
		return (false);
	for (int i = 0; ptr[i]; i++)
	{
		if (ptr[i] == '-' && minus == true)
		{
			i++;
			minus = false;
		}
		if (ptr[i] == '.')
			dot++;
		if ((!isdigit(ptr[i]) && ptr[i] != '.') && trigger == false)
			return false;
		if ((isdigit(ptr[i]) || ptr[i] == '.') && trigger == false)
			trigger = true;
		if ((!isdigit(ptr[i]) && ptr[i] != '.' && ptr[i] != 'f') && trigger == true)
			return false;
		if (ptr[i] == 'f' && trigger == true)
		{
			if (ptr[i + 1] != '\0')
				return false;
			else 
			{
				if (dot == 1)
					return true;
			}
		}
	}
	return false;
}

bool Convert::checkDouble(void)
{
	const char *ptr = literal.c_str();
	bool status = false;
	int dot = 0;
	bool minus = false;
	if (literal.length() <= 1)
		return false;
	if (ptr[0] == '-')
	{
		if (!isdigit(ptr[1]) && ptr[1] != '.')
			return false;
		minus = true;
	}
	for (int i = 0; ptr[i]; i++)
	{
		if (ptr[i] == '-' && minus == true)
		{
			i++;
			minus = false;
		}
		if (ptr[i] == '.')
			dot++;
		if (dot > 1)
			return false;
		if (isdigit(ptr[i]) || ptr[i] == '.')
			status = true;
		if (!isdigit(ptr[i]) && ptr[i] != '.')
			return false;
	}
	return status;
}