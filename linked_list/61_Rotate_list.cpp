/*
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

1. Take the last node and move to the front, and repeat it k times.


Alternate:

1. Find the length and simentaneously make the last node point to head node, making a circular list.
2. Find the kth node from the end of the list and then make the head and make it's prev node as NULL.

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
    int len(ListNode *head){
        if (head==NULL){
            return 0;
        }
        else{
            return 1+ len(head->next);
        }
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || head->next==NULL || k==0){
            return head;
        }
        ListNode *temp=head;
        k= k%len(head);
        while (k!=0){ // bad time complexity
            temp=head;
            while(temp->next !=NULL){
                if (temp->next->next==NULL){
                    temp->next->next =head;
                    head= temp->next;
                    temp->next=NULL; 
                    k--; // one rotation done
                }
                else{
                    temp=temp->next;
                }
            }
        }
        return head;
        
    }
};