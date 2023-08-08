/*
Delete node in Doubly Linked List
Basic

https://practice.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1?page=2&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a doubly linked list and a position. The task is to delete a node from given position in a doubly linked list.

Example 1:

Input:
LinkedList = 1 <--> 3 <--> 4 
x = 3
Output: 1 3  
Explanation: After deleting the node at
position 3 (position starts from 1),
the linked list will be now as 1->3.
Example 2:

Input:
LinkedList = 1 <--> 5 <--> 2 <--> 9  
x = 1
Output: 5 2 9
Your Task:
The task is to complete the function deleteNode() which should delete the node at given 
position and return the head of the linkedlist.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
2 <= size of the linked list <= 1000
1 <= x <= N

*/

/*
Algorithm

1. if value to be deleted is at its head, then point the head pointer to the next value and 
set the prev's value of the node to NULL and delete the head node
2. if the value to be deleted is at the end - i.e. if curr->next ==NULL, then go to previous node 
and set the next node to NuLL and delete the last node.
3. If the value to be deleted is in the middle, set the next and prev pointers and set it for the pointers of 
previous and next nodes

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;

    Node(int x){
        data =x;
        next = NULL;
        prev=NULL;
    }
};


class Solution
{
    public:
    Node* deleteNode(Node *head, int x)
    {
      //Your code here
      int k=1;
      if(head==NULL)
        return head;
        else if (head->next == NULL && k==x){
            delete(head);
            return NULL;
        }
        else if(head->next == NULL && k!=x){
            return head;
        }
        else if (head->next!=NULL && k== x){
            Node *temp= head;
            head = head->next;
            head->prev= NULL;
            delete(temp);
            return head;
        }
        else{
            Node *temp=head;
            Node *prev,*next;
            
            while (temp!=NULL && k!= x){
                temp =temp->next;
                k++;
            }
            prev = temp->prev;
            next = temp->next;
            if (next!=NULL)
                next->prev = prev;
            prev->next= next;
            delete(temp);
            return head;
        }
        
        
    }
};

class Solution1
{
    public:
    Node* deleteNode(Node *head, int x)
    {
      //Your code here
      if (head == NULL){
          return head;
      }
      else if(x==1){
          head= head->next;
          return head;
      }
      Node* temp =head;
      while(--x){
          temp=temp->next;
      }
      temp->prev->next=temp->next;
      if (temp->next !=NULL){
          temp->next->prev= temp->prev;
          delete(temp);
      }
      return head;
      
    }
};