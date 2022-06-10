#pragma once
#include <deque>
#include "../lexer/Token.h"
#include "nodes/Node.h"
#include "nodes/Expression.h"
namespace Lang
{
	class Parser
	{
	public:
		Parser(std::deque<Token> tokens)
		{
			mTokens = tokens;
			root = nullptr;
		}
		void parse();
		void parseExpression(Node* node);
		string eat(TokenType expected);
		inline TokenType peek()
		{
			return mTokens.front().getType();
		}

		inline void execute()
		{
			//root->execute();
		}
	private:
		Expression* root;
		std::deque<Token> mTokens{};
	};
}