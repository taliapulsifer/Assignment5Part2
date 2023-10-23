#include "cnPtrQueue.h"
#include <cassert>
#include <cstdlib>
using namespace std;

namespace CS3358_FA2023_A5P2
{


	size_t cnPtrQueue::size() const
	{

	}

	void cnPtrQueue::push(CNode* cnPtr)
	{
		inStack.push(cnPtr);
	}

	void cnPtrQueue::pop()
	{
		assert(!inStack.empty() || !outStack.empty());
		if (outStack.empty())
		{
			while (!inStack.empty())
			{
				outStack.push(inStack.top());
				inStack.pop();
			}
		}
		outStack.pop();
	}

	CNode* cnPtrQueue::front()
	{
		assert(!inStack.empty() || !outStack.empty());
		if (outStack.empty())
		{
			while (!inStack.empty())
			{
				outStack.push(inStack.top());
				inStack.pop();
			}
		}
		return outStack.top();
	}

	bool cnPtrQueue::empty() const
	{
		return size() == 0;
	}

}
