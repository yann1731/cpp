#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
# include <map>
# include <algorithm>
# include <iostream>

using std::map;
using std::string;
using std::cout;
using std::endl;
class BitcoinExchange
{
private:
    BitcoinExchange();
    map<string, string> bitcoin;
public:
    BitcoinExchange(char **argv);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange& rhs);
    
};

#endif 