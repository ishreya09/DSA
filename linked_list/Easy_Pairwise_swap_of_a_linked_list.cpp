/*
Pairwise swap elements of a linked list
Easy

https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1?page=1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a singly linked list of size N. The task is to swap elements in the linked list pairwise.
For example, if the input list is 1 2 3 4, the resulting list after swaps will be 2 1 4 3.
Note: You need to swap the nodes, not only the data. If only data is swapped then driver will print -1.

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
Output: 2 1 4 2 6 5 8 7
Explanation: After swapping each pair
considering (1,2), (2, 4), (5, 6).. so
on as pairs, we get 2, 1, 4, 2, 6, 5,
8, 7 as a new linked list.
 

Example 2:

Input:
LinkedList: 1->3->4->7->9->10->1
Output: 3 1 7 4 10 9 1
Explanation: After swapping each pair
considering (1,3), (4, 7), (9, 10).. so
on as pairs, we get 3, 1, 7, 4, 10, 9,
1 as a new linked list.
Your Task:
The task is to complete the function pairWiseSwap() which takes the head node as the 
only argument and returns the head of modified linked list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 103
*/

/*
Algorithm

1. If the linked list is empty or has a single node, no need to swap and return head directly
2. If 1st point is not true, then define prev and current pointers - and make the current's next to point towards 
prev. Also define a next pointer which is pointing to current's next. 
3. if next is not null or next is not the last node, then point prev's next to next's next pointers and change prev to next
and cur to next->next.
4. If next is null or next is the last node, change prev->next = next and thus swaping it pairwise.

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
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        // if linked list is empty or has only one element
        if (head == NULL || head->next == NULL)
            return head;
            
        Node *prev=head;
        Node *cur= head->next;
        head= cur;
        
        while (true){
            Node *next = cur->next;
            cur->next = prev;
            
            // If next is NULL or next is the last node
            if (next == NULL || next->next == NULL) {
                prev->next = next;
                break;
            }
            // Change next of previous to next of next
            prev->next = next->next;
       
            // Update previous and curr
            prev = next;
            cur = prev->next;
        }
        
        return head;
    }
};
