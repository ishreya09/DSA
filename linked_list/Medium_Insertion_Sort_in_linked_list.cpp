/*
Insertion Sort for Singly Linked List
Medium

https://practice.geeksforgeeks.org/problems/insertion-sort-for-singly-linked-list/1?page=2&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given a singly linked list, sort the list (in ascending order) using insertion sort algorithm.

Example 1:

Input:
N = 10
Linked List = 30->23->28->30->11->14->
              19->16->21->25 
Output : 11 14 16 19 21 23 25 28 30 30 
Explanation :
The resultant linked list is sorted.
Example 2:

Input : 
N = 7
Linked List=19->20->16->24->12->29->30 
Output : 12 16 19 20 24 29 30 
Explanation : 
The resultant linked list is sorted.
Your task:
You don't need to read input or print anything. Your task is to complete the function 
insertionSort() which takes the head of the linked list, sorts the list using insertion 
sort algorithm and returns the head of the sorted linked list.
 
Expected Time Complexity : O(n2)
Expected Auxiliary Space : O(1)
 
Constraints:
1<=n<=10^3
*/

/*
Algorithm

1) Create an empty sorted (or result) list
2) Traverse the given list, do following for every node.
......a) Insert current node in sorted way in sorted or result list.
3) Change head of given linked list to head of sorted (or result) list. 

Time and space complexity analysis: 
In the worst case, we might have to traverse all nodes of the sorted list for inserting a node. 
And there are “n” such nodes.

Thus Time Complexity: O(n)*O(n)=O(n^2)

Space Complexity: No extra space is required depending on the size of the input. 
Thus Space complexity is constant- O(1).

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
    Node *sorted; // class variable
    
    void SortedInsert(Node* newnode){
        // push in sorted array
        /* Special case for the head end */
        if (sorted == NULL || sorted->data >= newnode->data) {
            newnode->next = sorted;
            sorted = newnode;
        }
        else {
            Node* current = sorted;
            /* Locate the node before the point of insertion
             */
            while (current->next != NULL
                   && current->next->data < newnode->data) {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
        
    }
    
    Node* insertionSort(struct Node* head_ref)
    {
        //code here
        sorted=NULL;
        Node *t=head_ref;
        while(t!=NULL){
            Node *next= t->next;
            
            SortedInsert(t);
            t=next;
        }
        return sorted;
        
    }
    
    
};