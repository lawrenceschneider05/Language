#pragma once
#include "Node.h"

namespace Lang
{
	class Bracket : public INode
	{
	public:
		~Bracket()
		{
			delete expression;
		}
		void execute() override
		{
			expression->execute();
		}

		INode* expression;
	};
}