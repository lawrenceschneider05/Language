#pragma once
#include "Operator.h"
#include "Number.h"

namespace Lang
{
	class Plus : public Operator
	{
		int execute() override
		{
			Number l = *(Number*)left;
			Number r = *(Number*)right;
			//std::cout <<"fsdfd"<< l.number << " " << r.number;
			return l.number + r.number;
		}
	};
}