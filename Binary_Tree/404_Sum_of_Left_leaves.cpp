/*
404. Sum of Left Leaves
Easy

https://leetcode.com/problems/sum-of-left-leaves/description/

Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
Example 2:

Input: root = [1]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000

*/

/*
Algorithm

1. For each node, check if it has a left node and if node->left is the leaf node, then we add it to ans and move to left 
to make it null. On a null, the sum will always lead to 0.
2. if the node has the left node, but the next left node is not leaf node, we recursively call the func by moving left.
3. if the node has the right node, we move to the right node to check if has any left leaf nodes in its children.
4. After adding for the case 1, 2 and 3 - we return the sum for each node.

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
        int sumOfLeftLeaves(TreeNode* root) {
            if(root==NULL){
                return 0;
            }
            int ans=0;
            if (root->left && root->left->left==root->left->right){
                ans+= root->left->val+ sumOfLeftLeaves(root->left);
            }
            else{
                ans+= sumOfLeftLeaves(root->left);
            }
            if(root->right){
                ans+= sumOfLeftLeaves(root->right);
            }
            return ans;
        }
};