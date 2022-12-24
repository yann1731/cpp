#ifndef REPLACE_HPP
#define REPLACE_HPP
#include <iostream>

class ReplaceString
{
private:
	std::string _fileName;
	std::string _s1;
	std::string _s2;
public:
	ReplaceString(std::string fileName, std::string s1, std::string s2);
	~ReplaceString();
	void createNewFile(void);
	void replace(void);
};

#endif