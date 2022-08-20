/*
Reverse a Doubly Linked List
Easy

https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1?page=2&difficulty[]=-2&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a doubly linked list of n elements. The task is to reverse the doubly linked list.

Example 1:

Input:
LinkedList: 3 <--> 4 <--> 5
Output: 5 4 3
Example 2:

Input:
LinkedList: 75 <--> 122 <--> 59 <--> 196
Output: 196 59 122 75
Your Task:
Your task is to complete the given function reverseDLL(), which takes head reference 
as argument and should reverse the elements so that the tail becomes the new head and all 
pointers are correctly pointed. You need to return the new head of the reversed list. 
The printing and verification is done by the driver code.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= number of nodes <= 103
0 <= value of nodes <= 103

*/

/*
Algorithm

1. Swap the prev and next pointers at each node - 
and return tail which is pointing to the last element of the linked list

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;


    Node(int x){
        data =x;
        next = NULL;
        prev= NULL;
    }
};


Node* reverseDLL(Node * head)
{
    //Your code here
    if (head==NULL && head->next != NULL){
        return head;
    }
    Node *cur=head;
    Node *temp;
    Node *tail = head;
    
    while(cur != NULL ){
        // swap the next and prev pointers of doubly linked list
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        
        tail = cur;
        cur= cur->prev;
        
    }
    return tail;
    
}
