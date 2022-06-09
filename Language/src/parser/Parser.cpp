#include "Parser.h"
#include "nodes/Node.h"
#include "nodes/Root.h"
#include "nodes/Bracket.h"
#include "nodes/Number.h"
#include <iostream>

namespace Lang
{
	void Parser::parse()
	{
		Root* root = new Root();
		eat(TokenType::OpenBracket);
		root->codeBlock = new Bracket();
		if (mTokens.front().getType() == TokenType::Number)
		{
			Number* number = new Number();
			number->number = std::stoi(eat(TokenType::Number));
			root->codeBlock->expression = number;
		}
		eat(TokenType::CloseBracket);
	}

	string Parser::eat(TokenType expected)
	{
		if (mTokens.front().getType() == expected)
		{
			std::cout << TokenTypeToString(expected);
			string s = mTokens.front().getText();
			mTokens.pop_front();
			return s;
		}
		else
		{
			std::cout << "ERROR";
			return "ERROR";
		}
	}


}