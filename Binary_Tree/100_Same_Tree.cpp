/*
100. Same Tree
Easy

https://leetcode.com/problems/same-tree/description/

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104

*/

/*
Algorithm

1. For checking if we have the same tree or not, we do any type of traversal. 
In this case, we do inorder traversal for both the nodes.
2. If the value of the nodes are not same, we return false, then and there.
3. if both the trees reach the leaf node's null at the same time, then we can return true, otherwise
we will return false.
4. The ans will always depend on left tree and right tree, so the final answer will be "and" and then returned.

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        else if(p==NULL || q==NULL){
            return false;
        }
        bool a= isSameTree(p->left,q->left);
        if(p->val!=q->val){
            return false;
        }
        bool b=isSameTree(p->right,q->right);
        return a&b;
    }
};