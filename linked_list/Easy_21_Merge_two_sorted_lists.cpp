/*
TIME LIMIT EXCEEDED

21. Merge Two Sorted Lists
Easy

https://leetcode.com/problems/merge-two-sorted-lists/

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the 
nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

*/

/*
Algorithm

1. We merge list2 into list1.
2. If list1->val (head node) has more value than list2->val (head node), then we insert list2 head node in front and assign 
temp to it.
3. Take a temp pointer and traverse and keep checking if temp->next!=NULL && temp->next->val >= list2->val ,
if true add a pointer after temp
4. If temp reaches the last node and list2 is still not exausted, we simply merge the 2 lists then.

*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        ListNode *temp = list1;
        ListNode *p=NULL;

        if(list1->val > list2->val){
            p=list2->next;
            list2->next=list1;
            list1=list2;
            list2=p;
            temp=list1;
        }
        while(list2 !=NULL && temp!=NULL){
            
            if(temp->next!=NULL && temp->next->val >= list2->val){
                p=list2->next;
                list2->next=temp->next;
                temp->next=list2;
                temp=temp->next;
                list2=p;
                continue;
            }
            else if(temp->next==NULL && temp->val <= list2->val){ // last node 
                temp->next=list2;
                list2=NULL;
                temp=NULL;
                break;
            }
            temp= temp->next;
        }

        return list1;
        
    }
};