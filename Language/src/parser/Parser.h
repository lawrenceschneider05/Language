#pragma once
#include <deque>
#include "../lexer/Token.h"
#include "nodes/Node.h"

namespace Lang
{
	class Parser
	{
	public:
		Parser(std::deque<Token> tokens)
		{
			mTokens = tokens;
		}
		void parse();
		string eat(TokenType expected);
	private:
		std::deque<Token> mTokens{};
	};
}