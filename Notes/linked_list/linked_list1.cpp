/*
https://www.geeksforgeeks.org/data-structures/linked-list/singly-linked-list/

https://www.geeksforgeeks.org/data-structures/linked-list/

https://www.geeksforgeeks.org/linked-list-set-1-introduction/

Like arrays, Linked List is a linear data structure. Unlike arrays, 
linked list elements are not stored at a contiguous location; the elements 
are linked using pointers. They includes a series of connected nodes. Here, 
each node stores the data and the address of the next node.

Why Linked List? 

Arrays can be used to store linear data of similar types, but arrays have the following limitations. 

The size of the arrays is fixed: So we must know the upper limit on the number of elements in advance. 

Also, generally, the allocated memory is equal to the upper limit irrespective of the usage. 
Insertion of a new element / Deletion of a existing element in an array of elements is expensive: 
The room has to be created for the new elements and to create room existing elements have to be shifted 
but in Linked list if we have the head node then we can traverse to any node through it and insert new 
node at the required position.

For example, in a system, if we maintain a sorted list of IDs in an array id[]. 
id[] = [1000, 1010, 1050, 2000, 2040]. 
And if we want to insert a new ID 1005, then to maintain the sorted order, we have to move all the elements 
after 1000 (excluding 1000). 

Deletion is also expensive with arrays until unless some special techniques are used. 
For example, to delete 1010 in id[], everything after 1010 has to be moved due to this so 
much work is being done which affects the efficiency of the code.

Advantages over arrays:
Dynamic Array.
Ease of Insertion/Deletion.


Drawbacks: 
Random access is not allowed. We have to access elements sequentially 
starting from the first node(head node). So we cannot do binary search with linked lists 
efficiently with its default implementation. Read about it here. 

Extra memory space for a pointer is required with each element of the list. 

Not cache friendly. Since array elements are contiguous locations, there is locality of 
reference which is not there in case of linked lists.


Representation: 

A linked list is represented by a pointer to the first node of the linked list. 
The first node is called the head. If the linked list is empty, then the value of the head points to NULL. 

Each node in a list consists of at least two parts: 

A Data Item (we can store integer, strings or any type of data).
Pointer (Or Reference) to the next node (connects one node to another) or An address of another node
In C, we can represent a node using structures. Below is an example of a linked list node with integer data. 
In Java or C#, LinkedList can be represented as a class and a Node as a separate class. 
The LinkedList class contains a reference of Node class type. 




*/

// A simple CPP program to introduce
// a linked list

#include <bits/stdc++.h>
using namespace std;

class Node { 
public:
	int data;
	Node* next; // pointer to a class - 
};

// Program to create a simple linked
// list with 3 nodes
int main()
{
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;

	// allocate 3 nodes in the heap
	head = new Node(); // object creation for pointers?
	second = new Node();
	third = new Node();

	/* Three blocks have been allocated dynamically.
	We have pointers to these three blocks as head,
	second and third	
	head		 second		 third
		|			 |			 |
		|			 |			 |
	+---+-----+	 +----+----+	 +----+----+
	| # | # |	 | # | # |	 | # | # |
	+---+-----+	 +----+----+	 +----+----+
	
# represents any random value.
Data is random because we haven’t assigned
anything yet */
    // could class and struct be same ? or is it just because its stored in a similar way?
    // class members could be directly accessed with help of -> operator if that's a pointer
    // . operator is used if its an object
	head->data = 1; // assign data in first node
	head->next = second; // Link first node with
	// the second node

	/* data has been assigned to the data part of first
	block (block pointed by the head). And next
	pointer of the first block points to second.
	So they both are linked.

	head		 second		 third
		|			 |			 |
		|			 |			 |
	+---+---+	 +----+----+	 +-----+----+
	| 1 | o----->| # | # |	    | # | # |
	+---+---+	 +----+----+	 +-----+----+	
*/

	// assign data to second node
	second->data = 2;

	// Link second node with the third node
	second->next = third;

	/* data has been assigned to the data part of the second
	block (block pointed by second). And next
	pointer of the second block points to the third
	block. So all three blocks are linked.
	
	head		 second		 third
		|			 |			 |
		|			 |			 |
	+---+---+	 +---+---+	 +----+----+
	| 1 | o----->| 2 | o-----> | # | # |
	+---+---+	 +---+---+	 +----+----+	 */

	third->data = 3; // assign data to third node
	third->next = NULL;

	/* data has been assigned to the data part of the third
	block (block pointed by third). And next pointer
	of the third block is made NULL to indicate
	that the linked list is terminated here.

	We have the linked list ready.

		head	
			|
			|
		+---+---+	 +---+---+	 +----+------+
		| 1 | o----->| 2 | o-----> | 3 | NULL |
		+---+---+	 +---+---+	 +----+------+	
	
	
	Note that only the head is sufficient to represent
	the whole list. We can traverse the complete
	list by following the next pointers. */

	return 0;
}

// This code is contributed by rathbhupendra



