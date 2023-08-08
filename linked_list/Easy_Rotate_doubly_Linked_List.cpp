/*
Rotate doubly Linked List
Easy

https://practice.geeksforgeeks.org/problems/rotate-doubly-linked-list-by-p-nodes/1?page=3&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a doubly linked list, rotate the linked list counter-clockwise by P nodes. Here P is a given 
positive integer and is smaller than the count of nodes(N) in a linked list.

Example 1:

Input: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 , P = 2
Output: 3 <-> 4 <-> 5 <-> 6 <-> 1 <-> 2
Explanation: Doubly linked list after rotating
2 nodes is: 3 4 5 6 1 2.
Example 2:

Input: 3 <-> 4 <-> 5 <-> 1 ,P = 3
Output: 1<-> 3 <-> 4 <-> 5
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function rotateDLL() 
which takes head node of the linked list and an integer P as input parameters and returns the head 
node after rotating the linked list by P nodes.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
2 <= N <= 100
1 <= P <  N

*/

/*
Algorithm

1. To rotate the Doubly linked list, we need to change next of Nth node to NULL, 
next of last node to previous head node, and prev of head node to last node and 
finally change head to (N+1)th node and prev of new head node to NULL 
(Prev of Head node in doubly linked list is NULL)
2. So we need to get hold of three nodes: Nth node, (N+1)th node and last node. 
3. Traverse the list from the beginning and stop at Nth node. Store pointer to Nth node. We can get (N+1)th node 
using NthNode->next. Keep traversing till the end and store the pointer to the last node also. 
4. Finally, change pointers as stated above and at Last Print Rotated List

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;

    Node(int x){
        data =x;
        next = NULL;
        prev= NULL;
    }
};


class Solution {
public:
    Node *rotateDLL(Node *start,int p)
    {
        //Add your code here
        int c=1;
        Node *head = start;
        Node *temp = start;     
        Node *req= NULL;
        while(temp->next!= NULL){
            if (c==p){
                req=temp;
            }
            c++;
            temp =temp->next;
        }
        
        start = req->next;
        start->prev =NULL;
        req->next = NULL;
        temp->next = head;
        head->prev= temp;
        
        return start;
    }
    
};