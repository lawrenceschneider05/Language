#pragma once
namespace Lang
{
	class Node
	{
	public:

		virtual ~Node()
		{

		}
		virtual int execute()
		{
			return 0;
		}
		Node* node = nullptr;
	private:
	};
}