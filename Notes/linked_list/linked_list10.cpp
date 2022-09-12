// The above recursive approach can be modified to make it a tail recursive 
// function and thus our auxiliary space will become O(1):

// Implementation of the above approach is given below:

// Tail Recursive C++ program to find length
// or count of nodes in a linked list


// Time Complexity: O(n)

// As we are traversing the list only once.

// Auxiliary Space: O(1)

// As we are using tail recursive function, no extra space is used in function call stack .

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
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
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}
// A tail recursive function to count the nodes of a linked
// list
// default value of the count is used as zero
int getCount(Node* head, int count = 0) 
{
    // is it tail recursive when what we want to return is also in the arguement?
	// base case
	if (head == NULL)
		return count;
	// move the pointer to next node and increase the count
	return getCount(head->next, count + 1);
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
	cout << "Count of nodes is " << getCount(head);
	return 0;
}

// This is code is contributed by Abhijeet Kumar
