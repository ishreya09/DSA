// Sets are a type of associative containers in which each element has to be unique because the value of the element identifies it. 
// The values are stored in a specific order. 

/*
Syntax:

set<datatype> setname;

Datatype: Set can take any data type depending on the values, e.g. int, char, float, etc.

Example:

set<int> val; // defining an empty set
set<int> val = {6, 10, 5, 1}; // defining a set with values
Note: set<datatype, greater<datatype>> setname; is used for storing values in a set in descending order.

Properties:

The set stores the elements in sorted order.
All the elements in a set have unique values.
The value of the element cannot be modified once it is added to the set, though it is possible to remove and then 
add the modified value of that element. Thus, the values are immutable.

Sets follow the Binary search tree implementation.

The values in a set are unindexed.

Note: To store the elements in an unsorted(random) order,  unordered_set() can be used.

Some Basic Functions Associated with Set: 

begin() – Returns an iterator to the first element in the set.
end() – Returns an iterator to the theoretical element that follows the last element in the set.
size() – Returns the number of elements in the set.
max_size() – Returns the maximum number of elements that the set can hold.
empty() – Returns whether the set is empty.

The time complexities for doing various operations on sets are –

Insertion of Elements – O(log N)
Deletion of Elements – O(log N)

*/

// CPP program to demonstrate various functions of
// Set in C++ STL
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main()
{
	// empty set container
	set<int, greater<int> > s1; // stores in decending order

	// insert elements in random order
	s1.insert(40);
	s1.insert(30);
	s1.insert(60);
	s1.insert(20);
	s1.insert(50);

	// only one 50 will be added to the set
	s1.insert(50);
	s1.insert(10);


	// printing set s1
    // what is an iterator? 
	set<int, greater<int> >::iterator itr; // iterator itr gets the list kinda something maybe?

	cout << "\nThe set s1 is : \n";
	for (itr = s1.begin(); itr != s1.end(); itr++) { // itr is a pointer
		cout << *itr << " "; // derefrencing the pointer
	}
	cout << endl;

	// assigning the elements from s1 to s2
	set<int> s2(s1.begin(), s1.end()); // normal writing stores in accending order

	// print all elements of the set s2
	cout << "\nThe set s2 after assign from s1 is : \n";
	for (itr = s2.begin(); itr != s2.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;

	// remove all elements up to 30 in s2
	cout << "\ns2 after removal of elements less than 30 "
			":\n";

	s2.erase(s2.begin(), s2.find(30)); // removes upto 30
    // find() function finds 30 and iterates until it reaches 30
    // is it to be treated like index?

	for (itr = s2.begin(); itr != s2.end(); itr++) {
		cout << *itr << " ";
	}



	// remove element with value 50 in s2
	int num;
	num = s2.erase(50); // removes one element
	cout << "\ns2.erase(50) : ";
	cout << num << " removed\n";
	for (itr = s2.begin(); itr != s2.end(); itr++) {
		cout << *itr << " ";
	}

	cout << endl;

    cout<< "printing s1 : \n";
    for (itr = s1.begin(); itr != s1.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;


	// lower bound and upper bound for set s1
	cout << "s1.lower_bound(40) : \n"
		<< *s1.lower_bound(35) << endl; // lower bound checks for the number bit greater heirarchy than the given number in the set and 
        // calls that as lower_bound () of s1 object
	cout << "s1.upper_bound(40) : \n"
		<< *s1.upper_bound(15) << endl; //  upper bound checks for the number bit greater in heirarchy in the set and is called as 
        // upper bound of the number
        // if the number is the last member of the set , then a random number is returned

	// lower bound and upper bound for set s2
	cout << "s2.lower_bound(40) :\n"
		<< *s2.lower_bound(40) << endl;
	cout << "s2.upper_bound(40) : \n"
		<< *s2.upper_bound(40) << endl;

	return 0;
}

/*
Method	        Description
begin()	        Returns an iterator to the first element in the set.
end()	        Returns an iterator to the theoretical element that follows the last element in the set.
rbegin()	    Returns a reverse iterator pointing to the last element in the container.
rend()	        Returns a reverse iterator pointing to the theoretical element right before the first element in the set container.
crbegin()	    Returns a constant iterator pointing to the last element in the container.
crend()	        Returns a constant iterator pointing to the position just before the first element in the container.
cbegin()	    Returns a constant iterator pointing to the first element in the container.
cend()	        Returns a constant iterator pointing to the position past the last element in the container.
size()	        Returns the number of elements in the set.
max_size()	    Returns the maximum number of elements that the set can hold.
empty()	        Returns whether the set is empty.

Method	                                              Description

insert(const g) 	                                 Adds a new element ‘g’ to the set.
iterator insert (iterator position, const g)	     Adds a new element ‘g’ at the position pointed by the iterator.
erase(iterator position) 	                        Removes the element at the position pointed by the iterator.
erase(const g)	                                    Removes the value ‘g’ from the set.
clear() 	                                        Removes all the elements from the set.
key_comp() / value_comp()	                        Returns the object that determines how the elements in the set are ordered (‘<‘ by default).
find(const g)	                                    Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to end.
count(const g)	                                    Returns 1 or 0 based on the element ‘g’ is present in the set or not.
lower_bound(const g)	                            Returns an iterator to the first element that is equivalent to ‘g’ or definitely
                                                    will not go before the element ‘g’ in the set.

upper_bound(const g)	                            Returns an iterator to the first element that will go after the element ‘g’ in the set.
equal_range()	                                    The function returns an iterator of pairs. (key_comp). The pair refers to the range that 
                                                    includes all the elements in the container which have a key equivalent to k.

emplace()	                                        This function is used to insert a new element into the set container, only if the element to 
                                                    be inserted is unique and does not already exist in the set.

emplace_hint()	                                    Returns an iterator pointing to the position where the insertion is done. 
                                                    If the element passed in the parameter already exists, then it returns an 
                                                    iterator pointing to the position where the existing element is.

swap()	                                            This function is used to exchange the contents of two sets but the sets must be of the same 
                                                    type, although sizes may differ.
                                                    
operator=	                                        The ‘=’ is an operator in C++ STL which copies (or moves) a set to another set and 
                                                    set::operator= is the corresponding operator function.

get_allocator()	                                    Returns the copy of the allocator object associated with the set.

*/
