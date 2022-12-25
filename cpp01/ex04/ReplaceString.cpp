#include "ReplaceString.hpp"

ReplaceString::ReplaceString(std::string fileName, std::string s1, std::string s2): _fileName(fileName), _s1(s1), _s2(s2)
{
	_newFileName = fileName;
	return ;
}

ReplaceString::~ReplaceString()
{
	return ;
}

void ReplaceString::replace(void)
{
	_newFileName.append(".replace");
}