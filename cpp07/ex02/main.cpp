#include "Array.hpp"

int main(void)
{
	try {
		Array<int> array(10);
		Array<char> string(5);

		string[0] = 'H';
		string[1] = 'e';
		string[2] = 'l';
		string[3] = 'l';
		string[4] = 'o';

		Array<char> strCopy = string;

		cout << "printing string" << endl;
		for (size_t i = 0; i < string.size(); i++) {
			cout << string[i];
		}
		cout << endl;

		cout << "printing strCopy" << endl;
		for (size_t i = 0; i < string.size(); i++) {
			cout << strCopy[i];
		}
		cout << endl;

		string[0] = 'o';
		string[1] = 'k';
		string[2] = 'B';
		string[3] = 'y';
		string[4] = 'e';

		cout << "printing strCopy after modifying string" << endl;
		for (size_t i = 0; i < string.size(); i++) {
			cout << strCopy[i];
		}
		cout << endl;

		cout << "printing string after modif" << endl;
		for (size_t i = 0; i < string.size(); i++) {
			cout << string[i];
		}
		cout << endl;
	}
	catch (const std::exception& e) {
		cerr << e.what() << endl;
	}

    try
    {
		Array<int> array(10);
        array[11];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}