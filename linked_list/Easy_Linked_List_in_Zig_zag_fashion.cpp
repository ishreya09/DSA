/*
Linked List in Zig-Zag fashion
Easy

https://practice.geeksforgeeks.org/problems/linked-list-in-zig-zag-fashion/1?page=1&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given a Linked list, rearrange it such that converted list should be of the form a < b > c < d > e < f .. 
where a, b, c are consecutive data node of linked list and such that the order of linked list is sustained.
For example: In 11 15 20 5 10 we consider only 11 20 5 15 10 because it satisfies the above condition and 
the order of linked list. 5 20 11 15 10 is not considered as it does not follow the order of linked list.

To maintain the order, keep swapping the adjacent nodes of the linked list (whenever required) to get 
the desired output.  

Example 1:

Input:
LinkedList: 1->2->3->4 
Output: 1 3 2 4
Example 2:

Input:
LinkedList: 11->15->20->5->10
Output: 11 20 5 15 10
Explanation: In the given linked list,
after arranging them as 11 < 20 > 5
< 15 > 10 in the pattern as asked above.
Your Task:
The task is to complete the function zigZag() which should reorder the list as required and 
return the head of the linked list.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= size of linked list(a) <= 1000

*/

/*
Algorithm

1. If head contains only NULL or one node- return head
2.  If head contains only 2 nodes - check if head->data> head->next->data- swap and return head
3. The problem is consistent from 3 nodes onwards. 
    a) Take 4 pointer - prev = head, cur= head->next, next=cur->next and last=NULL. last ptr is supposed to be
    the previous node of prev pointer. 
    b) if a<b>c<d>e<f>.. so on is the list - prev will always be a,c,e and so on
    cur will always be b,d,f and so on, we can notice last will be equal to previous value of cur.
    next will always be c,e, and so on.
    c) if(prev->data > cur->data) - swap
    if(cur->data< next->data) - swap
    d) if next==NULL - it becomes necessary that we check prev and cur's condition and then return head.
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
    Node *zigZag(Node* head)
    {
     // your code goes here
     if(head==NULL || head->next==NULL){ // only no node or one node
        return head;
     }
     if (head->next!=NULL && head->next->next==NULL){ // two nodes
         if(head->data> head->next->data){
             Node *t=head->next;
             head->next=NULL;
             t->next=head;
             head=t;
         }
         return head;
     }
     // three nodes
     Node *last=NULL; //prev's previous
     Node *prev=head;
     Node *cur=head->next;
     Node *next=cur->next;
     while (cur->next!=NULL){ 
         // cur will always be the node such that a<b>c<d>e - 
         // so cur is always b,then d.. and so on 
         if(prev->data>cur->data){
             if(prev==head){
                prev->next=next;
                cur->next=prev;
                head=cur;
                // fix the pointers
                prev=head;
                cur=head->next;
             }
             else if(last!=NULL){
                 prev->next=next;
                 last->next=cur;
                 cur->next=prev;
                 // fix the pointers
                 Node *t=prev;
                 prev=cur;
                 cur=t;
             }
         }
         if(cur->data<next->data){
             prev->next=next;
             cur->next=next->next;
             next->next=cur;
             // fix the ptrs
             Node *t=next;
             next=cur;
             cur=t;
             
         }
         last=cur;
         prev=next;
         if(next->next!=NULL){
             cur=next->next;
             next=cur->next;
         }
         else{
             break;
         }
     }
     if (cur->next==NULL){
         if(prev->data>cur->data){
             prev->next=next;
             if (last!=NULL){
                 last->next=cur;
                 
             }
             cur->next=prev;
         }
     }
     
     return head;
     
    }
};