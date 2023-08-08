/*
203. Remove Linked List Elements
Easy

https://leetcode.com/problems/remove-linked-list-elements/

Given the head of a linked list and an integer val, remove all the nodes of the linked list that has 
Node.val == val, and return the new head.


Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50
*/

/*
Algorithm

1. Keep a track of cur and prev pointers while traversing through the linked list.
Keep a note that prev pointer doesn't get changed when we delete the node of the list.
We also will traverse the whole list, instead of just looping till the first element that has 
same value as x.
2. If the element is present at the head- we need to move the cur to cur->next
and point head to cur and delete the previous pointer
3. If the element is present in middle or in between, make prev->next point to cur->next and delete cur and 
make cur point to prev->next.

*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head==NULL || (head->next==NULL && head->val==val)){
            return NULL;
        }
        else if (head->next==NULL && head->val!=val){
            return head;
        }
        ListNode *prev=head;
        ListNode *cur=head;

        while(cur!=NULL){
            if (val== cur->val && cur==head){
                head= head->next;
                prev=head;
                cur=head;
                continue;
            }
            else if(val==cur->val){
                prev->next = cur->next;
                cur= cur->next;
                continue;
            }
            prev= cur;
            cur=cur->next;          
            
        }
        return head;
        
    }
};