#include <iostream>
#include "lexer/Token.h"
#include "lexer/Lexer.h"
using namespace Lang;
int main(int argc, char** argv)
{
	Lexer lex("");
	lex.lexLine("{11 1#  +2=3 }  ");
	for (auto it = lex.getTokens().begin(); it < lex.getTokens().end(); it++)
	{
		std::cout << TokenTypeToString((*it).getType()) << ": " << (*it).getText() << "\n";
	}
	lex.debug();
	return 0;
}