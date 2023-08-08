/*
Delete Alternate Nodes
Basic

https://practice.geeksforgeeks.org/problems/delete-alternate-nodes/1?page=2&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a Singly Linked List of size N, delete all alternate nodes of the list.

Example 1:

Input:
LinkedList: 1->2->3->4->5->6
Output: 1->3->5
Explanation: Deleting alternate nodes
results in the linked list with elements
1->3->5.
 

Example 2:

Input:
LinkedList: 99->59->42->20
Output: 99->42
 

Your Task:

Your task is to complete the function deleteAlt() which takes the head of the linked list in the 
input parameter and modifies the given linked list accordingly.

 

Constraints:
1<=N<=100

 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

*/

/*
Algorithm

1. Define a  k which is incremented per node
2. Delete a node only at even values of k (thereby alternate)
3. Define a previous and current pointer to traverse and delete the nodes.
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


// Complete this function
void deleteAlt(struct Node *head){
    // Code here
    if (head== NULL || head->next==NULL){
        return;
    }
    int k=1;
    Node *prev=head;
    Node *curr = head;
    while(curr!=NULL){
        if (k%2==0){
            // delete the node
            prev->next = curr->next;
            delete(curr);
            k++;
            curr = prev->next;
            continue;
        }
        k++;
        prev = curr;
        curr =curr->next;
    }
    
}

void deleteAlt1(struct Node *head){
    // Code here

    if(head==NULL || head->next==NULL){
        return;
    }
    Node* slow= head;
    Node* fast =slow->next;
    
    while(fast!=NULL){
        slow->next=fast->next;
        slow=slow->next;
        delete(fast);
        if (slow!=NULL)
            fast=slow->next;
        else
            fast=slow;
    }
}
