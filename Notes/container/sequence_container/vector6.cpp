/*
Passing Vector to a Function in C++

Difficulty Level : Easy
Last Updated : 06 Jul, 2022
When we pass an array to a function, a pointer is actually passed.

However, to pass a vector there are two ways to do so:

Pass By value
Pass By Reference
When a vector is passed to a function, a copy of the vector is created. 
This new copy of the vector is then used in the function and thus, any changes 
made to the vector in the function do not affect the original vector.

For example, we can see below the program, changes made inside the function are 
not reflected outside because the function has a copy.

Example(Pass By Value):


*/

// C++ program to demonstrate that when vectors
// are passed to functions without &, a copy is
// created.
#include <bits/stdc++.h>
using namespace std;

// The vect here is a copy of vect in main()
void func(vector<int> vect) { vect.push_back(30); }

int main()
{
	vector<int> vect;
	vect.push_back(10);
	vect.push_back(20);

	func(vect);

	// vect remains unchanged after function
	// call
	for (int i = 0; i < vect.size(); i++)
		cout << vect[i] << " ";

	return 0;
}


