/*
Find the Sum of Last N nodes of the Linked List
Basic

https://practice.geeksforgeeks.org/problems/find-the-sum-of-last-n-nodes-of-the-linked-list/1?page=2&difficulty[]=-2&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a single linked list of size M, your task is to complete the function sumOfLastN_Nodes(), 
which should return the sum of last N nodes of the linked list.

Input:
The function takes two arguments as input, the reference pointer to the head of the linked list and the an integer N.
There will be T test cases and for each test case the function will be called seperately.

Output:
For each test case output the sum of last N nodes of the linked list.

Constraints:
1<=T<=100
1<=N<=M<=1000

Example:
Input:
2
6 3
5 9 6 3 4 10
2 2
1 2

Output:
17
3

Explanation:
Testcase 1: Sum of last three nodes in the linked list is 3 + 4 + 10 = 17.
 

*/

/*
Algorithm

1. Calculate the length of the Linked list
2. traverse till length-n times in the linked list
3. Add sum after this

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


// your task is to complete this function 
// function should return sum of last n nodes
int length(struct Node *head){
    Node *temp=head;
    int c=0;
    while(temp!= NULL){
        c++;
        temp=temp->next;
    }
    return c;
}

int sumOfLastN_Nodes(struct Node* head, int n)
{
    // Code here
    int M = length (head);
    Node *temp=head;
    while (M-n !=0){
        M--;
        temp=temp->next;
    }
    // temp = temp->next;
    
    int sum=0;
    while (temp != NULL){
        // cout<<temp->data<<endl;
        sum += temp->data;
        temp =temp->next;
    }
    
    return sum;
    
}