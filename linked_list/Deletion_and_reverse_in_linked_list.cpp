/*
Deletion and Reverse in Linked List
Easy

https://practice.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1?page=3&difficulty[]=-2&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a Circular Linked List of size N. The task is to delete the given node (excluding the first and last node) in the circular linked list and then print the reverse of the circular linked list.

 

Example 1:


Input:
5
2 5 7 8 10
8

Output:
10 7 5 2
Explanation: 
After deleting 8 from the given circular linked 
list, it has elements as 2, 5, 7, 10. Now, 
reversing this list will result in 10, 7, 5, 2.
 

Example 2:

Input:
4
1 7 8 10
8

Output:
10 7 1

Explanation:
After deleting 8 from the given circular linked 
list, it has elements as 1, 7,10. Now, reversing 
this list will result in 10, 7, 1.
 

Your Task:
You don't need to read, input, or print anything. Your task is to complete the function deleteNode( ), 
which takes Node head, and integer key as input parameters, and delete the node with data key. 
Also Complete function reverse() which reverses the linked list.

 

Constraints:
1 <= T <= 100
1 <= n <= 100
1 <= data <= 100
*/

/*
Algorithm

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

/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key)
{

    // Your code goes here
    Node *temp=(*head)->next;
    if (temp->data==key){
        (*head)->next=temp->next;
    }
    while (temp->next !=(*head)){
        if (temp->next->data==key){
            temp->next = temp->next->next;
            break;
        }
        temp=temp->next;
    }

}

/* Function to reverse the linked list */
 void reverse(struct Node** head)
{
    // Your code goes here
    Node *prev;
    Node *temp= (*head)->next;
    Node *p=temp->next;
    temp->next=(*head);
    prev=temp;
    temp=p;
    while (temp->next!=(*head)){
        p=temp->next;
        temp->next  = prev;
        prev=temp;
        temp=p;
    }
    // last node
    temp->next=prev;
    (*head)->next=temp;
    (*head)=temp;
}