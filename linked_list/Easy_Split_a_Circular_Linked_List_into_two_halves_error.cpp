/*
Split a Circular Linked List into two halves
Easy

https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1?page=2&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a Cirular Linked List of size N, split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.

 

Example 1:

Input:
Circular LinkedList: 1->5->7
Output:
1 5
7
 

Example 2:

Input:
Circular LinkedList: 2->6->1->5
Output:
2 6
1 5

Your Task:
Your task is to complete the given function splitList(), which takes 3 input parameters: The address of the head of the linked list, addresses of the head of the first and second halved resultant lists and Set the head1_ref and head2_ref to the first resultant list and second resultant list respectively.


Expected Time Complexity: O(N)
Expected Auxilliary Space: O(1)


Constraints:
1 <= N <= 100

*/

/*
Algorithm

1. Find the middle element pointer through tortise and hare approach
2. point slow->next to head and then traverse to next of slow pointer and make it as *head2 (in opposite sequence)
3. traverse to the end of the list where the loop meets head and then make that point to *head2. 

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


//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1, Node **head2)
{
    // your code goes here
    (*head1) = head;
    Node *fast=head->next;
    Node *slow = head;
    Node *prev=head;
    while(fast != head && fast->next!=head ){
        prev= fast->next;
        fast = fast ->next->next;
        slow= slow->next; // will point to middle element always
    }

    (*head2) = slow->next;
    slow->next = (*head1);

    slow = (*head2);
    while (slow->next!=head){
        slow = slow->next;
    }
    slow->next = (*head2);

}
