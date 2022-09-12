/*
priority_queue::emplace()
This function is used to insert a new element into the priority queue container, 
the new element is added to the priority queue according to its priority. 
It is similar to push operation. The difference is that emplace() operation 
saves unnecessary copy of the object.

Time complexity: O(log n)

Syntax :  

priorityqueuename.emplace(value)
Parameters :
The element to be inserted into the priority
queue is passed as the parameter.
Result :
The parameter is added to the
priority queue at the top position.

Examples: 

Input  : mypqueue{5, 4};
         mypqueue.emplace(6);
Output : mypqueue = 6, 5, 4

Input  : mypqueue{};
         mypqueue.emplace(4);
Output : mypqueue = 4

Note: In priority_queue container, the elements are printed in reverse order because the top 
is printed first then moving on to other elements.

Errors and Exceptions 
1. It has a strong exception guarantee, therefore, no changes are made if an exception is thrown. 
2. Parameter should be of same type as that of the container, otherwise an error is thrown.
*/

// INTEGER PRIORITY QUEUE
// CPP program to illustrate
// Implementation of emplace() function
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> mypqueue;
	mypqueue.emplace(1);
	mypqueue.emplace(2);
	mypqueue.emplace(3);
	mypqueue.emplace(4);
	mypqueue.emplace(5);
	mypqueue.emplace(6);
	// queue becomes 1, 2, 3, 4, 5, 6

	// printing the priority queue
	cout << "mypqueue = ";
	while (!mypqueue.empty()) {
		cout << mypqueue.top() << " "; // mypqueue = 6 5 4 3 2 1 
		mypqueue.pop();
	}

	return 0;
}
