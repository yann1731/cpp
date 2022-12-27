#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		Harl newAnnoyingAsshole;
		std::string level = argv[1];
		newAnnoyingAsshole.complain(level);
	}
	else
		std::cout << "OH MY GOD ENTER A LEVEL. THIS IS UNACCEPTABLE I WANT TO SPEAK TO YOUR MANAGER" << std::endl;
	return (0);
}