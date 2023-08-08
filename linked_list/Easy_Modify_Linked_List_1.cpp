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

1. find the middle pointer and keep a check on if the list is having length even or odd with help of slow, fast 
and prev pointers.
(
    TO CHECK IF LIST IS EVEN OR ODD
        1. GO with the same algorithm of fast and slow pointer where fast pointer moves 2 places and 
        slow pointer moves one place at a given time.
        2. iF the list is even, the fast pointer will always end up as NULL and if it's odd, 
        then fast->next will be NULL
)
2. Make another pointer temp and check if the list is having even elements or odd
If number of elements is even, set temp as slow pointer and make prev->next = NULL
Otherwise set temp to slow->next and set slow->next = NULL

3. reverse temp and store head in another pointer t, and then traverse the linked list again by setting fast = root again
and do the substraction which is required

4. reverse the temp again using pointer t and then if prev->next was set to null, then set prev->next == NULL 
else slow->next == NULL

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
    if (root==NULL || root->next ==NULL){
        return root;
    }
    
    Node *head= root;
    Node *fast = root;
    Node *slow =root;
    Node *prev =root;
    
    while(fast!= NULL && fast->next!=NULL){
        prev=slow;
        slow= slow->next;
        fast = fast->next->next;
    }
    
    bool even=false;
    if (fast == NULL){
        even = true;
    }
    Node *temp;
    
    if(even){
        temp= slow;
        prev->next= NULL;
    }
    else{
        temp = slow->next;
        slow->next=NULL;
    }
    temp = reverse (temp);
    Node *t = temp;
    
    fast = root;
    while (temp!= NULL && fast!= NULL ){
        fast->data = fast->data- temp->data;
        
        fast= fast->next;
        temp=temp->next;
    }
    t= reverse (t);
    
    if(prev->next == NULL ){
        prev->next = t; 
    }
    else if(slow->next ==NULL){
        slow->next =t;
    }
    
    
    return root;
    
}