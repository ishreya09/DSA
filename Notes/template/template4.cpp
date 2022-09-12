// Can we specify a default value for template arguments? 

// Yes, like normal parameters, we can specify default arguments to templates. 
// The following example demonstrates the same. 

#include <iostream>
using namespace std;

template <class T, class U = char> class A { // default parameter is added for class U
public:
	T x;
	U y;
	A() { cout << "Constructor Called" << endl; }
};

int main()
{
	A<char> a; // This will call A<char, char>
	return 0;
}

