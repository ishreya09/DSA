// C++ program to demonstrate that we can use auto to
// save time when creating iterators

/*
Note: auto becomes int type if even an integer reference is assigned to it. 
To make it reference type, we use auto &. 

Function that returns a ‘reference to int’ type : int& fun() {};
m will default to int type instead of int& type : auto m = fun();
n will be of int& type because of use of extra & with auto keyword : auto& n = fun();
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Create a set of strings
	set<string> st;
	st.insert({ "geeks", "for", "geeks", "org" });

	// 'it' evaluates to iterator to set of string
	// type automatically
	for (auto it = st.begin(); it != st.end(); it++)
		cout << *it << " ";

	return 0;
}
