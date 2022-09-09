/*
2. Add Two Numbers
Medium

https://leetcode.com/problems/add-two-numbers/

You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

*/

/*
Algorithm

1. Write the logic of reverse function using prev and next pointers and reverse the linked list of first and second numbers.
2. Once both numbers linked list are reversed, start adding. If addition is greater than 9, store the rest of 
the number in carry.
3. Check for the conditions such as if first number reaches null first/ second number reaching null, etc
4. If at the end, carry is not equal to zero, then push carry as well into the linked list.

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
    void push (ListNode **head,int val){
        ListNode *temp= new ListNode(val);
        temp->next = (*head);
        (*head) = temp; 
    }
    
    ListNode* reverse (ListNode *head){
        ListNode* temp= head;
        ListNode* prev=temp;
        ListNode* next=temp->next;
        
        temp->next = NULL;
        
        while (temp!=NULL && next != NULL){
            temp = next;
            if (temp->next != NULL){
                
                next = temp->next;
            }
            else{
                next = NULL;
            }
            temp ->next = prev;
            prev = temp;
            
        }
        return temp;
    }
    //Function to add two numbers represented by linked list.
    ListNode* addTwoNumbers(ListNode* first, ListNode* second)
    {
        // code here
        int add=0,carry=0;
        ListNode *head1= NULL;
        while (first != NULL || second!= NULL){
            
            if (first== NULL && second !=NULL)
                add = carry + second->val;
            else if(first != NULL && second == NULL)
                add = carry + first ->val;
            else
                add=carry + first->val+second->val;
                
            if (add>9){ // add's range can't go beyond 18
                carry = add/10;
                add= add%10;
            }
            else {
                carry =0;
            }
            push (&head1,add);
            if (first != NULL)
                first= first->next;
            if(second != NULL)
                second= second->next;
        }
        if (carry != 0){
            push (&head1,carry);
        }
        return head1;
    }
};
