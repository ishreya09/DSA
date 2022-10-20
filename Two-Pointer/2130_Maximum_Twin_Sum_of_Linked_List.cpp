/*
2130. Maximum Twin Sum of a Linked List
Medium

https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.

 

Example 1:


Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6. 
Example 2:


Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 
Example 3:


Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.
 

Constraints:

The number of nodes in the list is an even integer in the range [2, 105].
1 <= Node.val <= 105

*/

/*
Algorithm

1. Traverse till the middle of the linked list and reverse the array from there 
2. Calculate the twin sum and find the max value and return max value

*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        
 
        /* reverse the rest list and put
          the first element at the end */
        ListNode* rest = reverse(head->next);
        head->next->next = head;
 
        /* tricky step -- see the diagram */
        head->next = NULL;
 
        /* fix the head pointer */
        return rest;
    }
    int pairSum(ListNode* head) {
        if(head==NULL){
            return 0;
        }
        if (head!=NULL && head->next!=NULL && head->next->next==NULL){
            // 2 elements
            return head->val+head->next->val;
        }
        ListNode *slow= head;
        ListNode *fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        ListNode *p = slow->next;
        slow->next = NULL;
        p = reverse(p);
        fast=head;
        int sum=0;
        while(fast!=NULL && p!=NULL){
            sum=max<int>(sum,fast->val+p->val);
            fast=fast->next;
            p=p->next;
        }
        return sum;
    }
};