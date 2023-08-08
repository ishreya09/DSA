/*
Move all zeros to the front of the linked list
Easy

https://practice.geeksforgeeks.org/problems/move-all-zeros-to-the-front-of-the-linked-list/1?page=3&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a linked list, the task is to move all 0s to the front of the linked list. The order of all another element except 0 should be same after rearrangement.

Example 1:

Input:  0 -> 4 -> 0 -> 5 -> 0
Output: 0 -> 0 -> 0 -> 4 -> 5
Explanation: After moving all 0s of the given
list to the front, the list is:
0 -> 0 -> 0 -> 4 -> 5
Example 2:

Input: 0 -> 1 -> 0 -> 1 -> 2
Output: 0 -> 0 -> 1 -> 1 -> 2
Your Task:
You don't need to read input or print anything. Your task is to complete the function moveZeroes() 
which takes head node of the linked list as input parameter.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 50

*/

/*
Algorithm

1. Keep a track of previous (here prev) and next(here temp) pointers
2. Do not change the prev pointer if we encounter a 0
3. If we encounter a zero, push it in the starting of the list before head. (since its only 0)
4. Adjust the pointers carefully

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


// Move Zeros to the front of the list
void moveZeroes(struct Node **head)
{
    //Your code here
    if ((*head)== NULL){
        return;
    }
    Node *temp = (*head)->next;
    Node *prev = (*head);
    while (temp != NULL){
        if(temp->data == 0){
                prev->next= temp->next;
                temp->next = (*head);
                (*head)= temp; // insertion at head
                temp = prev->next;
                continue;
        }
        prev = prev->next;
        temp = prev->next;
    }
    
}