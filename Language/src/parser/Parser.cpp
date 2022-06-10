#include "Parser.h"
#include <iostream>
#include "nodes/Expression.h"
#include "nodes/Number.h"
#include "nodes/Plus.h"

namespace Lang
{
	void Parser::parse()
	{
		Expression* root = new Expression();
		eat(TokenType::OpenBracket);
		parseExpression(root);
		eat(TokenType::CloseBracket);
		cout<<root->execute();
	}

	void Parser::parseExpression(Node* node)
	{
		if (peek() == TokenType::Number)
		{
			//cout << "Number\n";
			node->node = new Number(stoi(eat(TokenType::Number)));

			parseExpression(node);
		}
		else if (peek() == TokenType::Plus)
		{
			// Left
			Expression* left = &(* (Expression*)node->node);
			// losing the left value before the plus
			cout << ((Number*)node->node)->number << "\n";
			eat(TokenType::Plus);
			((Plus*)(node->node))->left = left;
			cout << ((Number*)node->node)->number << "\n";
			((Plus*)(node->node))->right = new Expression();
			parseExpression(((Plus*)(node->node))->right);
		}
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