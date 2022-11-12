/*
144. Binary Tree Preorder Traversal
Easy

https://leetcode.com/problems/binary-tree-preorder-traversal/description/

Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
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
2. In Inorder traversal, we traverse the root node first then the left node and then the right node.
3. We make the recursive call acordingly and in place of printing root node, we append it to the vector.

Iterative Approach 

Following is a simple stack based iterative process to print Preorder traversal. 

Create an empty stack nodeStack and push root node to stack. 
Do the following while nodeStack is not empty. 
Pop an item from the stack and print it. 
Push right child of a popped item to stack 
Push left child of a popped item to stack
The right child is pushed before the left child to make sure that the left subtree is processed first.

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
    void preorder(TreeNode*root , vector<int> &a){
        // left right node
        if (root== nullptr){
            return;
        }
        a.push_back(root->val);
        preorder(root->left,a);
        preorder(root->right,a);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>a;
        preorder(root,a);
        return a;
    }
};