/*
Reverse a Linked List in groups of given size
Medium

https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1?page=1&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) 
in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, 
should be considered as a group and must be reversed (See Example 2 for clarification).

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.
Example 2:

Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4 
Explanation: 
The first 3 elements are 1,2,3 are reversed 
first and then elements 4,5 are reversed.Hence, 
the resultant linked list is 3->2->1->5->4.
Your Task:
You don't need to read input or print anything. Your task is to complete the function reverse() 
which should reverse the linked list in group of size k and return the head of the modified linked list.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 105
1 <= k <= N

*/

/*
Algorithm


1. Reverse the first sub-list of size k. While reversing keep track of the next node and previous node. 
2. Let the pointer to the next node be next and pointer to the previous node be prev. 
3. head->next = reverse(next, k) ( Recursively call for rest of the list and link the two sub-lists )
4.  Return prev ( prev becomes the new head of the list )

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


/* Reverses the linked list in groups
of size k and returns the pointer
to the new head node. */
Node* reverse(Node* head, int k)
{
    // base case
    if (!head)
        return NULL;
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
  
    /*reverse first k nodes of the linked list using iterative method*/
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
  
    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if (next != NULL)
        head->next = reverse(next, k);
  
    /* prev is new head of the input list */
    return prev;
}