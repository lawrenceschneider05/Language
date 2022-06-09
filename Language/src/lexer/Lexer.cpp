#include "Lexer.h"
#include <iostream>
namespace Lang
{
	Lexer::Lexer(string program)
	{
		mProgram = program;
	}

	Lexer::~Lexer()
	{

	}
	/// <summary>
	/// Split 
	/// </summary>
	void Lexer::lexLine(string line)
	{
		mTokens = {};
		string currentToken = string(1, line[0]);
		for (int i = 1; i < line.size(); i++)
		{
			char c = line[i];

			if (Token::typeOf(c) != Token::typeOf(currentToken[0]))
			{
				addToken(currentToken, i);
				currentToken = "";
			}

			currentToken += c;
		}
		addToken(currentToken, line.size() - 1);
	}

	void Lexer::addToken(string tok, int pos)
	{
		if (Token::typeOf(tok[0]) != TokenType::Space)
		{
			mTokens.push_back(Token(tok, Token::typeOf(tok[0]), pos));
		}
	}

	void Lexer::debug()
	{
		for (auto it = mTokens.begin(); it < mTokens.end(); it++)
		{
			try
			{
				if ((*it).getType() == TokenType::Error)
				{
					throw((*it).getPos());
				}
			}
			catch (int pos)
			{
				cout << "LEXER ERROR: Unrecognized character at position " << pos << "\n";
			}
		}
	}
}