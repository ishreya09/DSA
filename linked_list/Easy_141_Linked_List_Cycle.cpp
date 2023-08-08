/*
141. Linked List Cycle
Easy

https://leetcode.com/problems/linked-list-cycle/

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/

/*
Algorithm

Implementation of Floyd’s Cycle-Finding Algorithm: 

1. Traverse linked list using two pointers.
2. Move one pointer(slow) by one and another pointer(fast) by two.
3. If these pointers meet at the same node then there is a loop. If pointers do 
not meet then linked list doesn’t have a loop.

*/

/**
 * Definition for singly-linked list.
 */

#include<bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head==NULL || head->next==NULL){
            return false;
        }
        ListNode* fast=head->next;
        ListNode *slow=head;
        while (fast!=NULL && fast!=slow && fast->next != NULL){
            fast =fast->next->next;
            slow=slow->next;
        }
        return fast==slow;
    }
};