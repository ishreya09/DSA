// Alternate method to declare the class in order to minimize the memory allocation work



#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;

	node(int value)	 // A constructor is called here
    // no need for newNode function like C here
	{					
		data = value;	 // it automatic assigns the value to the data
		next = NULL;	 // next pointer is pointed to NULL
	}
};





// function to insert a element at head position
void insertathead(node*& head, int val) // what is this *& means and what it means in terms of pointers? 
// I feel I am bit uncomfortable whenever I see & 
{
	node* n = new node(val);
	n->next = head; // no need to use (*head ) like in C? 
	head = n;
}





// function to insert a element at a specified position
void insertafter(node* head, int key, int val)
{
    // key is the value in the linked list after which we want to insert
	node* n = new node(val);
	if (key == head->data) { // insertion in the begining
		n->next = head->next;
		head->next = n;
		return;
	}

	node* temp = head; // creating a temp variable so that we don't lose head
	while (temp->data != key) { // traversing through the list till we find the key
		temp = temp->next;
		if (temp == NULL) {
			return;
		}
	}
	n->next = temp->next; 
	temp->next = n;
}





// function to insert a element at the end
void insertattail(node*& head, int val)
{
	node* n = new node(val);
	if (head == NULL) { // is head NULL if we do not assign any data to it?
		head = n;
		return;
	}

	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = n;
}





// function to print the singly linked list
void print(node*& head) // why to use *& if we can simply use *head?
{
	node* temp = head; 

	while (temp != NULL) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}




// main function
int main()
{
	node* head = NULL;	 //declaring an empty linked list

	insertathead(head, 1);
	insertathead(head, 2);
	cout << "After insertion at head: ";
	print(head);
	cout << endl;

	insertattail(head, 4); //we not have to worry about where to put & and where not
    // How is it understanding though that we need data in a certain format - in terms of pointers?
	insertattail(head, 5);
	cout << "After insertion at tail: ";
	print(head);
	cout << endl;

	insertafter(head, 1, 2);
	insertafter(head, 5, 6);
	cout << "After insertion at a given position: ";
	print(head);
	cout << endl;

	return 0;
}

// contributed by divyanshmishra101010
