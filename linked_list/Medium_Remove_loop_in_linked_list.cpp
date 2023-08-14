/*
Remove loop in Linked List
Medium

https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1?page=1&category[]=Linked%20List&sortBy=submissions

Given a linked list of N nodes such that it may contain a loop.

A loop here means that the last node of the link list is connected to the node at position X(1-based index). 
If the link list does not have any loop, X=0.

Remove the loop from the linked list, if it is present, i.e. unlink the last node which is forming the loop.


Example 1:

Input:
N = 3
value[] = {1,3,4}
X = 2
Output: 1
Explanation: The link list looks like
1 -> 3 -> 4
     ^    |
     |____|    
A loop is present. If you remove it 
successfully, the answer will be 1. 

Example 2:

Input:
N = 4
value[] = {1,8,3,4}
X = 0
Output: 1
Explanation: The Linked list does not 
contains any loop. 

Example 3:

Input:
N = 4
value[] = {1,2,3,4}
X = 1
Output: 1
Explanation: The link list looks like 
1 -> 2 -> 3 -> 4
^              |
|______________|
A loop is present. 
If you remove it successfully, 
the answer will be 1. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function removeLoop() 
which takes the head of the linked list as the input parameter. Simply remove the loop in the list 
(if present) without disconnecting any nodes from the list.
Note: The generated output will be 1 if your submitted code is correct.


Expected time complexity: O(N)
Expected auxiliary space: O(1)


Constraints:
1 ≤ N ≤ 10^4


*/

/*
Algorithm

1. apply floyd's algorithm to check for loop
2. Find the first node of the loop using slow and fast pointers. Make slow point to head
and fast at the meeting point. Move them both one by one. If slow==fast- that's the first node
3. Keep track of prev node of slow pointer before and afterwards of fast pointer. Do dry run to understand that.

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
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        // lets apply the floyd's algorithm such that slow and fast pointer meet incase there is a loop
        // then lets find the first node and its simentaneous prev node
        // set prev node's next to NULL
        // loop is removed
        if(head==NULL || head->next==NULL){
            return;
        }
        
        Node* prev=NULL;
        Node* slow=head,*fast=head;
        slow=head->next;
        fast = fast->next->next;
        while (fast && fast->next){
            if(slow==fast){
                break;
            }
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if (slow!=fast){
            // loop doesnt exist
            return;
        }
        
        // loop exists
        slow=head;
        
        while(slow!=fast && fast && fast->next){
            prev=fast; // jhol
            slow=slow->next; 
            fast=fast->next;
        }
        
        // slow==fast
        // slow points to first node of the loop
        prev->next=NULL;
        
    }
    
};