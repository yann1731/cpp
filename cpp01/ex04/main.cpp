#include "ReplaceString.hpp"

int main(int argc, char *argv[])
{
	if (argc != 4)
		std::cout << "Needs 3 arguments" << std::endl;
	else
	{
		ReplaceString repl(argv[1], argv[2], argv[3]);
		repl.replace();
	}
	return (0);
}