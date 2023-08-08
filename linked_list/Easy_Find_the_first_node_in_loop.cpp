/*
Find the first node of loop in linked list
Easy

https://practice.geeksforgeeks.org/problems/44bb5287b98797782162ffe3d2201621f6343a4b/1?page=1&status[]=unsolved&category[]=Linked%20List&sortBy=submissions

Given a singly linked list of N nodes. Find the first node of the loop if the linked list has a loop. 
If a loop is present return the node data of the first node of the loop else return -1.

Example 1:

Input:

Output: 3
Explanation:
We can see that there exists a loop 
in the given linked list and the first
node of the loop is 3.
 

Example 2:

Input:

Output: -1
Explanation: No loop exists in the above
linked list.So the output is -1.
 

Your Task:
The task is to complete the function findFirstNode() which contains reference to the head as only argument. 
This function should return the value of the first node of the loop if the linked list contains a loop, else return -1.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= N <= 105
1 <= Data on Node <= 106 
0 <= pos <= N

*/

/*
Algorithm

1. Check if there's a cycle using Floyd's loop algorithm of slow and fast pointers
2. If loop is found, initialize a slow pointer to head and fast pointer to the meeting point of fast and slow from the above algorithm.
3. Move both pointers one step at a time and the point where they meet is the first node of the loop.
4. Return the data of the first node of the loop.

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
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        // your code here
        if (!head || head->next==NULL){
            return -1;
        }
        Node *slow=head,*fast=head;
        slow=slow->next;
        fast=fast->next->next;
        while (fast && fast->next){
            if(slow==fast){
                break;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        if (slow!=fast){
            // loop doesnt exist
            return -1;
        }
        // If loop exists, start slow from head and fast from meeting point.
        slow=head;
        while(slow!=fast){
            slow = slow->next;
            fast=fast->next;
        }
        return slow->data;
    }
};