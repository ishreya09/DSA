/*
2) decltype Keyword: It inspects the declared type of an entity or the type of an expression. 
‘auto’ lets you declare a variable with a particular type whereas decltype lets you extract the 
type from the variable so decltype is sort of an operator that evaluates the type of passed expression. 

Explanation of the above keywords and their uses is given below:
*/

// C++ program to demonstrate use of decltype
#include <bits/stdc++.h>
using namespace std;

int fun1() { return 10; }
char fun2() { return 'g'; }

int main()
{
	// Data type of x is same as return type of fun1()
	// and type of y is same as return type of fun2()
	decltype(fun1()) x;
	decltype(fun2()) y;

	cout << typeid(x).name() << endl;
	cout << typeid(y).name() << endl;

	return 0;
}
/*
Output
i
c
*/