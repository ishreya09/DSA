/*
257. Binary Tree Paths
Easy

https://leetcode.com/problems/binary-tree-paths/description/

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Example 1:

Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100

*/

/*
Algorithm

1. Take a vector of strings and an empty string and pass it to another function with root Node
2. When we reach a leaf node, we add the value of string to the vector of strings. (Base condition)
3. If not, then we recursively call the function with string as str+"->"+root->left->val and 
2nd time with node->right->val. 
This helps us backtrack the value of s, giving us all the possibility possible from root to leaf.

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

class Solution
{
    public:
        void solve(TreeNode *root, vector<string> &ans, string s)
        {
           	// if the current node is not having either a left or a right then we are 
           	// done with one root to leaf path so we push it into the answer
            if (!root->left && !root->right)
            {
                ans.push_back(s);
                return;
            }

           	// we move towards either left of the root or right of the root, whichever
           	// suitable adding the current node's value to the string and moving ahead
           	// this addition to our string goes on until we find our base condition break
            if (root->left) 
                solve(root->left, ans, s + "->" + to_string(root->left->val));
            if (root->right) // state of s is preserved
                solve(root->right, ans, s + "->" + to_string(root->right->val));
        }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        if (!root) return ans;
       	// we make the value of our root node as a string
        string s = to_string(root->val);
        solve(root, ans, to_string(root->val));
        return ans;
    }
};