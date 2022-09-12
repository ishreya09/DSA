/*
Method 2 – using the set of pairs The idea is to insert all the (key-value)
pairs from the map into a set of pairs that can be constructed using a comparator function 
that orders the pairs according to the second value.

Below is the implementation of the above approach:

*/


// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Comparison function for sorting the
// set by increasing order of its pair's
// second value
struct comp {
	template <typename T>

	// Comparator function
	bool operator()(const T& l,
					const T& r) const
	{
		if (l.second != r.second) {
			return l.second < r.second;
		}
		return l.first < r.first;
	}
};

// Function to sort the map according
// to value in a (key-value) pairs
void sort(map<string, int>& M)
{

	// Declare set of pairs and insert
	// pairs according to the comparator
	// function comp()
	set<pair<string, int>, comp> S(M.begin(),
								M.end());

	// Print the sorted value
	for (auto& it : S) {
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
