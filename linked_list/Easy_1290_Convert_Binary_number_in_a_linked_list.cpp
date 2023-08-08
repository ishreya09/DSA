/*
1290. Convert Binary Number in a Linked List to Integer
Easy

https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

Given head which is a reference node to a singly-linked list. The value of each node in 
the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

 

Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.

*/

/*
Algorithm

1. initialise ans as 0
2. traverse the linked list as you double the ans first (left shift one time) 
and then left shift the head's data and multiply by 2(left shift once) and add to the ans
3. add the last node's data at end without multipling by 2.


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
    int getDecimalValue(ListNode* head) {
        int n=0;
        while(head->next!=NULL){
            n= n<<1;
            n+= head->val<<1;
            head=head->next;
        }
        n+= head->val;
        return n;
    }
};