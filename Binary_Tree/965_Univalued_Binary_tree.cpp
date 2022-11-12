/*
965. Univalued Binary Tree
Easy

https://leetcode.com/problems/univalued-binary-tree/description/

A binary tree is uni-valued if every node in the tree has the same value.

Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

 

Example 1:


Input: root = [1,1,1,1,1,null,1]
Output: true
Example 2:


Input: root = [2,2,2,5,2]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
0 <= Node.val < 100

*/

/*
Algorithm

1. Traverse the whole tree and check if it matches with the root->val or not
2. If all elements are same, then we return true.

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
    bool isEqual(TreeNode *root,int n){
        if (root==NULL){
            return true;
        }
        if (root->val==n){
            bool a=isEqual(root->left,n);
            bool b= isEqual(root->right,n);
            return a && b;
        }
        else{
            return false;
        }
    }
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL){
            return false;
        }
        return isEqual(root,root->val);
    }
};