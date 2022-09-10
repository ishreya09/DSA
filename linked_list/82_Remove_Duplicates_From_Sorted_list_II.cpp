/*
WRONG ANSWER

82. Remove Duplicates from Sorted List II
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
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head!=NULL || head->next==NULL){
            return head;
        }
        ListNode *temp=head;
        ListNode *prev=head;
        temp=head;
        int d;
        while(temp!=NULL){
            if(temp==head && temp->next && temp->val== temp->next->val){
                d=temp->val;
                while(temp->val==d){
                    head=head->next;
                    temp=head;
                    prev=head;
                }
            }
            else if(temp->next && temp->val == temp->next->val){
                d==temp->val;
                while(temp->val==d){
                    prev->next=temp->next;
                    temp=prev->next;
                }
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }

        return head;
    }
};