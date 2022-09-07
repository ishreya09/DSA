/*
234. Palindrome Linked List
Easy

https://leetcode.com/problems/palindrome-linked-list/

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?

*/

/*
Algorithm

1. to check if a linked list is palindrome or not, we find the middle element first (using fast and slow ptr)
2. Make slow's prev node to NULL. 
3. We reverse the list from the middle to the end  (using slow ptr) and reassign fast to head
4. We go element by element checking if the digits are same or not by traversing in fast and slow's list. 

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
    ListNode *reverse(ListNode *head){
        if (head==NULL || head->next==NULL){
            return head;
        }
        ListNode *rest = reverse(head->next);
        head->next->next=head;
        head->next=NULL;

        return rest;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        // find the middle of the list
        ListNode *fast= head;
        ListNode *slow=head;
        ListNode *prev=slow;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            prev=slow;
            slow= slow->next;
        }
        // slow has the middle pointer
        // for even length - fast will be NULL
        // for odd length - fast->next will be NULL
        bool odd= (fast==NULL);

        prev->next=NULL;
        // reverse the list from the middle ptr
        slow= reverse(slow);
        fast = head;
        while(slow!=NULL && fast!=NULL ){
            if (slow->val!=fast->val){
                return false;
            }
            slow=slow->next;
            fast=fast->next;
        }
        
        return true;
    }
};