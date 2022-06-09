#include "Parser.h"
#include "nodes/Node.h"
#include "nodes/Root.h"
#include "nodes/Bracket.h"
#include "nodes/Number.h"
#include "nodes/Plus.h"
#include <iostream>

namespace Lang
{
	void Parser::parse()
	{
		root = new Root();
		eat(TokenType::OpenBracket);

		root->codeBlock = new Bracket();
		if (mTokens.front().getType() == TokenType::Number)
		{
			Number* number = new Number();
			number->number = std::stoi(eat(TokenType::Number));
			root->codeBlock->expression = number;
		}

		if (mTokens.front().getType() == TokenType::Plus)
		{
			eat(TokenType::Plus);
			Plus* plus = new Plus();
			plus->left = (Number*)root->codeBlock->expression;
			Number* right = new Number();
			string s = eat(TokenType::Number);

			right->number = std::stoi(s);
			plus->right = right;
			root->codeBlock->expression = plus;

		}
		eat(TokenType::CloseBracket);
	}

	string Parser::eat(TokenType expected)
	{
		if (mTokens.front().getType() == expected)
		{
			string s = mTokens.front().getText();
			mTokens.pop_front();
			return s;
		}
		else
		{
			std::cout << "expected: " << TokenTypeToString(expected) << " recieved: " << TokenTypeToString(mTokens.front().getType())<<"\n";
			return "ERROR";
		}
	}


}