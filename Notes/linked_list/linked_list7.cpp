/*
Algorithm For C/C++: Iterate through the linked list and delete all the nodes one by one. 
The main point here is not to access the next of the current pointer if the current pointer is deleted.

In Java, Python, and JavaScript automatic garbage collection happens, so deleting a linked list is easy. 
Just need to change head to null.


Delete from beginning
Delete from the end
Delete from middle
Delete from the beginning :

ALGORITHM:

Store the address of the first node in a pointer. 
move the head node to the next node
dispose or free memory  of the pointer node 

// Delete linkedlist from beginiing
X=head;
head= head->next;
free(x);


Delete the last node:

ALGORITHM:

Traverse link list  to second last element
Change its next pointer to null
Free the memory of the last node.

// Delete linkedlist from end
Struct node* temp=head ;
While(temp->next->next!=NULL)
{
Temp= temp->next ;
}
Temp->next= NULL;



Delete from the middle:

ALGORITHM:

Store the address of the deleted node as a key node.
Store the address of the preceding node in a pointer. Eg . P
Store the address of a key node in the pointer variable  . eg . X
Make the successor of the key node as the successor of the node pointed by p.
Free node X.

// Delete linkedlist from middle
for(int i=2;i<position; i++)
{
If(temp->next!=NULL)
{
Temp=temp->next;
}
}
Temp->next=temp->next->next;



Time Complexity: O(n) 
Auxiliary Space: O(1)
*/

// C++ program to delete a linked list
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
}; 

// does class allocates memory on heap segment as we use free to delete the node? Or Does c++ creates everything in 
// dynamic memory only - because in case of vectors/ maps, etc -they are all are dynamic??

/* Function to delete the entire linked list */
void deleteList(Node** head_ref)
{

	/* deref head_ref to get the real head */
	Node* current = *head_ref;
	Node* next = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current); 
		current = next;
	}

	/* deref head_ref to affect the real head back
		in the caller. */
	*head_ref = NULL; // basially removing all the elements
}

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

/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	/* Use push() to construct below list
	1->12->1->4->1 */
	push(&head, 1);
	push(&head, 4);
	push(&head, 1);
	push(&head, 12);
	push(&head, 1);

	cout << "Deleting linked list";
	deleteList(&head);

	cout << "\nLinked list deleted";
}

// This is code is contributed by rathbhupendra
