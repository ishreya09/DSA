/*
A program that demonstrates use of both auto and decltype 

Below is a C++ template function min_type() that returns the minimum of two numbers. 
The two numbers can be of any integral type. The return type is determined using 
the type of minimum of two.
*/

// C++ program to demonstrate use of decltype in functions
#include <bits/stdc++.h>
using namespace std;

// A generic function which finds minimum of two values
// return type is type of variable which is minimum
template <class A, class B>
auto findMin(A a, B b) -> decltype(a < b ? a : b)
{
	return (a < b) ? a : b;
}

// driver function to test various inference
int main()
{
	// This call returns 3.44 of double type
	cout << findMin(4, 3.44) << endl;

	// This call returns 3 of double type
	cout << findMin(5.4, 3) << endl;

	return 0;
}
/*
Output
3.44
3
*/