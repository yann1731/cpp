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
	std::string bufferString;
	std::string newString;
	std::ifstream input(_fileName);
	std::ofstream stream(_newFileName);
	while (std::getline(input, bufferString, '\n'))
	{
		if (bufferString.find(_s1) != std::string::npos)
		{
			while (bufferString.find(_s1, 0) != std::string::npos)
			{
				size_t pos = bufferString.find(_s1);
				newString.append(bufferString.substr(0, pos));
				bufferString = bufferString.substr(pos + _s1.length(), std::string::npos);
				newString.append(_s2);
			}
			newString.append(bufferString);
			stream << newString << std::endl;
		}
		else
			stream << bufferString << std::endl;
	}
	input.close();
	stream.close();
}