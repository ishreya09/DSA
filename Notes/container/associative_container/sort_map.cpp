/*
Maps are associative containers that store elements in a mapped fashion. 
Each element has a key value and a mapped value. 
No two mapped values can have equal key values. 
By default, a Map in C++ is sorted in increasing order based on its key. 
Below is the various method to achieve this:

Method 1 – using the vector of pairs The idea is to copy all contents from the map to the 
corresponding vector of pairs and sort the vector of pairs according to second value using 
the lambda function given below:

bool cmp(pair<T1, T2>& a,
         pair<T1, T2>& b)
{
    return a.second < b.second;
}

where T1 and T2
are the data-types 
that can be the 
same or different.

*/

// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Comparator function to sort pairs
// according to second value
bool cmp(pair<string, int>& a,
		pair<string, int>& b)
{
	return a.second < b.second;
}

// Function to sort the map according
// to value in a (key-value) pairs
void sort(map<string, int>& M)
{

	// Declare vector of pairs
	vector<pair<string, int> > A;

	// Copy key-value pair from Map
	// to vector of pairs
	for (auto& it : M) {
		A.push_back(it);
	}

	// Sort using comparator function
	sort(A.begin(), A.end(), cmp);

	// Print the sorted value
	for (auto& it : A) {

		cout << it.first << ' '
			<< it.second << endl;
	}
}

// Driver Code
int main()
{

	// Declare Map
	map<string, int> M;

	// Given Map
	M = { { "GfG", 3 },
		{ "To", 2 },
		{ "Welcome", 1 } };

	// Function Call
	sort(M);
	return 0;
}
