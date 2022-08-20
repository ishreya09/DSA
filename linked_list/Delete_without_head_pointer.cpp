/*
Delete without head pointer
Easy

https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1?page=1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. The task is to delete the node. Pointer/ reference to head node is not given. 
Note: No head reference is given to you. It is guaranteed that the node to be deleted is not a tail node in the linked list.

Example 1:

Input:
N = 2
value[] = {1,2}
node = 1
Output: 2
Explanation: After deleting 1 from the
linked list, we have remaining nodes
as 2.
Example 2:

Input:
N = 4
value[] = {10,20,4,30}
node = 20
Output: 10 4 30
Explanation: After deleting 20 from
the linked list, we have remaining
nodes as 10, 4 and 30.
Your Task:
You only need to complete the function deleteNode that takes reference to the node that needs to be deleted. 
The printing is done automatically by the driver code.

Expected Time Complexity : O(1)
Expected Auxilliary Space : O(1)

Constraints:
2 <= N <= 103

*/

/*
Approach: 

Why conventional deletion method would fail here?
It would be a simple deletion problem from the singly linked list if the head pointer 
was given because for deletion you must know the previous node and you can easily reach 
there by traversing from the head pointer. Conventional deletion is impossible without 
knowledge of the previous node of a node that needs to be deleted. 

How to delete the node when you dont have the head pointer?
The trick here is we can copy the data of the next node to the data field of the current 
node to be deleted. Then we can move one step forward. Now our next has become the current 
node and the current has become the previous node. Now we can easily delete the current node 
by conventional deletion methods. 

*/

/*
Algorithm

1. We don't know the previous node, so we copy the data of the next node 
to the present node and then delete the next node
2. Also we change the address of previous node to next node's next variable, 
modyfing the linked list.
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
}*head;

Node *findNode(Node* head, int search_for){
    Node *current = head;
    while (current!= NULL){
        if (current ->data == search_for)
            break;
        current = current->next;
    }
    return current;
}

void insert (){
    int n, i , value;
    Node *temp;
    scanf("%d",&n);

    for (i=0; i<n;i++){
        scanf("%d", &value);
        if (i==0){
            head = new Node(value);
            temp = head;
            continue;
        }
        else{
            temp->next=  new Node(value);
            temp= temp->next;
            temp->next = NULL;
        }
    }
}

void printList(Node* node){
    while (node != NULL){
        printf("%d",node ->data);
        node = node->next;
    }
    cout<<endl;
}

class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
        
       // Your code here
       Node *temp;
       del->data = del->next->data;
       
       temp = del->next;
       del->next = del->next->next ;
       delete(temp);

    }

};

int main(void){
    int t,k,n,value;
    scanf("%d",&k);
    while(t--){
        Node *del = findNode(head,k);
        Solution ob;
        if(del != NULL && del->next != NULL){
            ob.deleteNode (del);
        }
        printList(head);
    }
    return 0;

}


