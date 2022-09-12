/*
Find the middle of a given linked list


https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/

Method 2: Traverse linked list using two-pointers. Move one pointer by one 
and the other pointers by two. When the fast pointer reaches the end, the slow 
pointer will reach the middle of the linked list.

Time Complexity: O(N), As we are traversing the list only once.
Auxiliary Space: O(1), As constant extra space is used.
*/

// C++ program for the above approach

#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};

class NodeOperation{
public:

	// Function to add a new node
	void pushNode(class Node** head_ref,int data_val){
	
		// Allocate node
		class Node *new_node = new Node();
		
		// Put in the data
		new_node->data = data_val;
		
		// Link the old list off the new node
		new_node->next = *head_ref;
		
		// move the head to point to the new node
		*head_ref = new_node;
	}
	
	// A utility function to print a given linked list
	void printNode(class Node *head){
		while(head != NULL){
			cout <<head->data << "->";
			head = head->next;
		}
		cout << "NULL" << endl;
	}
	
	void printMiddle(class Node *head){
		struct Node *slow_ptr = head;
		struct Node *fast_ptr = head;

		if (head!=NULL)
		{
			while (fast_ptr != NULL && fast_ptr->next != NULL)
			{
				fast_ptr = fast_ptr->next->next; // moving ahead with 2 nodes at once
				slow_ptr = slow_ptr->next; // moving ahead with one node at a time
			}
			cout << "The middle element is [" << slow_ptr->data << "]" << endl; 
            // when fast_ptr reaches the end of the list, we would be in the middle for slow ptr
            // this technique can be used to do n partitions of a linked list
		}
	}
};

// Driver Code
int main(){
	class Node *head = NULL;
	class NodeOperation *temp = new NodeOperation();
	for(int i=5; i>0; i--){
		temp->pushNode(&head, i);
		temp->printNode(head);
		temp->printMiddle(head);
	}
	return 0;
}
