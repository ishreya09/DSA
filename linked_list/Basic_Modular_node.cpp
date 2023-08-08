/*
Modular Node
Basic

https://practice.geeksforgeeks.org/problems/modular-node/1?page=3&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a singly linked list and a number k, you are required to complete the function modularNode() which returns the modular node of the linked list.
A modular node is the last node of the linked list whose Index is divisible by the number k, i.e. i%k==0.
Note: If no such node is available, return -1. We are following 1 indexing.

Example 1:

Input: LinkedList: 1->2->3->4->5->6->7
       k = 3
Output: 6
Explanation: Indexing of the linked list is
same as the values of the Node. The maximum
index is which is divisble by 3 is 6 and the
node value of the 6th index is 6.
Example 2:

Input: LinkedList: 19->28->37->46->55
           k = 2
Output: 46
Explanation: Index start from 1 and end at 5.
The maximum Index which is divisble by 2 is 4
and 4th Node in the list is 46.
 

Your Task:

You don't need to read input or print anything. Complete the function modularNode() which 
takes the head Node and integer k as input parameters and returns the modular Node, if exists, -1 otherwise.

Constraints:
1 <= T <= 100
1 <= N <= 500

*/

/*
Algorithm

1. Initialize i as 1 and mod as -1 (take care for the condiion when k=0)
2. Traverse through the linked list and check if i%k ==0 and change the value of mod
3. If a modular node exists, the value of mod is modified, else -1 is only returned

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


// Your task is to complete the function
// function should return the modular Node
// if no such node is present then return -1
int modularNode(Node* head, int k)
{
	// Code here
	int mod =-1;
	int i=1;
	if(k==0){
	    return -1;
	}
	
	while(head!= NULL){
	    if (i%k==0){
	        mod= head->data;
	    }
	    i++;
	    head= head->next;
	}
	return mod;
}
