// ordering by the first element of pairs in the priority queue(Max)

/*

How to implement min-heap using C++ STL library?
In C++, STL library priority_queue is by default made max-heap. 
To use priority_queue as min-heap,
we need to add two extra arguments as shown below.

priority_queue<type, vector<type>, greater<type> > pq;
*/

#include <bits/stdc++.h>
using namespace std;

//  print the data of
// the priority queue ordered by first
void print_pq( priority_queue < pair < int,  int > > pq)
{
// printing and popping out the elements
// until the priority queue
// is not empty
	while (!pq.empty()) 
	{
		cout << pq.top().first << " " << pq.top().second <<  endl;
		pq.pop();
	}
	cout <<  endl;
}

// driver Code
int main()
{
	priority_queue < pair < int,  int > > p;

// inserting of elements in priority queue
	p.push(make_pair(1,  9));
	p.push(make_pair(8,  4));
	p.push(make_pair(4,  5));
	p.push(make_pair(3,  3));
	p.push(make_pair(2,  7));
	print_pq(p);
	return 0;
}