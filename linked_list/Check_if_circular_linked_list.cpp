/*
Check If Circular Linked List
Basic

https://practice.geeksforgeeks.org/problems/circular-linked-list/1?page=1&difficulty[]=-2&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given head, the head of a singly linked list, find if the linked list is circular or not. 
A linked list is called circular if it not NULL terminated and all nodes are connected in the form of a cycle. 
An empty linked list is considered as circular.

Note: The linked list does not contains any inner loop.

Example 1:

Input:
LinkedList: 1->2->3->4->5
(the first and last node is connected,
i.e. 5 --> 1)
Output: 1
Example 2:

Input:
LinkedList: 2->4->6->7->5->1
Output: 0
Your Task:
The task is to complete the function isCircular() which checks if the given linked list is circular or not. 
It should return true or false accordingly. (the driver code prints 1 if the returned values is true, otherwise 0)

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <=Number of nodes<= 100

*/

/*
Algorithm

1. if head= NULL, its surely not circular linked list
2. Create a temp pointer pointing to head->next and if it is not equal to NULL and if its not equal to head, we traverse through 
the linked list
3. return if temp==head

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


/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
   // Your code here
   if (head==NULL){
       return true;
   }
   Node *temp=head->next;

   while (temp != NULL && temp != head){
        
       temp= temp->next;
   }
   return (temp==head);
}

