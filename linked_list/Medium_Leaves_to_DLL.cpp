/*
Leaves to DLL
Medium

https://practice.geeksforgeeks.org/problems/leaves-to-dll/1?page=1&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given a Binary Tree of size N, extract all its leaf nodes to form a Doubly Link List starting from the 
left most leaf. Modify the original tree to make the DLL thus removing the leaf nodes from the tree. 
Consider the left and right pointers of the tree to be the previous and next pointer of the DLL respectively.

Note: The generated output will contain the inorder traversal of the modified tree, the DLL from left 
to right and the DLL from right to left.

Example 1:

Input :
        1
      /   \
     2     3
    / \   / \
   4   5 6   7    

Output: 
Modified Tree :
        1
      /   \
     2     3

Doubly Link List :
4 <-> 5 <-> 6 <-> 7

Explanation:
The leaf nodes are modified to form the DLL 
in-place. Thus their links are removed from 
the tree.
Example 2:

Input :
        1
      /   \
     2     3
    / \   
   4   5 

Output: 
Modified Tree :
        1
      /   
     2    

Doubly Link List :
4 <-> 5 <-> 3

Your Task:  
You don't need to read input or print anything. Complete the function convertToDLL() which takes 
the root of the given tree as input parameter and returns the head of the doubly link list.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)


Constraints:
1 ≤ N ≤ 10^4

*/

/*
Algorithm

1. The algorithm is similar to binary tree to DLL type
2.  The only thing to check here to add to our head will be if that root node is a leaf node or not
3. Also we traverse right part of the tree first and then left so that we move head from last to the front.
4. Make sure if we add head - we return NULL for the root->right and root->left 
so that the leaf nodes are deleted from the tree.

*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

// The function returns new root of 
// Binary Tree (Note that root may change 
// if Binary Tree has only one node).
// The function also sets *head_ref as 
// head of doubly linked list. left pointer 
// of tree is used as prev in DLL 
// and right pointer is used as next 
Node* extractLeafList(Node *root, Node **head_ref) 
{ 
    // Base cases 
    if (root == NULL) return NULL; 
      
    if (root->left == NULL && root->right == NULL) 
    { 
        // This node is going to be added 
        // to doubly linked list of leaves,
        // set right pointer of this node 
        // as previous head of DLL. We 
        // don't need to set left pointer  
        // as left is already NULL 
        root->right = *head_ref; 
      
        // Change left pointer of previous head 
        if (*head_ref != NULL) 
            (*head_ref)->left = root; 
      
        // Change head of linked list 
        *head_ref = root; 
      
        return NULL; // Return new root 
    } 
    // Recur for right and left subtrees 
    root->right = extractLeafList(root->right, head_ref); 
    root->left = extractLeafList(root->left, head_ref); 
      
    return root; 
}

// return the head of the DLL and remove those node from the tree as well.
Node * convertToDLL(Node *root){
    // add code here.
    Node *head=NULL;
    root= extractLeafList(root,&head);
    return head;
}