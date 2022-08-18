/*
Modify Linked List-1
Easy

https://practice.geeksforgeeks.org/problems/modify-linked-list-1/1?page=3&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a singly linked list containing N nodes. Modify the value of the first half nodes such that 1st node's 
new value is equal to the value of the last node minus the first node's current value, 2nd node's new value is 
equal to the second last nodes value minus 2nd nodes current value, likewise for first half nodes. Replace 
the second half nodes with the first half nodes with the initial values of the first half nodes. If n is 
odd then the value of the middle node remains unchanged.

Note: Input in the linked list is like a new node will be entered at the head position (1st position). So, 
basically the linked list is filled in a reverse manner.

Example:

Input:
2
5
10 4 5 3 6
6
2 9 8 12 7 10

Output:
-4 -1 5 4 10
8 -2 4 8 9 2

Explanation:
Testcase 1: After modifying the linked list as required,
we have a new linked list containing the elements as
-4, -1, 5, 4, 10.
Input:

First line consists of T test cases. First line of every test case consists of N, denoting the number of nodes. 
Second line of every test case consists of Node of linked list.

Output:
Single line output, return the head of the modified linked list.

YourTask:
The task is to complete the function modifyTheList() which should modify the list as required.

Constraints:
1 <= T <= 200
1 <= N <= 100

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

//Function to reverse a linked list.
struct Node* reverse(struct Node *head)
{
        // code here
        // return head of reversed list
        struct Node* temp= head;
        struct Node* prev=temp;
        struct Node* next=temp->next;
        
        temp->next = NULL;
        
        while (temp!=NULL && next != NULL){
            temp = next;
            if (temp->next != NULL){
                
                next = temp->next;
            }
            else{
                next = NULL;
            }
            temp ->next = prev;
            prev = temp;
            
        }
        return temp;
}
  

struct Node* modifyTheList(struct Node *root)
{
    // your code goes here
    Node *head= root;
    Node *fast = root;
    Node *slow =root;
    
    while(fast!= NULL && fast->next!=NULL){
        slow= slow->next;
        fast = fast->next->next;// (fast->next != NULL) ? fast->next->next : fast->next;
    }
    // cout << slow->data<< endl;
    bool even=false;
    if (fast == NULL){
        even = true;
    }
    
    Node *temp;
    temp = slow->next;
    slow->next = NULL;

    
    temp = reverse (temp); // reversing from middle
    Node *t = temp;
    fast = head;
    // printList(fast);
    Node *c;
    int d;
    while (temp!= NULL && fast!=NULL && fast->next!= NULL){
        d= temp->data;
        fast->data = fast->data - temp->data;
        temp->data= d;
        // cout << d <<"\t"<< fast->data<< endl;
        temp= temp->next;
        fast= fast->next;
    }
    // printList(t);
    temp = reverse (t);
    // printList(t);
    fast->next = temp;
    
    
    return root;
    
}