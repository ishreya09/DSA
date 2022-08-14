/*
Delete Middle of Linked List
Easy

https://practice.geeksforgeeks.org/problems/delete-middle-of-linked-list/1?page=1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a singly linked list, delete middle of the linked list. For example, 
if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5.
If there are even nodes, then there would be two middle nodes, we need to delete the second middle element. 
For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.
If the input linked list is NULL or has 1 node, then it should return NULL

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 1 2 4 5
Example 2:

Input:
LinkedList: 2->4->6->7->5->1
Output: 2 4 6 5 1

Your Task:
The task is to complete the function deleteMid() which should delete the middle element 
from the linked list and return the head of the modified linked list. If the linked list is 
empty then it should return NULL.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 1000
1 <= value <= 1000

*/

/*
Algorithm

1. Use fast, slow and prev pointer. We use prev pointer to delete the node
2. We can also copy the next node's data to the present slow node and delete slow->next node (deleting without head pointer)
(as we only have to delete the middle element and never the last element)
3. We use the logic to delete the slow node then (either of the above logic - using prev or deleting without head pointer)

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


// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head)
{
    // Your Code Here
    if (head==NULL || head->next==NULL){
        return NULL;
    }
    
    Node *fast=head;
    Node *slow = head;
    Node *prev= head;
    
    while (fast != NULL && fast->next!= NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // we have middle element in slow
    prev->next = slow->next;
    delete (slow);
    
    return head;
    
}
