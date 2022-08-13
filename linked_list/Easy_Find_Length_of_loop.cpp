/*
Find length of Loop
Easy

https://practice.geeksforgeeks.org/problems/find-length-of-loop/1?page=1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a linked list of size N. The task is to complete the function countNodesinLoop() that checks whether a given Linked List contains a loop or not and if the loop is present then return the count of nodes in a loop or else return 0. C is the position of the node to which the last node is connected. If it is 0 then no loop.



Example 1:

Input:
N = 10
value[]={25,14,19,33,10,21,39,90,58,45}
C = 4
Output: 7
Explanation: The loop is 45->33. So
length of loop is 33->10->21->39->
90->58->45 = 7. The number 33 is
connected to the last node to form the
loop because according to the input the
4th node from the beginning(1 based
index) will be connected to the last
node for the loop.
Example 2:

Input:
N = 2
value[] = {1,0}
C = 1
Output: 2
Explanation: The length of the loop
is 2.
Your Task:
The task is to complete the function countNodesinLoop() which contains the only argument as 
reference to head of linked list and return the length of the loop ( 0 if there is no loop).

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 500
0 <= C <= N-1


*/

/*
Algorithm

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


int count (Node *head){
    Node *temp=head->next;
    int c=1;
    
    while (temp!= head && temp!=NULL){
        c++;
        temp = temp->next;
    }
    return c;
    
}

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    // Code here
    Node *temp=head, *fast=head,*slow=head;
    while (fast != NULL && fast->next !=NULL){
        fast = fast->next->next;
        slow= slow->next;
        if (fast ==slow){
            return count (slow);
        }
        
    }
    
}