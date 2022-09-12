/*
Vectors are the same as dynamic arrays with the ability to resize itself automatically 
when an element is inserted or deleted, with their storage being handled automatically 
by the container. Vector elements are placed in contiguous storage so that they can be 
accessed and traversed using iterators. In vectors, data is inserted at the end. Inserting 
at the end takes differential time, as sometimes the array may need to be extended. 
Removing the last element takes only constant time because no resizing happens. 
Inserting and erasing at the beginning or in the middle is linear in time.

begin() – Returns an iterator pointing to the first element in the vector
end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
cbegin() – Returns a constant iterator pointing to the first element in the vector.

cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.

crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). 
It moves from last to first element

crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector 
(considered as reverse end)
*/

// Does vector uses stack segment of the memory ?

// C++ program to illustrate the
// iterators in vector
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> g1;

	for (int i = 1; i <= 5; i++)
		g1.push_back(i); // similar to append function in python
        // This is a typical stack operation. The function creates an element at the end of the %vector and assigns the given data to it.
        // Due to the nature of a %vector this operation can be done in constant time if the %vector has preallocated space available.

	cout << "Output of begin and end: ";
	for (auto i = g1.begin(); i != g1.end(); ++i) // how does i know the return type of g1.begin() (basically iterator) ?
		cout << *i << " "; // since auto i is containing an iterator - so we are derefrencing it
        // iterator is basically an array of pointers in a for loop


	cout << "\nOutput of cbegin and cend: ";
	for (auto i = g1.cbegin(); i != g1.cend(); ++i)
		cout << *i << " ";

	cout << "\nOutput of rbegin and rend: ";
	for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
		cout << *ir << " ";

	cout << "\nOutput of crbegin and crend : ";
	for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
		cout << *ir << " ";

	return 0;
}
