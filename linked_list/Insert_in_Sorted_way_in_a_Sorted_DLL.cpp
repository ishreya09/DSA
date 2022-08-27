// Segmentation error
/*
Insert in Sorted way in a Sorted DLL
Easy

https://practice.geeksforgeeks.org/problems/insert-in-sorted-way-in-a-sorted-dll/1?page=3&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a sorted doubly linked list and an element X, your need to insert the element X into 
correct position in the sorted DLL.

Example:

Input:
LinkedList:

X = 9
Output:

Your Task:
You only need to complete the function sortedInsert() that takes head reference 
and x as arguments and returns the head of the modified list. The printing and 
checking tasks are done by the driver code.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= Number of nodes <= 103

*/

/*
Algorithm

1. Create a new node temp and set the data and set next and prev pointers to NULL
2. if head is NULL, we insert at head
3. If head is not null, we check if head's data > data passed
If true:
	then we insert at head by making the head->prev point to temp and temp->next to head
	and then storing temp as head.
If false:
	then we traverse to the list using start pointer and traverse till the start->next->data<x
	and then stop there
	We get the prev node now, we changetemp->next to start->next and start->next = temp and temp ->prev = start 
	then we change start to temp->next and set start->prev= temp. Do the last step only after checking
	if start != NULL

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// function should insert a new node in sorted way in
// a sorted doubly linked list
//Return the head after insertion
Node* sortedInsert(Node * head, int x)
{
	// Code here
	// initialize a new node temp
	Node *temp;
	temp->data = x;
	temp->prev=temp->next= NULL;
	
	if(head== NULL){
	    head= temp;
	}
	else if (head->data > x ){ // inserion at head
	    temp->next = head;
	    head->prev= temp;
	    head= temp;
	}
	else{
	    Node *start =head;
	    while(start->next!= NULL && start->next->data < x){
	        start = start->next;
	    }
	    temp->prev = start;
	    temp->next = start->next;
	    start->next = temp;
	    start= temp->next;
	    if (start != NULL)
	        start->prev = temp;
	   
	}
	return head;
}