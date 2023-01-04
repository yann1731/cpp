#include "Convert.hpp"

//flow convertLiteral -> findType -> checkForPseudoLiteral  |-> doConversion -> doPrint
//                                                          |-> handlepseudoliteral -> print if input is a valid pseudoliteral
//                                                          |-> if not a pseudoliteral and wrong input throw error
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Need to enter 1 argument" << std::endl;
    }
    else
    {
        Convert convert(argv[1]);
        convert.convertLiteral();
    }
}