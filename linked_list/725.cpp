/*


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
    int length(ListNode *head){
        if (head==NULL){
            return 0;
        }
        else{
            return 1+ length(head->next);
        }
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> a(k);
        int len=length(head);
        int i=0;
        int n=k/len;
        int b = k%len; 
        
        n=n+b;
        ListNode *temp=head;
        ListNode *prev=head;

        while(temp!=NULL){
            a[i]=temp;
            i++;
            while(--n){
                prev=temp;
                temp=temp->next;
            }
            temp=prev->next;
            prev->next=NULL;
            prev=temp;
            n=k/len;
        }
        return a;
    }
};