/*
Merge K sorted linked lists
Medium

https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1?page=1&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given K sorted linked lists of different sizes. The task is to merge them in such a way that 
after merging they will be a single sorted linked list.

Example 1:

Input:
K = 4
value = {{1,2,3},{4 5},{5 6},{7,8}}
Output: 1 2 3 4 5 5 6 7 8
Explanation:
The test case has 4 sorted linked 
list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be
1->2->3->4->5->5->6->7->8.
Example 2:

Input:
K = 3
value = {{1,3},{4,5,6},{8}}
Output: 1 3 4 5 6 8
Explanation:
The test case has 3 sorted linked
list of size 2, 3, 1.
1st list 1 -> 3
2nd list 4 -> 5 -> 6
3rd list 8
The merged list will be
1->3->4->5->6->8.
Your Task:
The task is to complete the function mergeKList() which merges the K given lists into a sorted one. 
The printing is done automatically by the driver code.

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)
Note: n is the maximum size of all the k link list

Constraints
1 <= K <= 103

 

*/

/*
Algorithm

1. Initialize a new Head as null
2. Iterate through the list and merge head and arr[i] list in sorted Merge manner and store it back to head.
3. repeat step 2 till i==K
4. return head

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
    Node *sortedMerge(Node *h1, Node *h2){
        Node *a=h1,*b=h2;
        if (a==NULL){
            return b;
        }
        if(b==NULL){
            return a;
        }
        if (b->data<a->data){
            Node *t=b->next;
            b->next=a; // insert at head
            h1=b;
            b=t;
            a= h1;
        }
        while(a!=NULL && a->next!=NULL && b!=NULL){
            if (a->next->data>b->data){
                Node *t=b->next;
                b->next = a->next;
                a->next= b;
                b=t;
            }
            a=a->next;
        }
        if (b!=NULL){
            a->next=b;
        }
        return h1;
    }
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        // Your code here
        Node *head=NULL;
        for (int i=0; i<K;i++){
            head= sortedMerge(head,arr[i]);
        }
        return head;
        
    }
};

