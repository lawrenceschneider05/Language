#pragma once
#include "nodes/Node.h"
#include "Bracket.h"

namespace Lang
{
	class Root : public INode
	{
	public:
		Root()
		{
			codeBlock = nullptr;
		}
		~Root()
		{
			delete codeBlock;
		}

		void execute() override
		{
			codeBlock->execute();
		}

		Bracket* codeBlock;
	private:
	};
}