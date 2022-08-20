/*
Check if Linked List is Palindrome
Easy

https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1?page=1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a singly linked list of size N of integers. 
The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.
Your Task:
The task is to complete the function isPalindrome() which takes head as reference as the only parameter 
and returns true or false if linked list is palindrome or not respectively.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

Constraints:
1 <= N <= 105
*/

/*
Algorithm

1. to check if a linked list is palindrome or not, we find the middle element first (using fast and slow ptr)
2. We reverse the list from the middle to the end  (using prev and next ptr)
3. We go element by element checking if the digits are same or not.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x){
        data =x;
        next = NULL;
    }
};


class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        
            if (head==NULL){
                return false;
            }
            Node *temp= head;
            Node *fast=head;
            Node *slow = head;
            while (fast!=NULL && fast->next !=NULL){
                fast = fast->next->next;
                slow=slow->next;
            } 
            // we have mid pointer in slow pointer
            
            // logic to reverse the linked list from the middle
            Node *next=slow->next,*prev = slow;
            slow->next = NULL;
            while (next!=NULL && slow!=NULL){
                slow = next;
                if (slow->next != NULL){
                    next = slow->next;
                }
                else{
                    next=NULL;
                }
                slow->next = prev;
                prev=slow;
            }
            int c=0;

            while(temp!=NULL && slow !=NULL && c!=1){
                if (temp->data!=slow->data){
                    c=1;
                }
                temp=temp->next;
                slow=slow->next;
            }
            
            if (c==0){
                return true;
            }
            else{
                return false;
            }
    }
};
