// CPP Program to demonstrate Priority Queue
#include <iostream>
#include <queue>
using namespace std;

/*
https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/

Priority queues are a type of container adapters, specifically designed such that the 
first element of the queue is either the greatest or the smallest of all elements in 
the queue and elements are in nonincreasing order (hence we can see that each element 
of the queue has a priority {fixed order}). However in C++ STL, by default, the top 
element is always the greatest element. We can also change it to the smallest element 
at the top. Priority queues are built on the top to the max heap and uses array or vector 
as an internal structure.

*/

void showpq(priority_queue<int> gq)
{
	priority_queue<int> g = gq;
	while (!g.empty()) {
		cout << '\t' << g.top();
		g.pop();
	}
	cout << '\n';
}

// Driver Code
int main()
{
	priority_queue<int> gquiz;
	gquiz.push(10);
	gquiz.push(30); // to push into the pq
	gquiz.push(20);
	gquiz.push(5); // sorted in decending order
	gquiz.push(1);

	cout << "The priority queue gquiz is : ";
	showpq(gquiz);

	cout << "\ngquiz.size() : " << gquiz.size();
	cout << "\ngquiz.top() : " << gquiz.top();

	// cout << "\ngquiz.pop() : " << gquiz.pop() <<endl;
	gquiz.pop();
	showpq(gquiz);

	return 0;
}

/*
Methods of Priority Queue are: 

Method

Definition

priority_queue::empty()	    Returns whether the queue is empty.
priority_queue::size() 	    Returns the size of the queue.
priority_queue::top()	    Returns a reference to the topmost element of the queue.
priority_queue::push()  	Adds the element ‘g’ at the end of the queue.
priority_queue::pop()	    Deletes the first element of the queue.
priority_queue::swap()	    Used to swap the contents of two queues provided the queues must be of the same type,
                            although sizes may differ.
priority_queue::emplace()	Used to insert a new element into the priority queue container.
priority_queue value_type 	Represents the type of object stored as an element in a priority_queue. 
                            It acts as a synonym for the template parameter.
*/