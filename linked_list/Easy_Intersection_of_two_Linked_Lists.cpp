/*
Intersection of Two Linked Lists
Easy

https://practice.geeksforgeeks.org/problems/intersection-of-two-linked-list/1?page=1&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given two linked lists, the task is to complete the function findIntersection(), that returns the 
intersection of two linked lists. Each of the two linked list contains distinct node values.

Example 1:

Input:
LinkedList1: 9->6->4->2->3->8
LinkedList2: 1->2->8->6
Output: 6 2 8
Your Task:
You task is to complete the function findIntersection() which takes the heads of the 2 input linked lists 
as parameter and returns the head of intersection list. Returned list will be automatically printed by driver code.
Note: The order of nodes in this list should be same as the order in which those particular nodes appear in 
input list 1.

Constraints:
1 <= n,m <= 104

Expected time complexity: O(m+n)
Expected auxiliary space: O(m+n)

*/

/*
Algorithm

1. For In place intersection of two lists - take the 2nd list whose order doesn't matter and add it to a map
2. Iterate through the other list whose order matters and check if it's present in the map or not
If present- then add the head to a new linked list and keep a track of last pointer so that insertion TC is O(1)
If not- move on to next element
3. Return the head.
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

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        
        map<int,int> f;
        Node *a=head1,*b=head2;
        while (b!=NULL){
            f[b->data]= 1;
            b=b->next;
        }
        Node *head=NULL;
        Node * last = NULL;
        
        while (a!=NULL){
            if(f[a->data]==1){ // present in b too
                Node *t= new Node(a->data);
                if(head==NULL){
                    head=t;
                    last=t;
                }
                else{
                    last->next=t;
                    last=t;
                }
                
            }
            a= a->next;
        }
        
        
        return head;
    }
};