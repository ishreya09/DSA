/*
Merge 2 sorted linked list in reverse order
Easy

https://practice.geeksforgeeks.org/problems/merge-2-sorted-linked-list-in-reverse-order/1?page=3&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given two linked lists of size N and M, which are sorted in non-decreasing order. 
The task is to merge them in such a way that the resulting list is in decreasing order.

Input:
First line of input contains number of testcases T. For each testcase, first line of input 
conatains length of both linked lists N and M respectively. Next two lines contains N and M elements of two linked lists.

Output:
For each testcase, print the merged linked list which is in non-increasing order.

User Task:
The task is to complete the function mergeResult() which takes reference to the heads of both linked 
list and returns the pointer to the merged linked list.

Constraints:
1 <=T<= 50
1 <= N, M <= 1000

Example:
Input:
2
4 3
5 10 15 40 
2 3 20
2 2
1 1
2 4

Output:
40 20 15 10 5 3 2
4 2 1 1 

Explanation:
Testcase 1: After merging the two lists in decreasing order, we have new lists as 40->20->15->10->5->3->2.

*/

/*
Algorithm

1. check if both lists are null or not. Return NULL if both are nULL
2. If either one of them is not NuLL and other is NULL,  initialize another head and go on pushing the values of either of the nodes 
on the head
3. If both are not NULL, then first take the common elements and push them into new linked list and push on the head.
and then for the elements which is left after either one of them becomes NULL, repeat step -2. 

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


struct Node * mergeResult(Node *node1,Node *node2)
{
    // your code goes here
    if(node1==NULL && node2 == NULL){
        return NULL;
    }
    Node *res=NULL;
    
    while(node1!=NULL && node2!=NULL){
        if (node1->data<= node2->data){
            Node* temp = node1->next;
            
            node1->next= res;
            res= node1;
            
            node1=temp;
        }
        else{
            Node* temp = node2->next;
            
            node2->next= res;
            res= node2;
            
            node2=temp;
            
        }
    }
    
    while(node1!=NULL){
        Node *temp = node1->next;
        node1->next= res;
        res= node1;
            
        node1=temp;
    }
    while(node2!=NULL){
        Node *temp = node2->next;
        node2->next= res;
        res= node2;
            
        node2=temp;
    }


    return res;
}