#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2) { //check for number of args
		//find relevant data if applicable
		try
		{
			BitcoinExchange btc(argv);
			btc.storeInput();
			btc.storeData();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return 1;
		}
	}
	else {
		std::cerr << "Program takes 2 arguments" << std::endl;
		return 1;
	}
	return 0;
}