/*
Reverse a linked list
Easy

https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1?page=1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a linked list of N nodes. The task is to reverse this list.

Example 1:

Input:
LinkedList: 1->2->3->4->5->6
Output: 6 5 4 3 2 1
Explanation: After reversing the list, 
elements are 6->5->4->3->2->1.
Example 2:

Input:
LinkedList: 2->7->8->9->10
Output: 10 9 8 7 2
Explanation: After reversing the list,
elements are 10->9->8->7->2.
Your Task:
The task is to complete the function reverseList() with head reference as the only argument 
and should return new head after reversing the list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 104

*/

/*
Algorithm

1. Consider two pointers - prev and next - the next pointer will be pointing to the next node and 
prev will point towards the current node
2. we use a temp pointer to shift from one node to the other- traversing in the linked list
3. now for this temp pointer - we have 2 cases
4. If temp is in the beginning, then we make temp->next as NULL after storting next = temp->next in next pointer 
(prev is assigned to temp )
and assign temp to the next pointer directly.
5. If temp is in middle or at the end, then temp->next is changed to prev pointer, after changing the next pointer
and prev pointer is then changed to temp again.

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
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        struct Node* temp= head;
        struct Node* prev=temp;
        struct Node* next=temp->next;
        
        temp->next = NULL;
        
        while (temp!=NULL && next != NULL){
            temp = next;
            if (temp->next != NULL){
                
                next = temp->next;
            }
            else{
                next = NULL;
            }
            temp ->next = prev;
            prev = temp;
            
        }
        return temp;
    }
    
};

// recursive method

Node* reverse (Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*rest = reverse(head->next);
    head->next->next=head=head;
    head->next=NULL; // for last node
    return rest;
}