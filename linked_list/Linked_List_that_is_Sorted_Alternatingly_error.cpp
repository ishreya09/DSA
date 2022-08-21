/*
Linked List that is Sorted Alternatingly
Easy

https://practice.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1?page=3&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a Linked list of size N, the list is in alternating ascending and descending orders. 
Sort the given linked list in non-decreasing order.


Example 1:

Input:
LinkedList: 1->9->2->8->3->7
Output: 1 2 3 7 8 9
Explanation: After sorting the given
list will be 1-> 2-> 3-> 7-> 8-> 9.
 

Example 2:

Input:
LinkedList: 13->99->21->80->50
Output: 13 21 50 80 99
Explanation: After sorting the given list 
will be 12-> 21-> 50-> 80-> 99.
 

Your Task:
You do not need to read input or print anything. The task is to complete the function sort() 
which should sort the linked list in non-decreasing order. 

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= Number of nodes <= 100
0 <= Values of the linked list <= 103


*/

/*
Algorithm

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

// your task is to complete this function
void sort(Node **head)
{
     // Code here
     if((*head)==NULL || (*head)->next == NULL){
         return ;
     }
     Node *res=NULL;
     Node *last=NULL;
     Node *odd =(*head);
     bool flag =false; 

     Node *even =(*head)->next;
     
     while(even->next != NULL && odd->next!= NULL){
         
         odd->next= even->next;
         even->next = res;
         
         if(res==NULL ){
             last= even;
         }
         res= even;
         
         odd= odd->next;
         if(odd->next !=NULL)
            even= odd->next;
     }
     
   
     if (even->next==NULL){
         odd->next = NULL;
         even->next= res;
         res=even;
     }
     
     if (last->data >= odd->data)
         odd->next = res;
     else if (last->data < odd->data){
         last->next= (*head);
         (*head) = res;
     }
     else{
         Node *start= (*head);
         //merge alternatingly
         while(res != NULL && (*head)->data > res->data){
             Node *tem= res->next; // insertion at head
             res->next= (*head);
             (*head)= res;
             res= tem;
         }
         
         while (res!= NULL && start!= NULL){
             if (res->data < start->next->data){ // insertion in between and at last
                 res->next = start->next->next;
                 start->next=res;
             }
         }
         
     }
     
}