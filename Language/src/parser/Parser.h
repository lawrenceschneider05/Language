#pragma once
#include <deque>
#include "../lexer/Token.h"
#include "nodes/Node.h"
#include "nodes/Root.h"

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

		inline void execute()
		{
			root->execute();
		}
	private:
		Root* root;
		std::deque<Token> mTokens{};
	};
}