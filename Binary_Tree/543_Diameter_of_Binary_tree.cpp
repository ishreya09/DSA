/*
543. Diameter of Binary Tree
Easy

https://leetcode.com/problems/diameter-of-binary-tree/description/

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100

*/

/*
Algorithm

1. Write a function to find the height of the tree
2. For Diameter of binary tree- we can either find the the max path(diameter) in left tree or the right tree 
or addition of the heights of left and right trees. 
The number of nodes will be equal to height of the left tree+ height of right tree +1 - which is the max path
3. We return the maximum value of that. 

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
    // using height function for option3 of diameter function
    int height(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        return 1 + max<int>(leftHeight, rightHeight);
    }
    
    int diameterOfBinaryTree(TreeNode* root){
        // base case
        if(root == NULL){
            return 0;
        }
        
        // diameter will of either of these:- either in left only, either in right only, either combination of both
        
        int option1 = diameterOfBinaryTree(root->left); // either in left
        
        int option2 = diameterOfBinaryTree(root->right); // either in right
        
        int option3 = height(root->left) + height(root->right); // either combination of both
        
        int ans = max<int>(option1, max<int>(option2, option3));
        
        return ans;
    }
};