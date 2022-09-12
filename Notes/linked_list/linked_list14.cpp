// Program for n’th node from the end of a Linked List

// https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/

/*
Given a Linked List and a number n, write a function that returns 
the value at the n’th node from the end of the Linked List.

For example, if the input is below list and n = 3, then output is “B”

NOTE: Index from end starts with 1

Algorithm

1. get the number of elements/ length of linked list in the linked list
2. check for the index n-i index node from the start.
// true when we take starting index as zero 

Method 1 (Use length of linked list) 

1) Calculate the length of the Linked List. Let the length be len. 
2) Print the (len – n + 1)th node from the beginning of the Linked List. 

Note : from both sides - we are starting index from 1.

Double pointer concept: First pointer is used to store the address of the 
variable and the second pointer is used to store the address of the first pointer. 
If we wish to change the value of a variable by a function, we pass a pointer to it. 
And if we wish to change the value of a pointer (i. e., it should start pointing to 
something else), we pass the pointer to a pointer.


Time complexity: O(n) where n is size of the linked list

Auxiliary Space: O(1)

*/

// Simple C++ program to find n'th node from end
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};

/* Function to get the nth node from
the last of a linked list*/
void printNthFromLast(struct Node* head, int n)
{
	int len = 0, i;
	struct Node* temp = head;

	// count the number of nodes in Linked List
	while (temp != NULL) {
		temp = temp->next;
		len++;
	}

	// check if value of n is not
	// more than length of the linked list
	if (len < n)
		return;

	temp = head; // re-initialise

	// get the (len-n+1)th node from the beginning
	for (i = 1; i < len - n + 1; i++)
		temp = temp->next;

	cout << temp->data;

	return;
}

void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

// Driver Code
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	// create linked 35->15->4->20
	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 35);

	printNthFromLast(head, 4);
	return 0;
}
