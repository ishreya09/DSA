/*
101. Symmetric Tree
Easy

https://leetcode.com/problems/symmetric-tree/description/

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center)
Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?

*/

/*
Algorithm

1. Split the root node to its left(r) and right nodes(s). Now if we traverse left in r then we traverse right in s 
and vice versa.
2. We check if the value of nodes are equal or not at each position and if its not equal, we return false.
3. If we reach null at the same time, then we have a symmtric tree, otherwise we return false.

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
    // changing the parameters for our ease to write a recurrsive solution
    bool isSym(TreeNode *r,TreeNode* s){
        if (r==NULL && s==NULL){
            return true;
        }
        else if(r==NULL || s==NULL){
            return false;
        }
        if (r->val==s->val){
            // if we traverse in left for r, traverse right for s and vice versa for it to be symmetric
            return isSym(r->left,s->right) && isSym(r->right,s->left);
        }
        else{
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        return isSym(root->left,root->right);
    }
};