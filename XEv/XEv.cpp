#include <iostream>
#include "src/include/lexer.h"

int main()
{
	Lexer lex;

	std::cout << lex.Lex("10 * (5 * (4 - (6 / 3) ) / 5) + ( (13 * 8) - 24)");
	return 0;
}
