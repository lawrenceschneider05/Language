#pragma once
#include "Node.h"
#include <iostream>

namespace Lang
{
	class Number : public INode
	{
	public:
		Number()
		{

		}

		~Number()
		{

		}

		void execute() override
		{
			
		}

		int number;
	private:
	};
}