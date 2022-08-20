/*
Add 1 to a number represented as linked list
Easy

https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1?page=1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124 
Your Task:
Your task is to complete the function addOne() which takes the head of the linked list as the only 
argument and returns the head of the modified linked list. The driver code prints the number.
Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 101000
*/

/*
Algorithm

1. reverse the linked list first and take carry as 1
2. Now add 1 to the linked list and if number is less than 9 , change carry to 0.
3. If the number is 9, and temp->next is not NULL, then set the number to 0, and keep carry as 1 and move to next node
4. If the number is 9, and temp->next is NULL, then create a new node and set temp->next to this new node with value as 1.
Also change temp->data =0 and set carry =0 as well.


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


class Solution
{
    public:
    Node* reverse (Node *head){
        struct Node* temp= head;
        struct Node* prev=temp;
        struct Node* next=temp->next;
        
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
    Node* addOne(Node *head) 
    {
        // Your Code here
        head=reverse(head);
        Node* temp = head;
        int carry =1;
        while (carry !=0){
            if (temp->data < 9){
                temp->data+= 1;
                carry=0;
            }
            else{
                if (temp->next == NULL){
                    temp->data =0;
                    Node *newNode = new Node(1);
                    temp->next = newNode;
                    carry =0;
                }
                else {
                    temp ->data =0;
                }
            }
            temp = temp->next;
        }
        
        head = reverse(head);
    }
};
