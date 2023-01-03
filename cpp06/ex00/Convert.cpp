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

Convert::Convert(const std::string &literal): literal(literal)
{
}

Convert::Convert(const Convert &src): literal(src.literal)
{
}

Convert::~Convert()
{
}

Convert &Convert::operator=(const Convert &src)
{
	this->literal = src.literal;
	return *this;
}

void Convert::convertLiteral(void)
{
	std::string litCopy;
	int toInt;
	//float toFloat;
	//double toDouble;
	litCopy = literal;

	try
	{
		toInt = std::stoi(litCopy, nullptr, 10);
		std::cout << toInt << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

void Convert::findType(void)
{
	
}