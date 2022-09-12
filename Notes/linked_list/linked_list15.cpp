// Program for n’th node from the end of a Linked List

// Recursive Solution

// Time Complexity: O(n) where n is the length of linked list. 

// Auxiliary Space: O(n) for call stack

#include<bits/stdc++.h>
using namespace std;


/* Link list node */
struct Node {
	int data;
	struct Node* next;
};


void printNthFromLast(struct Node* head, int n)
{
	static int i = 0;
	if (head == NULL)
		return;
	printNthFromLast(head->next, n);
	if (++i == n)
		cout<<head->data;
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
