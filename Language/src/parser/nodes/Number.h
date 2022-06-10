#pragma once
#include "Expression.h"

namespace Lang
{
	class Number : public Expression
	{
	public:
		Number(int i)
		{
			number = i;
		}
		int execute() override
		{
			return number;
		}
		int number;
	};
}