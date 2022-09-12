// Find Length of a Linked List (Iterative and Recursive)

// Iterative Solution 

// 1) Initialize count as 0 
// 2) Initialize a node pointer, current = head.
// 3) Do following while current is not NULL
//      a) current = current -> next
//      b) count++;
// 4) Return count 

// Iterative C++ program to find length
// or count of nodes in a linked list


// Time complexity: O(n) 

// Where n is the size of the linked list, and we have to traverse the list only once.

// Auxiliary Space: O(1)

// As constant extra space is used.


#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
	public:
	int data;
	Node* next;
};

/* Given a reference (pointer to pointer) to the head
of a list and an int, push a new node on the front
of the list. */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node =new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Counts no. of nodes in linked list */
int getCount(Node* head) // similar to print
{
	int count = 0; // Initialize count
	Node* current = head; // Initialize current
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

/* Driver program to test count function*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	/* Use push() to construct below list
	1->2->1->3->1 */
	push(&head, 1);
	push(&head, 3);
	push(&head, 1);
	push(&head, 2);
	push(&head, 1);

	/* Check the count function */
	cout<<"count of nodes is "<< getCount(head);
	return 0;
}

// This is code is contributed by rathbhupendra


