/*
// NOT WORKING -153/231 testcases passed


61. Rotate List
Medium

https://leetcode.com/problems/rotate-list/

Given the head of a linked list, rotate the list to the right by k places.

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109

*/

/*
Algorithm

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || k==0 || head->next==NULL ){
            return head;
        }

        ListNode *temp=head;
        ListNode *rot= head;
        while(k-- && temp->next!=NULL){
            temp=temp->next;
        }
        if(k!=0 && temp->next==NULL){
            // push last node to first
            while(rot->next->next!=NULL){
                rot=rot->next;
            }
            rot->next=NULL;
            temp->next=head;
            head= temp;
            return head;
        }
        while(temp->next!=NULL){
            rot=rot->next; // rot will end up on the prev node since we are 
            // stoping at temp->next ==NULL
            temp=temp->next;
        }
        
        temp->next=head;
        head=rot->next;
        rot->next=NULL;
        return head;
        
    }
};