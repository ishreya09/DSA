// C++ code to demonstrate difference between
// emplace and insert
#include<bits/stdc++.h>
using namespace std;

/*
emplace() vs push() 

When we use push(), we create an object and then insert it into the priority_queue. 
With emplace(), the object is constructed in-place and saves an unnecessary copy. 
Please see emplace vs insert in C++ STL for details.
*/

int main()
{
	// declaring priority queue
	priority_queue<pair<char, int>> pqueue;
	
	// using emplace() to insert pair in-place
	pqueue.emplace('a', 24);
	
	// Below line would not compile
	// pqueue.push('b', 25);
	
	// using push() to insert pair
	pqueue.push(make_pair('b', 25));
	
	// printing the priority_queue
	while (!pqueue.empty()) {
		pair<char, int> p = pqueue.top();
		cout << p.first << " "
			<< p.second << endl;
		pqueue.pop();
	}

	return 0;
}
