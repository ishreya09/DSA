
/*
Rotate a Linked List
Medium

https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1?page=1&category[]=Linked%20List&sortBy=submissions

Given a singly linked list of size N. The task is to left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Example 1:

Input:
N = 5
value[] = {2, 4, 7, 8, 9}
k = 3
Output: 8 9 2 4 7
Explanation:
Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
Rotate 3: 8 -> 9 -> 2 -> 4 -> 7
Example 2:

Input:
N = 8
value[] = {1, 2, 3, 4, 5, 6, 7, 8}
k = 4
Output: 5 6 7 8 1 2 3 4

Your Task:
You don't need to read input or print anything. Your task is to complete the function rotate() which 
takes a head reference as the first argument and k as the second argument, and returns the head of 
the rotated linked list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 103
1 <= k <= N

*/

/*
Algorithm

1. For rotating, first go the last pointer and connect the last pointer to the head- making it 
as a circular linked list.
2. Once this is done, traverse the last pointer k times.
3. When k becomes 0, come out of the loop, set head as last->next and set last->next =NULL to convert it
back to Simple linked list.

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
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        // we need last ptr and head
        if(!head || k<1){
            return head;
        }
        Node* last=head;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next = head; // making it circular linked list
        while(k--){
            last = last->next;
        }
        head= last->next;
        last->next=NULL;
        
        return head;
        
    }
};
    
