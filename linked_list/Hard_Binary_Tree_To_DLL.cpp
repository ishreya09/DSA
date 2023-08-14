/*
Binary Tree to DLL
Hard

https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1?page=2&category[]=Linked%20List&sortBy=submissions

Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Note: H is the height of the tree and this space is used implicitly for the recursion stack.
 

TreeToList

Example 1:

Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3 
Explanation: DLL would be 3<=>1<=>2
Example 2:

Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40
Explanation:  DLL would be 
40<=>20<=>60<=>10<=>30.
Your Task:
You don't have to take input. Complete the function bToDLL() that takes root node of the tree as a parameter and returns the head of DLL . The driver code prints the DLL both ways.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).

Constraints:
1 ≤ Number of nodes ≤ 105
0 ≤ Data of a node ≤ 105    
*/

/*
Algorithm

1. For Converting Binary tree to dll
    a. We will use opposite of inorder traversal - right root left
    b. We will first convert right subtree to dll
    c. Then we will convert left subtree to dll
    d. Then we will make root as head of dll
    e. Then we will make root->right=head
    f. Then we will make head->left=root
    g. Then we will make head=root
    h. Then we will convert left subtree to dll
    i. Then we will convert right subtree to dll
    j. Then we will return head

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;


    Node(int x){
        data =x;
        left =right=NULL;
    }
};

// This function should return head to the DLL
class Solution
{
    public: 
    void BtoDLL(Node* root, Node* &head){
        // your code here
        if (root==NULL){
            return;
        }
        // going in opposite of inorder traversal 
        BtoDLL(root->right,head);
        root->right=head;
        if(head!=NULL){
            head->left=root; // previous root 
            // we are inserting at the head in this.
        }
        head=root; // head points to new root
        BtoDLL(root->left,head);
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        Node*head=NULL;
        BtoDLL(root,head);
        return head;
    }
};