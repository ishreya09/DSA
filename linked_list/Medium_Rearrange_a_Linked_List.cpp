/*
Rearrange a linked list
Medium

https://practice.geeksforgeeks.org/problems/rearrange-a-linked-list/1?page=1&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given a singly linked list, the task is to rearrange it in a way that 
all odd position nodes are together and all even positions node are together.
Assume the first element to be at position 1 followed by second element at position 2 and so on.
Note: You should place all odd positioned nodes first and then the even positioned ones. 
(considering 1 based indexing). Also, the relative order of odd positioned nodes and even 
positioned nodes should be maintained.

Example 1:

Input:
LinkedList: 1->2->3->4
Output: 1 3 2 4 
Explanation: 
Odd elements are 1, 3 and even elements are 
2, 4. Hence, resultant linked list is 
1->3->2->4.
Example 2:

Input:
LinkedList: 1->2->3->4->5
Output: 1 3 5 2 4 
Explanation: 
Odd elements are 1, 3, 5 and even elements are
2, 4. Hence, resultant linked list is
1->3->5->2->4.
Your Task:
The task is to complete the function rearrangeEvenOdd() which rearranges the nodes in the 
linked list as required and doesn't return anything.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ Size of the linked list ≤ 104
0 ≤ value of linked list ≤ 103

*/

/*
Algorithm

1. Find the end node
2. Store the end node in last and then add all even postion node to last and move last to that node.
Maintain a prev node of temp to delete the node from the current list
3. This method only checks till the end and the end node is not added to the end of list if the pos is even
So we do this explicitly later on

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
    void rearrangeEvenOdd(Node *head)
    {
       // Your Code here
       if(head==NULL || head->next==NULL || head->next->next==NULL){
           return;
       }
       // traverse and find the end
       Node *end=head;
       while(end!=NULL && end->next!=NULL){
           end=end->next;
       }
       Node *last= end;
       Node* temp=head,*prev=NULL;
      int i=1;
      while(end!=NULL && temp!=end){
          if(i++%2==0){ // even pos
              // delete node from here and add it to the last
              prev->next=temp->next;
              temp->next=NULL;
              last->next=temp;
              last=temp;
              temp=prev->next;
          }
          else{
              prev=temp;
              temp=temp->next;
          }
      }
      if(i%2==0 && temp!=NULL && end!=NULL && temp==end){
        //   then end will have to come at the last
        prev->next=temp->next;
        temp->next=NULL;
        last->next=temp;
        last=temp;
      }
    }
};
