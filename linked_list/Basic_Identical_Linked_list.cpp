/*
Identical Linked Lists
Basic

Given two Singly Linked List of N and M nodes respectively. The task is to check whether two linked lists are identical or not. 
Two Linked Lists are identical when they have same data and with same arrangement too.

Example 1:

Input:
LinkedList1: 1->2->3->4->5->6
LinkedList2: 99->59->42->20
Output: Not identical 
Example 2:

Input:
LinkedList1: 1->2->3->4->5
LinkedList2: 1->2->3->4->5
Output: Identical
 
Your Task:
The task is to complete the function areIdentical() which takes the head of both linked lists as arguments and returns True or False.

Constraints:
1 <= N <= 103

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

*/

/*
Algorithm

1. traverse both the linked list simentaneously and compare
2. Also check if both are null simentaneously- If they are null simentaneously, only then they are identical

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


//Function to check whether two linked lists are identical or not. 
bool areIdentical(struct Node *head1, struct Node *head2)
{
    // Code here
    while(head1!=NULL && head2!=NULL){
        if(head1->data != head2->data){
            return false;
        }
        head1= head1->next;
        head2= head2->next;
        
    }
    if(head1!=NULL || head2!=NULL){
        return false;
    }
    else{
        return true;
    }
}