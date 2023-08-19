/*
Delete nodes having greater value on right
Medium

https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1?page=1&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given a singly linked list, remove all the nodes which have a greater value on their right side.

Example 1:

Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on the following nodes. So, after deleting
them, the linked list would like be 15,
11, 6, 3.
Example 2:

Input:
LinkedList = 10->20->30->40->50->60
Output: 60
Explanation: All the nodes except the last
node has a greater value node on its right,
so all the nodes except the last node must
be removed.
Your Task:
The task is to complete the function compute() which should modify the 
list as required and return the head of the modified linked list. The printing is done by the driver code,

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ size of linked list ≤ 105
1 ≤ element of linked list ≤ 105
Note: Try to solve the problem without using any extra space.
*/

/*
Algorithm

1. Traverse till the end using recursion and if head->next==NULL, return head
2. Store the returned value in t. t ptr will act as next ptr
3. If t->data > head-> data - then delete head by storing the value of t->data in head and then
deleting t. 
4. return head to get the rest of the list

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


class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node *t= compute(head->next);
        if (head->data < t->data){
            head->data=t->data;
            head->next=t->next;
        }
        return head;
    }
    
};