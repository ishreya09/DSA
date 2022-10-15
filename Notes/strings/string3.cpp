// C++ program to print words in a sentence
#include <bits/stdc++.h>
using namespace std;

void removeDupWord(string str)
{
	// Used to split string around spaces.
	istringstream ss(str);

	string word; // for storing each word

	// Traverse through all words
	// while loop till we get
	// strings to store in string word
	while (ss >> word)
	{
		// print the read word
		cout << word << "\n";
	}
}

// Driver code
int main()
{
	string str = "Geeks for Geeks";
	removeDupWord(str);
	return 0;
}
