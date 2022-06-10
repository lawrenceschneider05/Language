#pragma once
#include "Node.h"
namespace Lang
{
	class Expression : public Node
	{
	public:
		Expression()
		{
		
		}
		~Expression()
		{

		}

		int execute() override
		{
			return node->execute();
		}
	};
}