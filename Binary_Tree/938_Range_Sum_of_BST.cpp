/*
938. Range Sum of BST
Easy

https://leetcode.com/problems/range-sum-of-bst/description/

Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes
with a value in the inclusive range [low, high].



Example 1:


Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
Example 2:


Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.


Constraints:

The number of nodes in the tree is in the range [1, 2 * 104].
1 <= Node.val <= 105
1 <= low <= high <= 105
All Node.val are unique.

*/

/*
Algorithm

1. if root is null, return null
2. divide each root into left and right subtree and caculate the sum of that sub tree in the given range and repeat the process
3. if the val is in the range we add the value and add the further in sum of left and right subtree of the given present node.

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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->val >= low && root->val <= high)
        {
            cout << root->val << endl; // values added
            // add the root->val and find sum for left and right subtree
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        else
        {
            // just add the left and right subtree - if element won't be found on either side, it will return 0 anyway
            return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
    }
};