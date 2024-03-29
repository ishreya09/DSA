/*
Find n/k th node in Linked list
Basic

https://practice.geeksforgeeks.org/problems/find-nk-th-node-in-linked-list/1?page=2&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a singly linked list and a number k. Write a function to find the (N/k)th element, where N is the number of elements in the list. We need to consider ceil value in case of decimals.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case consists of an integer N. The second line consists of N spaced integers.The last line consists of an integer k.

Output:
Print the data value of (N/k)th node in the Linked List.

User Task:
The task is to complete the function fractional_node() which should find the n/kth node in the linked list and return its data value.

Constraints: 
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
6
1 2 3 4 5 6
2
5
2 7 9 3 5
3

Output:
3
7

Explanation:
Testcase 1: 6/2th element is the 3rd(1-based indexing) element which is 3.

*/

/*
Algorithm

1. Take two pointers temp and fractionalNode and initialize them with null and head respectively.
2. For every k jumps of the temp pointer, make one jump of the fractionalNode pointer.

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


int fractional_node(struct Node *head, int k)
{
    
    
    int i=1;
    Node *temp=head;
    Node *fn = head;
    while (temp->next!=NULL){
        // cout<< i <<"\t"<< head->data<< endl;
        if (i==k){
            i=0;
            fn= fn->next;
        }
        i++;
        temp= temp->next;
    }
    return fn->data;
}

int fn(struct Node* head,int k){
    int i=1;
    Node* fast=head,*slow=head;
    while(fast->next!=NULL){
        if(i==k){
            slow=slow->next;
            i=0;
        }
        i++;
        fast=fast->next;
    }
    return slow->data;
}