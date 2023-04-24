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
	try
	{
		findType();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void Convert::findType(void)
{
	checkForPseudoLiteral();
	if (pseudoLiteral == false) {
		if (checkChar()) {
			std::cout << "Entered type 1" << std::endl;
			type = 1;
		}
		else if (checkInt()) {
			std::cout << "Entered type 2" << std::endl;
			type = 2;
		}
		else if (checkFloat()) {
			std::cout << "Entered type 3" << std::endl;
			type = 3;
		}
		else if (checkDouble()) {
			std::cout << "Entered type 4" << std::endl;
			type = 4;
		}
	}
	if (type == 0 && pseudoLiteral == false)
		throw BadInput();
	else if (pseudoLiteral == true)
		handlePseudoLiteral();
	else
	{
		doConversion();
		doPrint();
	}
}

bool Convert::checkChar(void)
{
	const char *ptr = literal.c_str();
	if (literal.length() < 1 || literal.length() > 1)
		return false;
	if (isprint(ptr[0]) && !isdigit(ptr[0]))
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
	if (type == 1)
	{
		intType = static_cast<int>(charType);
		floatType = static_cast<float>(charType);
		doubleType = static_cast<double>(charType);
		if (!isprint(charType - 48))
			std::cout << "Not a printable character" << std::endl;
		else if ((charType - 48) < 255)
			std::cout << "Char: " << charType << std::endl;
		else
			std::cout << "Char: Invalid" << std::endl;
		std::cout << "Int: " << intType << std::endl;
		std::cout << "Float: " << floatType << ".0f" << std::endl;
		std::cout << "Double: " << doubleType << ".0" << std::endl;
	}
	if (type == 2)
	{
		charType = static_cast<char>(intType);
		floatType = static_cast<float>(intType);
		doubleType = static_cast<double>(intType);
		if (!isprint(charType - 48))
			std::cout << "Not a printable character" << std::endl;
		else if ((charType - 48) < 255)
			std::cout << "Char: " << charType << std::endl;
		else
			std::cout << "Char: Invalid" << std::endl;
		std::cout << "Int: " << intType << std::endl;
		std::cout << "Float: " << floatType << ".0f" << std::endl;
		std::cout << "Double: " << doubleType << ".0" << std::endl;
	}
	if (type == 3)
	{
		charType = static_cast<char>(floatType);
		intType = static_cast<int>(floatType);
		doubleType = static_cast<double>(floatType);
		if (!isprint(charType - 48))
			std::cout << "Not a printable character" << std::endl;
		else if ((charType - 48) < 255)
			std::cout << "Char: " << charType << std::endl;
		else
			std::cout << "Char: Invalid" << std::endl;
		std::cout << "Int: " << intType << std::endl;
		std::cout << "Float: " << floatType << "f" << std::endl;
		std::cout << "Double: " << doubleType << ".0" << std::endl;
	}
	if (type == 4)
	{
		charType = static_cast<char>(doubleType);
		intType = static_cast<int>(doubleType);
		floatType = static_cast<float>(doubleType);
		if (!isprint(charType - 48))
			std::cout << "Not a printable character" << std::endl;
		else if ((charType - 48) < 255)
			std::cout << "Char: " << charType << std::endl;
		else
			std::cout << "Char: Invalid" << std::endl;
		std::cout << "Int: " << intType << std::endl;
		std::cout << "Float: " << floatType << "f" << std::endl;
		std::cout << "Double: " << doubleType << std::endl;
	}
}

void Convert::checkForPseudoLiteral(void)
{
	if (literal == "nan" || literal == "nanf" || literal == "inf"\
	||	literal == "inff" || literal == "-inf" || literal == "-inff")
		pseudoLiteral = true;
}

void Convert::handlePseudoLiteral(void)
{
	std::cout << "Char: Impossible" << std::endl;
	std::cout << "Int: Impossible" << std::endl;
	if (literal == "nanf" || literal == "inff" || literal == "-inff")
	{
		std::cout << "Float: " << literal << std::endl;
		if (literal == "nanf")
			std::cout << "Double: " << "nan" << std::endl;
		else if (literal == "inff")
			std::cout << "Double: " << "inf" << std::endl;
		else
			std::cout << "Double: " << "-inf" << std::endl;
	}
	else
	{
		if (literal == "nan")
			std::cout << "Float: " << "nanf" << std::endl;
		else if (literal == "inf")
			std::cout << "Float: " << "inff" << std::endl;
		else
			std::cout << "Float: " << "-inff" << std::endl;
		std::cout << "Double: " << literal << std::endl;
	}
}

const char *Convert::BadInput::what() const throw()
{
	return "Invalid input. Need char, int, float or double";
}

const char *Convert::ThisIsVeryWrong::what() const throw()
{
	return "Something has gone wrong on a very fundamental level";
}