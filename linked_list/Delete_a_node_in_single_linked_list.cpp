/*
Delete a Node in Single Linked List
Easy

https://practice.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1?page=1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a singly linked list and an integer x.Delete xth node from the singly linked list.

Example 1:

Input: 1 -> 3 -> 4 
       x = 3
Output: 1 -> 3
Explanation:
After deleting the node at 3rd
position (1-base indexing), the
linked list is as 1 -> 3. 
Example 2:

Input: 1 -> 5 -> 2 -> 9 
x = 2
Output: 1 -> 2 -> 9
Explanation: 
After deleting the node at 2nd
position (1-based indexing), the
linked list is as 1 -> 2 -> 9.
 

Your task: Your task is to complete the method deleteNode() which takes two arguments: 
the address of the head of the linked list and an integer x. The function returns 
the head of the modified linked list.

Constraints:
1 <= T <= 300
2 <= N <= 100
1 <= x <= N

*/

/*
Algorithm

1. There are only 2 deletion possibility- deletion of node at start and deletion in middle or end
2. If we need to delete the head node (x=1), save the head pointer to a temp and change head to head->next and then 
delete the temp variable.
3. If we need to delete the middle or end node - keep a count such that when x== count,
delete that node keeping a prev pointer and changing prev->next to temp->next

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


/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    //Your code here
  
    Node *temp;
    // deleteing the head
    if(x==1){
        temp = head;
        head = head->next;
        delete (temp);
    }
    else {
        int count =0;
        Node *prev= head;
        temp = head;
        
        while(temp!=NULL){
            count+=1;
            
            if (x==count){
                // delete the node 
                Node *del = temp;
                prev->next = temp->next;
                delete(del);
            }
            prev =temp;
            temp = temp->next;
        }
        
        
    }
    
    return head;
}
