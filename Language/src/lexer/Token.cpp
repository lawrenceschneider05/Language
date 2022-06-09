#include "Token.h"



namespace Lang
{
	
	Token::Token(const string& text, const TokenType& type, const int& pos)
	{
		mText = text;
		mType = type;
		mPos = pos;
	}

	Lang::TokenType Token::typeOf(char c)
	{
		if (c >= 48 && c <= 57)
		{
			return TokenType::Number;
		}
		else if (c == '+')
		{
			return TokenType::Plus;
		}
		else if (c == '{')
		{
			return TokenType::OpenBracket;
		}
		else if (c == '}')
		{
			return TokenType::CloseBracket;
		}
		else if (c == ' ')
		{
			return TokenType::Space;
		}
		return TokenType::Error;
	}
	
}