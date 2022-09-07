/*
86. Partition List
Medium

https://leetcode.com/problems/partition-list/

Given the head of a linked list and a value x, partition it such that all nodes less than x come 
before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200

*/

/*
Algorithm

1. Create 2 new linked lists as part1 and part2 with heads as head1 and head2. 
Make Sure not to lose the head of part2 list and we would also need the last node of part1 list. 
2. part1 list will have the elements less than x and part2 list will have elements greater than or equal to x.
Traverse through the linked list given, and at last Merge the two lists at the end.
3. Take care of the condition that part1 list might be NULL - so to access part1->next = head2 will give 
runtime error.



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
    ListNode* partition(ListNode* head, int x) {
        ListNode *part1=NULL,*part2=NULL, *head1=NULL,*head2=NULL;
        ListNode *temp=head;
        ListNode *p;
        while(temp!=NULL){
            p=temp->next;
            temp->next=NULL;
            if(temp->val <x && part1==NULL){
                part1=temp;
                head1=part1;
            }
            else if(temp->val < x){
                part1->next=temp;
                part1= part1->next;
            }
            else if (temp->val >= x && part2==NULL){ // temp->val >= x condition is already true
                part2=temp;
                head2=part2;
            }
            else if (temp->val >= x){
                part2->next=temp;
                part2=part2->next;
            }
            temp=p;
        }
        if (part1!=NULL)
            part1->next=head2;
        else{
            head1=head2;
        }
        return head1;
        
    }
};