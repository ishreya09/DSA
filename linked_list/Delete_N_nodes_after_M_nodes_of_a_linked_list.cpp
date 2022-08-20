/*
Delete N nodes after M nodes of a linked list
Easy

https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1?page=2&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list.

Example:
Input:
2
8
2 1
9 1 3 5 9 4 10 1
6
6 1
1 2 3 4 5 6 

Output: 
9 1 5 9 10 1
1 2 3 4 5 6

Explanation:
Deleting one node after skipping the M nodes each time, we have list as 9-> 1-> 5-> 9-> 10-> 1.
Input:
The first line of input contains the number of test cases T. For each test case, the first 
line of input contains a number of elements in the linked list, and the next M and N respectively 
space-separated. The last line contains the elements of the linked list.

Output:
The function should not print any output to the stdin/console.

Your Task:
The task is to complete the function linkdelete() which should modify the linked list as required.

Constraints:

size of linked list <= 1000

1 <= N + M <= size of linked list

*/

/*
Algorithm

1. if M>= length of linked list, return directly
2. if M+N >=length of linked list, reduce the value of N to length - M
3. Now take m and n and initialize both m and n - first decrement m (and keep moving prev and curr pointers), 
once it is zero - keep the prev pointer constant and decrement n while changing prev->next pointer to curr->next pointer
4. ALways keep a check if curr ! = NULL (even inside the loop)

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
    int length(Node *head){
        int c=0;
        Node *temp= head;
        while (temp!=NULL){
            temp=temp->next;
            c++;
        }
        return c;
    }
    void linkdelete(struct Node  *head, int M, int N)
    {
        int len= length(head);
        if (M>=len){
            return;
        }
        if (M+N>=len){
            N=len-M;
        }
        int m=M,n=N;
        Node *prev = head;
        Node *temp= head;
        int c=0;
        
        while (temp!=NULL){ // till we reach the last node
            if (m==0 && n==0){
                m=M;
                n=N;
            }
            
            if (m!=0){
                // do nothing 
                m--;
                prev= temp; // keep changing the previous pointer
                temp=prev->next;
                c++;
            }
            
            if (m==0 && n!=0 && temp !=NULL){
                // delete the node
                prev->next =temp->next;
                delete(temp);
                n--;
                temp=prev->next;
                c++;
            }
        }
        
    }
};
