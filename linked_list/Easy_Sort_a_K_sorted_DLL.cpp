/*
Sort a k sorted doubly linked list
Easy

https://practice.geeksforgeeks.org/problems/sort-a-k-sorted-doubly-linked-list/1?page=2&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given a doubly linked list containing N nodes. The problem is to sort the given doubly linked list. 

Example 1:

Input: 5 <-> 6 <-> 3 <-> 4 <-> 1 <-> 2
K = 2
Output: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
Explanation: 
After sorting the given 2 sorted
list is 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6.
Example 2:

Input: 5 <-> 6 <-> 7 <-> 3 <-> 4 <-> 4
K = 3
Output: 3 <-> 4 <-> 4 <-> 5 <-> 6 <-> 7
Explanation: 
After sorting the given 3 sorted
list is 3 <-> 4 <-> 4 <-> 5 <-> 6 <-> 7.
Your Task:
You don't need to read input or print anything. Your task is to complete the function sortAKSortedDLL() which takes head node of the doubly linked list as input parameter and returns the head node after sorting.


Expected Time Complexity: O(N*logK)
Expected Auxiliary Space: O(k)


Constraints:
1 <= Number of nodes <= 10^5
1 <= Data of a node <= 10^5
*/

/*
Algorithm

1. Seperate the first k nodes from head and set the last node as NULL and 
make a recursive function which calls after that last node
2. If head becomes Null or head->next==NULL - then we return or it fails to complete k nodes then we return
3. Store the returned list in b.
4. Do sortedMerge of b and head and then return head.

*/

#include<bits/stdc++.h>
using namespace std;

class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution
{
public:
    DLLNode *sortedMerge(DLLNode *h1, DLLNode *h2){
        DLLNode *a=h1,*b=h2;
        if (a==NULL){
            return b;
        }
        if(b==NULL){
            return a;
        }
        if (b->data<a->data){
            DLLNode *t=b->next;
            if (t) t->prev=NULL;
            b->next=a; // insert at head
            a->prev= b;
            h1=b;
            b=t;
            a= h1;
        }
        while(a!=NULL && a->next!=NULL && b!=NULL){
            if (a->next->data>b->data){
                DLLNode *t=b->next;
                if (t ) t->prev=NULL;
                b->next = a->next;
                if(a->next){
                    a->next->prev= b;
                }
                a->next= b;
                b=t;
            }
            a=a->next;
        }
        if (b!=NULL){
            a->next=b;
            b->prev= a;
        }
        return h1;
    }
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k)
    {
        // code here
        if(head==NULL){
            return head;
        }
        int t=k;
        DLLNode* a=head;
        while(--t==1){
            if(a!=NULL && a->next!=NULL)
                a=a->next;
            else
                return head;
        }
        DLLNode *b=sortAKSortedDLL(a->next,k);
        if(a)
            a->next=NULL;
        // Do sorted merge of a and b
        head= sortedMerge(head,b);
        return head;
    }
};