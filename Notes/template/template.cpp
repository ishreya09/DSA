#include <iostream>
using namespace std;

/*
A template is a simple and yet very powerful tool in C++. The simple idea is to 
pass data type as a parameter so that we don’t need to write the same code for 
different data types. For example, a software company may need sort() for different data types. 
Rather than writing and maintaining the multiple codes, we can write one sort() and pass data type as a parameter. 
C++ adds two new keywords to support templates: ‘template’ and ‘typename’. The second keyword can always 
be replaced by keyword ‘class’.

Templates are expanded at compiler time. 
This is like macros. The difference is, the compiler does type checking before template expansion. 

The idea is simple, source code contains only function/class, 
but compiled code may contain multiple copies of same function/class. 

Function Templates We write a generic function that can be used for different data types. 
Examples of function templates are sort(), max(), min(), printArray(). 




*/


// One function works for all data types. This would work
// even for user defined types if operator '>' is overloaded
template <typename T> T myMax(T x, T y)
{
	return (x > y) ? x : y;
}

int main()
{
	cout << myMax<int>(3, 7) << endl; // Call myMax for int
	cout << myMax<double>(3.0, 7.0)
		<< endl; // call myMax for double
	cout << myMax<char>('g', 'e')
		<< endl; // call myMax for char

	return 0;
}
