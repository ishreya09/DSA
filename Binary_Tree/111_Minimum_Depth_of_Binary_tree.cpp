/*
111. Minimum Depth of Binary Tree
Easy

https://leetcode.com/problems/minimum-depth-of-binary-tree/description/

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 

Constraints:

The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000

*/

/*
Algorithm

1. Think of each node as another seperate binary search tree.
if root is the node, then root->left will be a seperate binary search tree and 
root->right will be seperate binary search tree
2. if root is Null, we have reached the leaf node and we return 0.
3. if root->left == NULL , then look in right side of the tree and find its depth and add 1 and vice versa for root->right==NULL
4. If both the child nodes are not NULL, then find the min b/w the depth of left child and right child
and add 1 to count the root node's height.

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
    int minDepth(TreeNode* root) {
        if (root==NULL){
            return 0;
        }
        return (root->left==NULL) ? 
        minDepth(root->right)+1 
        :((root->right==NULL)?(minDepth(root->left)+1) 
        : (min<int>(minDepth(root->left),minDepth(root->right))+1));
    }
};