/*
876. Middle of the Linked List
Easy

https://leetcode.com/problems/middle-of-the-linked-list/

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100

*/

/*
Algorithm


1. Check if head is null or not - checking if the linked list is empty and if its true then return -1.
2. Check if head->next is null or not- if that is the case - we can surely say that we only have one element in
the linked list and we can return node->data directly
3. If its not the above two cases, instead of finding the length and traversing through the linked list again and again - 
its better to define a fast pointer(Pointing to head initially) which moves 2 indexes at a time and a 
slow pointer (Pointing to head initially) and traverse the list element by element.
4. When the fast->next pointer becomes Null, the slow pointer remains exactly in the middle of the list.

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
    ListNode* middleNode(ListNode* head) {
        if (head==NULL || head->next==NULL){
            return head;
        }
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
        
    }
};