#pragma once
#include "Expression.h"
#include "Node.h"

namespace Lang
{
	class Operator : public Node
	{
	public:
		Operator()
		{

		}
		~Operator()
		{

		}
		virtual int execute()
		{
			return 0;
		}
		Expression* left;
		Expression* right;
	private:
	};
}