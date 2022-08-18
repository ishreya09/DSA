/*
Rearrange linked list in-place
Easy

https://practice.geeksforgeeks.org/problems/rearrange-linked-list-in-place/1?page=3&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln. Rearrange the nodes in the list so that 
the new formed list is: L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2.

Input:
You have to complete the method which takes 1 argument: the head of the  linked list. You should not 
read any input from stdin/console. There are multiple test cases. For each test case, this method will 
be called individually.

Output:
Your function should return a pointer to the rearranged list so obtained.

User Task:
The task is to complete the function inPlace() which should rearrange the given linked list as required.

Constraints:
1 <=T<= 50
1 <= size of linked lists <= 100

Example:
Input:
2
4
1 2 3 4
5
1 2 3 4 5

Output:
1 4 2 3
1 5 2 4 3

Explanation:
Testcase 1: After rearranging the linked list as required, we have 1, 4, 2 and 3 as the elements of the linked list.

*/

/*
Algorithm

1. Find the middle element and reverse the list from there after setting the middle element's next as null and 
shifting to middle element's previous next.
2. Reverse the list after the middle node then traverse the heads of both the linked list and add them alternatingly.

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


//Function to reverse a linked list.
struct Node* reverse(struct Node *head)
{
        // code here
        // return head of reversed list
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
  

Node *inPlace(Node *root)
{
    // your code goes here
    Node *fast = root;
    Node *slow =root;
    
    while(fast!= NULL && fast->next!=NULL){
        slow= slow->next;
        fast = fast->next->next;// (fast->next != NULL) ? fast->next->next : fast->next;
    }
    // cout << slow->data<< endl;
    Node *temp = slow->next;
    slow->next = NULL;
    
    temp = reverse (temp); // reversing from middle
    fast = root;
    Node *c;
    while (temp!= NULL && fast!= NULL){
        c=temp->next;
        temp->next = fast->next;
        fast->next = temp;
        temp=c;
        fast = fast->next->next;
    }
    
}

