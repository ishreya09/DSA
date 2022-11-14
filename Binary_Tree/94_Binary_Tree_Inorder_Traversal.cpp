/*
94. Binary Tree Inorder Traversal
Easy

https://leetcode.com/problems/binary-tree-inorder-traversal/description/

Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?

*/

/*
Algorithm

1. Create an array and store all the values in the array.
2. In Inorder traversal, we traverse the left node first then the root node and then the right node.
3. We make the recursive call acordingly and in place of printing root node, we append it to the vector.

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
        void inorder(TreeNode* root, vector<int> &a){
            // left root right
            if (root==NULL){
                return;
            }
            inorder(root->left,a);
            a.push_back(root->val);
            inorder(root->right,a);
        }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> a;
        inorder(root,a);
        return a;
    }
};