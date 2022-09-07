/*
19. Remove Nth Node From End of List
Medium

https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?
*/

/*
Algorithm
1. take 2 pointers - temp and rem,
make temp traverse till n nodes while rem points to head node.
2. check if n==0 and temp->next==NULL - if true - it means we need to delete the head node
3. Now make rem and temp traverse through the list till temp->next==NULL,
once it is null- rem points to the previous node of the nth node from the end of the linked list
4. Now delete the rem->next pointer and set rem->next to rem->next->next 

*/
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==NULL || (head->next==NULL && n==1)){
            return NULL;
        }

        ListNode *temp=head;
        ListNode *rem=head;

        while(n-- && temp->next!=NULL){
            temp=temp->next;
        }
        
        if (temp->next==NULL && n==0){
            // delete the head node
            head=head->next;
            return head;
        }

        while (temp->next!=NULL){
            temp=temp->next;
            rem=rem->next;
            
        }
    
        cout<<rem->val;
        rem->next= rem->next->next;
        
        
        // delete (cur);
        return head;

    }
};
