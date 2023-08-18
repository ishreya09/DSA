/*
Merge Sort for Linked List
Medium

https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1?page=1&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Example 1:

Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.
Example 2:

Input:
N = 3
value[]  = {9,15,0}
Output: 0 9 15
Explanation: After sorting the given
linked list , resultant will be
0->9->15.
Your Task:
For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(N) - recursion stack space

Constraints:
1 <= N <= 10^5


*/

/*
Algorithm

1. If head is NULL or there is only one element - return
2. Otherwise Split the linked list into two using slow and fast pointer nd sliting in the middle
3. Sort the two halves- Bharosa func
Mergesort(partA)
Mergesort(partB)

4. Merge the sorted A and B parts and update the head pointer ref


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
    // split the nodes in a given list into front and back halves
    // and return two lists using double pointer refrences
    // we can also use c++ refrences
    void FrontBackSplit(Node *source, Node **front, Node **back){
        Node* fast;
        Node* slow= source; // advance by 1 node
        fast= source->next; // advance by 2 nodes 
        while (fast!= NULL){
            fast=fast->next;
            if(fast!=NULL){
                slow=slow->next; // points to the middle of linked list
                fast=fast->next;
            }
        }
        *front = source;
        *back = slow->next;
        slow->next=NULL;
    }
    Node *SortedMerge(Node *a,Node *b){
        Node *result= NULL;
        // base cases
        if (a==NULL)
            return b;
        else if(b==NULL)
            return a;
        
        // pick either a or b and recur
        if (a->data <= b->data){
            result= a;
            result->next= SortedMerge(a->next,b);
        }
        else {
            result= b;
            result->next= SortedMerge(a,b->next);
        }
        return result;
    }
    void mergeSortRec(Node **headRef){
        Node *head=*headRef;
        Node *a,*b;
        if (head==NULL || head->next==NULL){
            return;
        }
        // split a and b
        FrontBackSplit(head,&a,&b);
        // Sort the sublists
        mergeSortRec(&a);
        mergeSortRec(&b);
        // ans = merge two sorted linked list
        *headRef = SortedMerge(a,b);
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        mergeSortRec(&head);
        return head;
        
    }
};