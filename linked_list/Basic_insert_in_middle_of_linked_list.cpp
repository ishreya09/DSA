/*
Insert in Middle of Linked List
Basic

https://practice.geeksforgeeks.org/problems/insert-in-middle-of-linked-list/1?page=2&difficulty[]=-2&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a linked list of size N and a key. The task is to insert the key in the middle of the linked list.

Example 1:

Input:
LinkedList = 1->2->4
key = 3
Output: 1 2 3 4
Explanation: The new element is inserted
after the current middle element in the
linked list.
Example 2:

Input:
LinkedList = 10->20->40->50
key = 30
Output: 10 20 30 40 50
Explanation: The new element is inserted
after the current middle element in the
linked list and Hence, the output is
10 20 30 40 50.
 

Your Task:
The task is to complete the function insertInMiddle() which takes head reference and 
element to be inserted as the arguments. The printing is done automatically by the driver code.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 104


*/

/*
Algorithm

Based on the tortoise and hare algorithm which uses two pointers, 
one known as slow and the other known as fast. This algorithm helps 
in finding the middle node of the linked list. It is explained in the 
front and black split procedure of this post. Now, you can insert the 
new node after the middle node obtained from the above process. 
This approach requires only a single traversal of the list. 

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x){
        data =x;
        next = NULL;
    }
};


//Function to insert a node in the middle of the linked list.
Node* insertInMiddle(Node* head, int x)
{
	// Code here
	if (head==NULL){
	    Node* temp = new Node(x);
	    head=temp;
        return head;
    }
	Node *fast=head->next;
	Node *slow = head; 
	Node *prev=head;
	while (fast != NULL && fast ->next != NULL){
	    slow = slow->next;
	    fast = fast->next->next;
	    
	}
	Node *temp = new Node (x);

	
	temp->next = slow->next;
	slow->next = temp; 
	
	return head;
	
}