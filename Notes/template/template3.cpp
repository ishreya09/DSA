// Can there be more than one argument to templates? 

// Yes, like normal parameters, we can pass more than one data type as arguments to templates. 
// The following example demonstrates the same.

#include <iostream>
using namespace std;

template <class T, class U> class A { // this takes 2 data type arguements which can be any basic data type or user defined
	T x;
	U y;

public:
	A() { cout << "Constructor Called" << endl; }
};

int main()
{
	A<char, char> a; // objects of class A
	A<int, double> b;
	return 0;
}
