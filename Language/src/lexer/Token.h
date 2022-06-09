#pragma once
#include <string>
#include <ostream>

using namespace std;
namespace Lang
{
	enum class TokenType
	{
		Number,
		Plus,
		OpenBracket,
		CloseBracket,
		Space,
		Error
	};
	static string TokenTypeToString(TokenType type)
	{
		switch (type)
		{
		case TokenType::Number:     return "Number";
		case TokenType::Plus:       return "Plus";
		case TokenType::OpenBracket:  return "OpenBracket";
		case TokenType::CloseBracket: return "CloseBracket";
		case TokenType::Space:      return "Space";
		case TokenType::Error:      return "Error";
		}
		return string("Unrecognized");
	}

	class Token
	{
	public:
		

	public:
		Token(const string& text, const TokenType& type, const int& pos);
		
		inline const string& getText() { return mText; }
		inline const TokenType& getType() { return mType; }
		inline const int& getPos() { return mPos; }

		static TokenType typeOf(char c);

	public:
		operator string() const
		{
			return string("cast");
		}
		
	private:
		string mText;
		TokenType mType;
		int mPos;
	};
}