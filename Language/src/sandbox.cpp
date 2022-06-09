#include <iostream>
#include "lexer/Token.h"
#include "lexer/Lexer.h"
#include "parser/Parser.h"
#include <deque>
using namespace Lang;
int main(int argc, char** argv)
{
	std::deque<int> ints{ 1,2,3 };
	ints.pop_back();
	Lexer lex("");
	lex.lexLine("{1}");
	for (auto it = lex.getTokens().begin(); it < lex.getTokens().end(); it++)
	{
		//std::cout << TokenTypeToString((*it).getType()) << ": " << (*it).getText() << "\n";
	}
	lex.debug();
	Parser parser(lex.getTokens());
	parser.parse();
	return 0;
}