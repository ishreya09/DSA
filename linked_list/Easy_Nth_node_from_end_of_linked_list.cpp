/*
Nth node from end of linked list
Easy

https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1?page=1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

Example 1:

Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
Explanation: In the first example, there
are 9 nodes in linked list and we need
to find 2nd node from end. 2nd node
from end os 8.  
Example 2:

Input:
N = 5
LinkedList: 10->5->100->5
Output: -1
Explanation: In the second example, there
are 4 nodes in the linked list and we
need to find 5th from the end. Since 'n'
is more than the number of nodes in the
linked list, the output is -1.
Your Task:
The task is to complete the function getNthFromLast() which takes two arguments: 
reference to head and N and you need to return Nth from the end or -1 in case node doesn't exist..

Note:
Try to solve in single traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= L <= 106
1 <= N <= 106



*/

/*
Algorithm

1. We use two pointers again : here a main pointer and a temporary pointer
2. Move the temporary pointer counting from 1 to nth position and then start moving the main pointer along with it then
3. Continue to move the main pointer till temp pointer reaches the end of the list - 
The position of main pointer is the nth element from the last.

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

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       // Your code here
       if (head==NULL){
           return -1;
       }
       
       int count=0;
       Node* start=head;
       Node* temp = head;
       
       for (int i=1; i<n; i++){
           temp = temp->next;
           count++;
       }
       if (temp!=NULL){
           while (temp->next != NULL){
               temp=temp->next;
               start= start->next;
               count++;
           }
           return start->data;
       }
       else {
           return -1;
       }
       
}
