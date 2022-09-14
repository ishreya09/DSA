// C++ program to demonstrate working of auto
// and type inference

#include <bits/stdc++.h>
using namespace std;

int main()
{
	// auto a; this line will give error
	// because 'a' is not initialized at
	// the time of declaration
	// a=33;

	// see here x ,y,ptr are
	// initialised at the time of
	// declaration hence there is
	// no error in them
	auto x = 4;
	auto y = 3.37;
	auto ptr = &x;
	cout << typeid(x).name() << endl
		<< typeid(y).name() << endl
		<< typeid(ptr).name() << endl;

    /*
    Output: 
    
    i
    d
    Pi

	Note: We have used typeid for getting the type of the variables. 

	Typeid is an operator which is used where the dynamic type of an object needs to be known. 

	typeid(x).name() returns the data type of x, for example, it return ‘i’ for integers, ‘d’ for doubles, 
	‘Pi’ for the pointer to integer etc. But the actual name returned is mostly compiler dependent. 
	
	Good use of auto is to avoid long initializations when creating iterators for containers.
    */
	return 0;
}
