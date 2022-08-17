/*
Move Last Element to Front of a Linked List
Easy

https://practice.geeksforgeeks.org/problems/move-last-element-to-front-of-a-linked-list/1?page=4&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

You are given the head of a Linked List. You have to move the last element to the front 
of the Linked List and return the list.

 

Example 1:

Input:
N = 5
List = {2,5,6,2,1}
Output:
{1,2,5,6,2}
Explanation:
In the given linked list, the last element is 1,
after moving the last element to the front the
linked list will be {1,2,5,6,2}.
 

Example 2:

Input:
N = 1
List = {2}
Output:
{2}
Explanation:
Here 2 is the only element so, the linked list
will remain the same.
 

Your Task:

You don't need to read input or print anything. Your task is to complete the function moveToFront() 
which takes the address of the head of the linked list and returns the modified linked list.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= N <= 105
0 <= Elements of List <= 109
Sum of N over all test cases doesn't exceeds 106



*/

/*
Algorithm

1. create a previous and last pointer, which points to second last and last node of the linked list.
(to do with one variable, we can also traverse till second last element and then set it to null and
move to the last node and make its next pointer point to head and make head point to this pointer)
2. We make prev->next as NULL and last->next as head and then set the head pointer to last node. 

*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    struct ListNode* next;

    ListNode(int x){
        data =x;
        next = NULL;
    }
};

class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        if(head== NULL || head->next == NULL){
            return head;
        }
        ListNode *prev=head;
        ListNode *last=head;
        while (last->next != NULL){ // while we reach the last node
            prev=last;
            last = last->next;
        }
        prev->next = NULL;
        last->next = head;
        head= last;
        return head;
    }
};