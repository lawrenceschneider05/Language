/*
-Input: file path
-Output: tokens

Steps:
-Create string from file
-Tokenize
*/

#pragma once
#include <string>
#include <vector>
#include "Token.h"

using namespace std;
namespace Lang
{
	class Lexer
	{
	public:
		Lexer(string program);
		~Lexer();

		void lexLine(string line);

		void debug();

		inline vector<Token>& getTokens() { return mTokens; }

		inline bool success() { return mSuccess; }
	private:
		void addToken(string tok, int pos);
		vector<Token> mTokens;
		string mProgram;
		bool mSuccess;
	};
}