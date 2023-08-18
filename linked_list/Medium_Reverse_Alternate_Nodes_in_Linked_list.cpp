/*
Reverse alternate nodes in Link List
Medium

https://practice.geeksforgeeks.org/problems/given-a-linked-list-reverse-alternate-nodes-and-append-at-the-end/1?page=1&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given a linked list, you have to perform the following task:

Extract the alternative nodes starting from second node.
Reverse the extracted list.
Append the extracted list at the end of the original list.
â€‹Example 1:

Input:
LinkedList = 10->4->9->1->3->5->9->4
Output: 10 9 3 9 4 5 1 4
Explanation: Reversing the alternative
nodes from the given list, and then
appending them to the end of the list
results in a list with the elements as
10 9 3 9 4 5 1 4.
â€‹Example 2:

Input:
LinkedList = 1->2->3->4->5
Output: 1 3 5 4 2 
Explanation:
Your Task:
You don't have to read input or print anything. Your task is to complete the function rearrange() 
which takes the head of the linked list as input and rearranges the list as required.

Note: Try to solve the problem without using any extra memory.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
0 <= Node_value <= 1000

*/

/*
Algorithm

1. 

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
    void rearrange(struct Node *odd)
    {
        //add code here
        if (odd == NULL){
            return;
        }
        // lets get the end pointer
        int i=1;
        Node* end=odd;
        while(end->next!=NULL){
            end=end->next;
        }
        // Now lets traverse the list and move them to the end of the list 
        // make sure not to move the end so that they are reversed finally
        
        Node *temp=odd;
        Node* prev =NULL;
        while(end!=NULL && temp!=end){
            if(i++%2 == 0){
                prev->next=temp->next;
                temp->next=end->next;
                end->next=temp;
                temp=prev->next;
                
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
    }
};
