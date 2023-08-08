/*
24. Swap Nodes in Pairs
Medium

https://leetcode.com/problems/swap-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without 
modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100

*/

/*
Algorithm

1. If head contains NULL or only one node- simply return the head
2. If 1st point is not true, then define prev and current pointers - and make the current's next to point towards 
prev. Also define a next pointer which is pointing to current's next. 
3. if next is not null or next is not the last node, then point prev's next to next's next pointers and change prev to next
and cur to next->next.
4. If next is null or next is the last node, change prev->next = next and thus swaping it pairwise.

*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head==NULL || head->next==NULL){
            return head;
        }
        ListNode *prev=head;
        ListNode *cur= head->next;
        head= cur;
        
        while (true){
            ListNode *next = cur->next;
            cur->next = prev;
            
            // If next is NULL or next is the last node
            if (next == NULL || next->next == NULL) {
                prev->next = next;
                break;
            }
            // Change next of previous to next of next
            prev->next = next->next;
       
            // Update previous and curr
            prev = next;
            cur = prev->next;
        }
        
        return head;
    }
};