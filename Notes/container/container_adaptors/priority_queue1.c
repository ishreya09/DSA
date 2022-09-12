/*
How to create a min-heap for the priority queue? 
We can pass another parameter while creating the priority queue to make it a min heap. 
C++ provides the below syntax for the same.  

Syntax:

priority_queue <int, vector<int>, greater<int>> g = gq;  


Note: The above syntax may be difficult to remember, so in case of numeric values, 
we can multiply the values with -1 and use max heap to get the effect of min heap.
*/

// C++ program to demonstrate min heap for priority queue

#include<bits/stdc++.h>
using namespace std;

void showpq(
	priority_queue<int, vector<int>, greater<int> > gq)
{
	priority_queue<int, vector<int>, greater<int> > g = gq;
	while (!g.empty()) {
		cout << '\t' << g.top();
		g.pop();
	}
	cout << '\n';
}

// Driver Code
int main()
{
	priority_queue<int, vector<int>, greater<int> > gquiz; // pq in ascending order
	gquiz.push(10);
	gquiz.push(30);
	gquiz.push(20);
	gquiz.push(5);
	gquiz.push(1);

	cout << "The priority queue gquiz is : ";
	showpq(gquiz);

	cout << "\ngquiz.size() : " << gquiz.size();
	cout << "\ngquiz.top() : " << gquiz.top();

	cout << "\ngquiz.pop() : ";
	gquiz.pop();
	showpq(gquiz);

	return 0;
}
