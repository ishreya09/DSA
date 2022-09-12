// Passing by value keeps the original vector unchanged and doesn’t modify the original values of the vector. 
// However, the above style of passing might also take a lot of time in cases of large vectors. 
// So, it is a good idea to pass by reference.

// C++ program to demonstrate how vectors
// can be passed by reference.
#include <bits/stdc++.h>
using namespace std;

// The vect is passed by reference and changes
// made here reflect in main()
void func(vector<int>& vect) { vect.push_back(30); }
// why is & used ?
int main()
{
	vector<int> vect;
	vect.push_back(10);
	vect.push_back(20);

	func(vect);

	for (int i = 0; i < vect.size(); i++)
		cout << vect[i] << " ";

	return 0;
}
