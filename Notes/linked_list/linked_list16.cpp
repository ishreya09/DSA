/*

Program for n’th node from the end of a Linked List

Method 2 (Use two pointers) 
Maintain two pointers – reference pointer and main pointer. Initialize 
both reference and main pointers to head. First, move the reference pointer 
to n nodes from head. Now move both pointers one by one until the reference 
pointer reaches the end. Now the main pointer will point to nth node from the end. 
Return the main pointer.

Time Complexity: O(n) where n is the length of linked list.

Auxiliary Space: O(1)
*/

// C++ program to find n-th node
// from the end of the linked list.

// index is starting with 0 from both ends

#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node* next;
	node(int val)
	{
		data = val;
		next = NULL;
	}
};

struct llist { // using struct as class??

	node* head;
	llist() { head = NULL; } // constructor?

	// insert operation at the beginning of the list.
	void insertAtBegin(int val) // methods of structure
	{
		node* newNode = new node(val);
		newNode->next = head;
		head = newNode;
	}

	// finding n-th node from the end.
	void nthFromEnd(int n)
	{
		// create two pointers main_ptr and ref_ptr
		// initially pointing to head.
		node* main_ptr = head;
		node* ref_ptr = head;

		// if list is empty, return
		if (head == NULL) {
			cout << "List is empty" << endl;
			return;
		}

		// move ref_ptr to the n-th node from beginning.
		for (int i = 1; i < n; i++) {
			ref_ptr = ref_ptr->next;
			if (ref_ptr == NULL) {
				cout << n
					<< " is greater than no. of nodes in "
						"the list"
					<< endl;
				return;
			}
		}

		// move ref_ptr and main_ptr by one node until
		// ref_ptr reaches end of the list. - so then it will be already NULL
		while (ref_ptr != NULL && ref_ptr->next != NULL) { // ref_ptr->next !=NULL is for current thing
			ref_ptr = ref_ptr->next;
			main_ptr = main_ptr->next;
		}
		cout << "Node no. " << n
			<< " from end is: " << main_ptr->data << endl;
	}

	void displaylist()
	{
		node* temp = head;
		while (temp != NULL) {
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
};

int main()
{
	llist ll;

	for (int i = 60; i >= 10; i -= 10)
		ll.insertAtBegin(i);

	ll.displaylist();

	for (int i = 1; i <= 7; i++)
		ll.nthFromEnd(i);

	return 0;
}

// This code is contributed by sandeepkrsuman.


