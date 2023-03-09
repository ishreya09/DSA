/*
Check for BST
Easy

Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

Input:
   2
 /    \
1      3
Output: 1 
Explanation: 
The left subtree of root node contains node
with key lesser than the root nodes key and 
the right subtree of root node contains node 
with key greater than the root nodes key.
Hence, the tree is a BST.
Example 2:

Input:
  2
   \
    7
     \
      6
       \
        5
         \
          9
           \
            2
             \
              6
Output: 0 
Explanation: 
Since the node with value 7 has right subtree 
nodes with keys less than 7, this is not a BST.
Your Task:
You don't need to read input or print anything. Your task is to complete the function isBST() 
which takes the root of the tree as a parameter and returns true if the given binary tree is 
BST, else returns false. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
0 <= Number of edges <= 100000

*/

/*
Algorithm

1. Find the inorder traversal of the tree and check if it ascending or not.
2. if it is ascending, then it is a BST, otherwise not.

*/

#include<bits/stdc++.h>
using namespace std;

// gfg
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    void inorder(Node *root, vector<int> &a){
        if (root==NULL){
            return;
        }
        inorder(root->left,a);
        a.push_back(root->data);
        inorder(root->right,a);
    }
    bool isBST(Node* root) 
    {
        vector<int> a;
        inorder(root,a);
        int i=0,j=1;
        while (j<a.size()){
            if (a[i]<=a[j]){
                i++;
                j++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

