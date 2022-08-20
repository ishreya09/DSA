/*
Add two numbers represented by linked lists
Easy

https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1?page=1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given two decimal numbers represented by two linked lists of size N and M respectively. The task is to return a linked list that represents the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists 
and returns the head of the sum list.   

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M)) for the resultant list.

Constraints:
1 <= N, M <= 5000

*/

/*
Algorithm

1. Write the logic of reverse function using prev and next pointers and reverse the linked list of first and second numbers.
2. Once both numbers linked list are reversed, start adding. If addition is greater than 9, store the rest of the number in carry.
3. Check for the conditions such as if first number reaches null first/ second number reaching null, etc
4. If at the end, carry is not equal to zero, then push carry as well into the linked list.

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
    void push (struct Node **head,int data){
        Node *temp= new Node(data);
        temp->next = (*head);
        (*head) = temp; 
    }
    
    struct Node* reverse (struct Node *head){
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
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first =reverse(first);
        second =reverse (second);
        int add=0,carry=0;
        Node *head1= NULL;
        while (first != NULL || second!= NULL){
            
            if (first== NULL && second !=NULL)
                add = carry + second->data;
            else if(first != NULL && second == NULL)
                add = carry + first ->data;
            else
                add=carry + first->data+second->data;
                
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
