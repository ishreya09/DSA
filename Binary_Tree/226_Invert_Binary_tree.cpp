/*
226. Invert Binary Tree
Easy

https://leetcode.com/problems/invert-binary-tree/description/

Given the root of a binary tree, invert the tree, and return its root.

Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

*/

/*
Algorithm

1. Think of each node as another seperate binary search tree.
if root is the node, then root->left will be a seperate binary search tree and root->right 
will be seperate binary search tree
2. if root is not null, call the same function recurively and make
root->left be equal to func(root->right) and same for right part of the tree
to swap the nodes and then return the root node.

*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node(Leetcode).
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root !=NULL){
            TreeNode *tem=root->left;
            root->left=invertTree(root->right);
            root->right=invertTree(tem);
            return root;
        }
        else {
            return NULL;
        }
    }
};
