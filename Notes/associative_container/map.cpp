// Maps are associative containers that store elements in a mapped fashion. 
// Each element has a key value and a mapped value. No two mapped values can have the same key values.

// Some basic functions associated with Map: 

// begin() – Returns an iterator to the first element in the map.
// end() – Returns an iterator to the theoretical element that follows the last element in the map.
// size() – Returns the number of elements in the map.
// max_size() – Returns the maximum number of elements that the map can hold.
// empty() – Returns whether the map is empty.
// pair insert(keyvalue, mapvalue) – Adds a new element to the map.
// erase(iterator position) – Removes the element at the position pointed by the iterator.
// erase(const g)– Removes the key-value ‘g’ from the map.
// clear() – Removes all the elements from the map.

// CPP Program to demonstrate the implementation in Map
#include <iostream>
#include <iterator>
#include <map> // to include map
using namespace std;

int main()
{

	// empty map container
	map<int, int> gquiz1; // template class objects of map class 

	// insert elements in random order
	// pair is another class having a template - here using a constructor
	gquiz1.insert(pair<int, int>(1, 40));
	gquiz1.insert(pair<int, int>(2, 30));
	gquiz1.insert(pair<int, int>(3, 60));
	gquiz1.insert(pair<int, int>(4, 20));
	gquiz1.insert(pair<int, int>(5, 50));
	gquiz1.insert(pair<int, int>(6, 50)); // key value, map value
	
	gquiz1[7]=10;
	gquiz1[0]=20;	 // another way of inserting a value in a map
	// gquiz[keyvalue]= mapvalue;

	// printing map gquiz1
	map<int, int>::iterator itr;
	cout << "\nThe map gquiz1 is : \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
		cout << '\t' << itr->first << '\t' << itr->second << '\n'; 
		// why -> operator is used? - is itr a pointer and is itr is pointing to a structure? -yes
	}
	cout << endl;

	// assigning the elements from gquiz1 to gquiz2 
	map<int, int> gquiz2(gquiz1.begin(), gquiz1.end()); // working with the constructor of map class

	// print all elements of the map gquiz2
	cout << "\nThe map gquiz2 after"
		<< " assign from gquiz1 is : \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		cout << '\t' << itr->first << '\t' << itr->second
			<< '\n';
	}
	cout << endl;

	// remove all elements up to
	// element with key=3 in gquiz2
	cout << "\ngquiz2 after removal of"
			" elements less than key=3 : \n";
	cout << "\tKEY\tELEMENT\n";
	gquiz2.erase(gquiz2.begin(), gquiz2.find(3)); // erases a range of elements less than key=3
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		cout << '\t' << itr->first << '\t' << itr->second
			<< '\n';
	}

	// remove all elements with key = 4
	int num;
	num = gquiz2.erase(4); 
	cout << "\ngquiz2.erase(4) : ";
	cout << num << " removed \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		cout << '\t' << itr->first << '\t' << itr->second
			<< '\n';
	}

	cout << endl;

	// lower bound and upper bound for map gquiz1 key = 5
	// what is the role of upper bound and lower bound?
	cout << "gquiz1.lower_bound(5) : "
		<< "\tKEY = ";
	cout << gquiz1.lower_bound(5)->first << '\t';
	cout << "\tELEMENT = " << gquiz1.lower_bound(5)->second
		<< endl;
	cout << "gquiz1.upper_bound(5) : "
		<< "\tKEY = ";
	cout << gquiz1.upper_bound(5)->first << '\t';
	cout << "\tELEMENT = " << gquiz1.upper_bound(5)->second
		<< endl;

	return 0;
}

/*

List of all Functions of Map 
Function	                        Definition
map::insert()	                    Insert elements with a particular key in the map container –> O(log n)
map:: count()	                    Returns the number of matches to element with key-value ‘g’ in the map. –> O(log n)
map equal_range()	                Returns an iterator of pairs. The pair refers to the bounds of a range that includes all 
                                    the elements in the container which have a key equivalent to k.
map erase()	                        Used to erase elements from the container –> O(log n)
map rend()	                        Returns a reverse iterator pointing to the theoretical element right before the first key-value pair
                                    in the map(which is considered its reverse end).
map rbegin() 	                    Returns a reverse iterator which points to the last element of the map.
map find()	                        Returns an iterator to the element with key-value ‘g’ in the map if found, else returns the iterator to end.

map crbegin() and crend() 	crbegin()   returns a constant reverse iterator referring to the last element in the map container.
                                        crend() returns a constant reverse iterator pointing to the theoretical element before 
                                        the first element in the map.

map cbegin() and cend()	 cbegin()       returns a constant iterator referring to the first element in the map container. 
                                        cend() returns a constant iterator pointing to the theoretical element that follows the 
                                        last element in the multimap.

map emplace()	                    Inserts the key and its element in the map container.
map max_size() 	                    Returns the maximum number of elements a map container can hold –> O(1)
map upper_bound()	                Returns an iterator to the first element that is equivalent to mapped value with key-value ‘g’ 
                                    or definitely will go after the element with key-value ‘g’ in the map
map operator=	                    Assigns contents of a container to a different container, replacing its current content.

map lower_bound()	                Returns an iterator to the first element that is equivalent to the mapped value with key-value ‘g’ 
                                    or definitely will not go before the element with key-value ‘g’ in the map –> O(log n)

map emplace_hint()	                Inserts the key and its element in the map container with a given hint.
map value_comp() 	                Returns the object that determines how the elements in the map are ordered (‘<‘ by default).
map key_comp() 	                    Returns the object that determines how the elements in the map are ordered (‘<‘ by default).
map::size()	                        Returns the number of elements in the map.
map::empty()	                    Returns whether the map is empty

map::begin() and end()	begin()     returns an iterator to the first element in the map. end() returns an iterator to the theoretical 
                                    element that follows the last element in the map

map::operator[]	                    This operator is used to reference the element present at the position given inside the operator.
map::clear() 	                    Removes all the elements from the map.

map::at() and map::swap()	        at() function is used to return the reference to the element associated with the key k. swap() 
                                    function is used to exchange the contents of two maps but the maps must be of the same type, 
                                    although sizes may differ.

*/
