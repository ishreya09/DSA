/*
Given a linked list of 0s, 1s and 2s, sort it.
Easy

https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?page=1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Example 1:

Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated
to the left end of the linked list,
2s to the right end of the list, and
1s in between.
Example 2:

Input:
N = 4
value[] = {2,2,0,1}
Output: 0 1 2 2
Explanation: After arranging all the
0s,1s and 2s in the given format,
the output will be 0 1 2 2.
Your Task:
The task is to complete the function segregate() which segregates the nodes in the linked list as asked 
in the problem statement and returns the head of the modified linked list. The printing is done 
automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 103

*/

/*
Algorithm

1. Count the number of 0, 1 and 2 present in the linked list
2. Create a new head and start adding the maximum value(2) in the linked list using push func
3. push is a function which inserts a node at the head.
4. Go on and repeat same for then 1 and then 0 and return the new head we created.

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
    void push (Node **head, int data){
        Node *temp= new Node(data);
        temp->next =(*head);
        (*head)=temp;
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        int c0=0,c1=0,c2=0;
        Node *temp=head;
        while(temp != NULL){
            if (temp->data ==0){
                c0++;
            }
            if (temp->data ==1){
                c1++;
            }
            if (temp->data ==2){
                c2++;
            }
            temp = temp->next;
        }
        Node *head2= NULL;
        
        while (c2--){
            push (&head2, 2);
        }
        while (c1--){
            push (&head2, 1);
        }
        while (c0--){
            push (&head2, 0);
        }
        
        return head2;
        
    }
};

