#include "Convert.hpp"

Convert::Convert()
{
}

Convert::Convert(const std::string &literal): literal(literal), charType(0), intType(0), floatType(0), doubleType(0), type(0), pseudoLiteral(false)
{
}

Convert::Convert(const Convert &src): literal(src.literal), charType(src.charType), intType(src.intType), floatType(src.floatType), doubleType(src.doubleType), type(src.type), pseudoLiteral(src.pseudoLiteral)
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
	findType();
	switch (type)
	{
		case (1):
			std::cout << "Input is char" << std::endl;
			break;
		case (2):
			std::cout << "Input is int" << std::endl;
			break;
		case (3):
			std::cout << "Input is float" << std::endl;
			break;
		case (4): 
			std::cout << "Input is double" << std::endl;
			break;
		default:
			std::cerr << "Input is invalid" << std::endl;
			break;
	}

}

void Convert::findType(void)
{
	checkForPseudoLiteral();
	if (type == 0 && pseudoLiteral == false)
	{
		throw BadInput();
	}
	else if (pseudoLiteral == true)
	{
		handlePseudoLiteral();
	}
	else
		doConversion()
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

void Convert::doConversion(void)
{
	switch(type)
	{
		case(1):
			charType = literal[0];
			break;
		case(2):
			intType = std::stoi(literal.c_str());
			break;
		case(3):
			floatType = std::stof(literal.c_str());
			break;
		case(4):
			doubleType = std::stod(literal.c_str());
			break;
		default:
			throw ThisIsVeryWrong();
	}
}

void Convert::doPrint(void)
{

}

void Convert::checkForPseudoLiteral(void)
{

}

void Convert::handlePseudoLiteral(void)
{

}

const char *Convert::BadInput::what() const throw()
{
	return "Invalid input. Need char, int, float or double";
}

const char *Convert::ThisIsVeryWrong::what() const throw()
{
	return "Something has gone wrong on a very fundamental level";
}