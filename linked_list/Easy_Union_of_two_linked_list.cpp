/*
Union of Two Linked Lists
Easy

https://practice.geeksforgeeks.org/problems/union-of-two-linked-list/1?page=1&status[]=unsolved&category[]=Linked%20List&sortBy=submissions

Given two linked lists, your task is to complete the function makeUnion(), that returns the union list of two linked lists. 
This union list should include all the distinct elements only and it should be sorted in ascending order.

Example 1:

Input:
L1 = 9->6->4->2->3->8
L2 = 1->2->8->6->2
Output: 
1 2 3 4 6 8 9
Explaination: 
All the distinct numbers from two lists, when sorted forms the list in the output. 
Example 2:

Input:
L1 = 1->5->1->2->2->5
L2 = 4->5->6->7->1
Output: 
1 2 4 5 6 7
Explaination: 
All the distinct numbers from two lists, when sorted forms the list in the output.
Your Task:
The task is to complete the function makeUnion() which makes the union of the given two lists and returns the head of the new list.

Expected Time Complexity: O((N+M)*Log(N+M))
Expected Auxiliary Space: O(N+M)

Constraints:
1<=N,M<=10^4

*/

/*
Algorithm

1. Make a single set and add elements of both the linked list in the set
2. Take another head node and make a linked list as u traverse through the set.
3. Return the head node of the new linked list

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
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        set<int> s;
        while(head1!=NULL){
            s.insert(head1->data);
            head1=head1->next;
        }
        while(head2!=NULL){
            s.insert(head2->data);
            head2=head2->next;
        }
        
        struct Node* head=NULL,*last=NULL;
        for (auto i= s.begin();i!=s.end();i++){
            Node* temp = new Node(*i);
            if(head==NULL){
                head=temp;
                last=temp;
            }
            else{
                last->next=temp;
                last=temp;
            }
        }
        return head;
    }
};