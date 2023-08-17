/*
Flattening a Linked List
Medium

https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1?page=1&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 

Note: The flattened list will be printed using the bottom pointer instead of the next pointer.
For more clarity have a look at the printList() function in the driver code.

 

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
 

Example 2:

Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
Output: 5->7->8->10->19->22->28->30->50
Explanation:
The resultant linked lists has every
node in a single level.

(Note: | represents the bottom pointer.)
 

Your Task:
You do not need to read input or print anything. Complete the function flatten() that takes the 
head of the linked list as input parameter and returns the head of flattened link list.

Expected Time Complexity: O(N*N*M)
Expected Auxiliary Space: O(N)

Constraints:
0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 10^3

*/

/*
Algorithm


One solution is to do any type of tree traversal and store in a map and then create
a simple linked list throught that. But due to that - our space complexity becomes 
O(n). 
   
Another soluution is to use sorted merge of two lists and solve it recursively
by doing it root->next first and then sort the returned list and the root list and
make sure to make root->next =NULL 

Time Complexity : O(n)
Space Complexity : O(1) - uses Recursion Stack
*/

#include<bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};


/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   if (root && root->next==NULL){
       return root;
   }
   Node *first=flatten(root->next);
   Node *second= root; // We got our two lists
   root->next= NULL;
   
   if (first->data < second->data){
       // we need to insert first's node at the head of the second list
       Node* tmp= first->bottom;
       first->bottom= second;
       second=first;
       first =tmp;
   }
   // Apply sorted merge
   while (first!=NULL && second!=NULL && second->bottom!=NULL){
       if (second->bottom->data>first->data){ // add before
           Node *tmp= first->bottom;
           first->bottom=second->bottom;
           second->bottom = first;
           first=tmp;
       }
       second=second->bottom;
       
   }
   if (first){
       second->bottom= first;
   }
   return root;
   
}
