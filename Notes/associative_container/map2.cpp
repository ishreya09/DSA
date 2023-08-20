// C++ program to illustrate map::rend() function

#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<char, int> mymap;

	// Insert pairs in the multimap
	mymap.insert(make_pair('a', 1));
	mymap.insert(make_pair('b', 3));
	mymap.insert(make_pair('c', 5));

	// Show content
	for (auto it = mymap.rbegin(); it != mymap.rend(); it++) {

		cout << it->first
			<< " = "
			<< it->second
			<< endl;
	}

	return 0;
}
