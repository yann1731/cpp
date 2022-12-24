#include "ReplaceString.hpp"

// class ReplaceString
// {
// private:
// 	std::string _fileName;
// 	std::string _s1;
// 	std::string _s2;
// public:
// 	ReplaceString();
// 	~ReplaceString();
// 	void replace(void);
// };

ReplaceString::ReplaceString(std::string fileName, std::string s1, std::string s2): _fileName(fileName), _s1(s1), _s2(s2)
{
	return ;
}

ReplaceString::~ReplaceString()
{
	return ;
}

std::string	changeFileName(char *fileName)
{
	std::string newFile;

	newFile = fileName;
	newFile.append(".replace");
	return (newFile);
}

void ReplaceString::replace(void)
{
	_fileName.append(".replace");
}