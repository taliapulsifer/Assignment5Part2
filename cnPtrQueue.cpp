#include "cnPtrQueue.h"
#include <cassert>
#include <cstdlib>
using namespace std;

namespace CS3358_FA2023_A5P2
{


	size_t cnPtrQueue::size() const
	{
		size_t counter;
		//Traverse the queue and tally the number of
		//elements found

		return counter;

	}

	void cnPtrQueue::push(CNode* cnPtr)
	{
		//Using stdStack function push
		inStack.push(cnPtr);
	}

	void cnPtrQueue::pop()
	{
		//Make sure that one of the stacks is not empty
		assert(!inStack.empty() || !outStack.empty());
		//If the outStack IS empty
		if (outStack.empty())
		{
			//While the inStack is not empty (until we hit the end of the stack)
			while (!inStack.empty())
			{
				//Push the top of instack
				outStack.push(inStack.top());
				//Take the element that we pushed to outstack out of instack
				inStack.pop();
			}
		}
		//pop outstack
		outStack.pop();
	}

	CNode* cnPtrQueue::front()
	{
		//Chack that at least one of the queues has values
		assert(!inStack.empty() || !outStack.empty());
		//If the outstack IS empty
		if (outStack.empty())
		{
			//While the instack still has values
			while (!inStack.empty())
			{
				//push the top of instack
				outStack.push(inStack.top());
				//Pop the value from instack that we just put into outstack
				inStack.pop();
			}
		}
		//Return the top of outstack
		return outStack.top();
	}

	bool cnPtrQueue::empty() const
	{
		//Check to see if the size is 0.
		//If it is, its empty
		return size() == 0;
	}

}
