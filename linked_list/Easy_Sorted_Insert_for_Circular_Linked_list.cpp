/*
Sorted insert for circular linked list
Easy

https://practice.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1?page=2&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions




Given a sorted circular linked list, the task is to insert a new node in this 
circular list so that it remains a sorted circular linked list.

Example 1:

Input:
LinkedList = 1->2->4
(the first and last node is connected,
i.e. 4 --> 1)
data = 2
Output: 1 2 2 4
Example 2:

Input:
LinkedList = 1->4->7->9
(the first and last node is connected,
i.e. 9 --> 1)
data = 5
Output: 1 4 5 7 9
Your Task:
The task is to complete the function sortedInsert() which should insert the new node 
into the given circular linked list and return the head of the linkedlist.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
0 <= N <= 105
*/

/*
Algorithm

There will be 3 cases in this question:

    Case 1: head is NULL
                  In this case, create a node with data x and store its address at head_ref.

    Case 2: data of head node is greater than new node's data
                  In this case as well, new node will become head of list and previous head will be second node. 
                  Also take care of the last node's next. Remember that last node will be pointing to new head's next 
                  pointer in this case.

    Case 3: if none of the prev is true
                  Locate a node whose data is greater than new data and insert new node right before it. 
                  In case no such node is found in the list, append new node at the end.

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

// This function should return head of
// the modified list
class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       //Your code here
       // insertion at head
        Node *temp= new Node (data);
        if (head==NULL){
            head= temp;
            temp->next = head;
        }
        else if(head->data > data){
            // insertion at head 
            temp->next = head;
            head= temp;
            // change the last node's next to head as well
            Node *last=head->next;
            while(last->next != head->next){
                last = last->next;
            }
            last->next = head;
        }
        else{
            Node *cur=head;
            while(cur->next!=head && cur->next->data < data){
                cur= cur->next;
            }
            temp->next = cur->next;
            cur->next= temp;
        }
        return head;
    }
};