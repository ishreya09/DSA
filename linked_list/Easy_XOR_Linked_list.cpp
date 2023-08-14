
/*
XOR Linked List
Easy

https://practice.geeksforgeeks.org/problems/xor-linked-list/1?page=3&status[]=unsolved&category[]=Linked%20List&sortBy=submissions

An ordinary Doubly Linked List requires space for two address fields to store the addresses of previous and next nodes. A memory efficient version of Doubly Linked List can be created using only one space for address field with every node. This memory efficient Doubly Linked List is called XOR Linked List or Memory Efficient as the list uses bit-wise XOR operation to save space for one address.
Given stream of data of size N for the linked list, your task is to complete the function insert() and printList(). The insert() function pushes (or inserts at beginning) the given data in the linked list and the printList() function returns the linked list as a list.
Note: There is an utility function XOR() that takes two Node pointer to get the bit-wise XOR of the two Node pointer. Use this function to get the XOR of the two pointers.

Example 1:

Input:
LinkedList: 9<->5<->4<->7<->3<->10
Output:
10 3 7 4 5 9
9 5 4 7 3 10
Example 2:

Input:
LinkedList: 58<->96<->31
Output:
31 96 58
58 96 31
Your Task:
The task is to complete the function insert() and printList() as required.

Note: The driver code prints the returned list twice, once forward and once backward.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 100

*/

/*
Algorithm

1. The insert and print to similar to how its done in normal doubly linked list. What is different here is that 
we XOR the value of prev and next pointers in order to save space

2. The XOR of two addresses will be the address of the next or previous node depending on which node we are at
and also we use a variable xor_prev which will store the previous node's address

Consider a dll - 

1->2->3->4

1->npx= Null XOR add(2)
2->npx= add(1) XOR add(3)
3->npx= add(2) XOR add(4)
4->npx= add(3) XOR Null

Now if we want to go from 1 to 2, we can do so by XORing 1->npx with NULL
Now if we want to go from 2 to 3, we can do so by XORing 2->npx with add(1)
Now if we want to go from 3 to 4, we can do so by XORing 3->npx with add(2)
So basically this algorithm works like a linkedlist traversal but instead of traversing it forwards or backwards, 
here we are doing it in both directions at the same time

3. So in order to traverse the list, we need to store the previous node's address in a variable xor_prev
and then we can traverse the list by XORing the current node's npx with xor_prev

4. Now we need to update the npx of the current node. 
So we need to XOR the current node's npx with the address of the next node
and then store it in the npx of the current node. But we dont have the address of the next node. 
So we need to store it in a variable

5. Now we need to update the address of the next node.

6. Now we need to update the address of the previous node.

uintptr_t is used for casting pointers when we want to perform address arithmetic
*/

#include<bits/stdc++.h>
using namespace std;

// Utility function to get XOR of two Struct Node pointer
// use this function to get XOR of two pointers
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

// Structure of linked list is as
struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

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

struct Node *insert(struct Node *head, int data) {
    // Code here
    Node* temp = new Node(data);
    if (head==NULL){
        head=temp;
    }
    else{
        temp->npx = (Node*)((uintptr_t)head ^ (uintptr_t)NULL);
        Node*k = (Node*)((uintptr_t)head->npx ^ (uintptr_t)NULL);
        head->npx=(Node*)((uintptr_t)k ^ (uintptr_t)temp);
        head=temp;
    }
}

vector<int> printList(struct Node *head) {
    // Code here
    vector<int> ans;
    Node* add =NULL;
    Node* temp=head;
    while (temp!=NULL){
        ans.push_back(temp->data);
        Node* cur=temp;
        temp = (Node*)((uintptr_t)temp->npx ^ (uintptr_t)add); // gives next node address
        add=cur;
        
    }
    return ans;
}
