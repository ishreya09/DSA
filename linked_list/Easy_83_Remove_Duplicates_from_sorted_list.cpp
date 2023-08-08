/*
83. Remove Duplicates from Sorted List
Easy

https://leetcode.com/problems/remove-duplicates-from-sorted-list/

Given the head of a sorted linked list, delete all duplicates such that each element appears 
only once. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.

*/

/*
Algorithm

1. Create a map to see the frequency of the members
2. If the frequency of a number is greater than 1, then delete that particuar node.
3. Maintain a prev and next(here temp) pointers so as to remove the node from the linked list

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL || head->next==NULL){
            return head;
        }
        map<int,int> freq;
        ListNode *prev=head;
        ListNode *next =head;
        
        while (next!=NULL){
            freq[next->val]++;
            if (freq[next->val]>1){
                // delete the node
                prev->next=next->next;
                next=next->next;
                continue;
            }
            prev= next;
            next=next->next;
        }
        return head;
    }
};