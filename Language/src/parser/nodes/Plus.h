#pragma once
#include "Node.h"
#include <iostream>
#include "Number.h"

namespace Lang
{
	class Plus : public INode
	{
	public:
		Plus()
		{

		}

		~Plus()
		{

		}

		void execute() override
		{
			std::cout << (left->number + right->number);
		}

		Number* left;
		Number* right;
	private:
	};
}