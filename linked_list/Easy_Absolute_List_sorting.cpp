/*
Absolute List Sorting
Easy

https://practice.geeksforgeeks.org/problems/absolute-list-sorting/1?page=3&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a linked list L of N nodes, sorted in ascending order based on the absolute values of its data,i.e. negative values are considered as positive ones. Sort the linked list according to the actual values, consider negative numbers as negative and positive number as positive.


Example 1:

Input: 
List: 1, -2, -3, 4, -5
Output: 
List: -5, -3, -2, 1, 4
 

Example 2:

Input: 
List: 5, -10
Output: 
List: -10, 5
 

Your Task:
You don't need to read or print anyhting. Your Task is to comple the function sortList() 
which takes the head of the Linked List as input parameter and sort the list in ascending order. 
Don't create a new Linked List instead rearrange the given List.

 

Expected Time Complexity: O(N)
Expected Space Complexity: O(1)


Constraints
1 ≤  N  ≤ 104
-105 ≤ L[i] ≤ 105

*/

/*
Algorithm

1. An important observation is, all negative elements 
are present in reverse order. So we traverse the list, 
whenever we find an element that is out of order, we move 
it to the front of the linked list. 

2. to track if the element is out of order, maintain a val which contains data of last node 
(or check which node is negative)
3. Maintain next and prev pointers to manage deletion and insertion.

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


/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution
{
public:
    void sortList(Node** head)
    {
        // Your Code Here
        
        
        if ((*head)==NULL){
            return;
        }
        int val = (*head)->data;
        Node *temp= (*head)->next;
        Node *prev = (*head);
        while(temp != NULL){
            if (val > temp->data){ // push in the start
                prev->next = temp->next;
                temp->next = (*head);
                (*head)= temp;
                temp = prev->next;
                continue;
            }
            val= temp->data;
            prev= prev->next;
            temp= prev->next;
        }
    }
};

