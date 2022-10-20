/*
1721. Swapping Nodes in a Linked List
Medium

https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node 
from the end (the list is 1-indexed).

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 10^5
0 <= Node.val <= 100


*/

/*
Algorithm

1. Use one pointer p and first traverse till the kth element, this will give me kth element from the start. Store it
in another pointer (say temp2)
2. Use the same pointer p along with another pointer temp which initially points to the head
and traverse the linked list till p becomes null
3. temp points to the kth node from the last. Swap temp2 and temp nodes's value and return the head.

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *temp =head;
        ListNode *temp2;
        ListNode *p= head;
        while(p!=NULL && --k){
            p=p->next;
        }
        temp2=p;
        while(p!=NULL && p->next!=NULL){
            p=p->next;
            temp=temp->next;
        }
        swap(temp->val, temp2->val);
        return head;
        
    }
};