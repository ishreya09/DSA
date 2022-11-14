/*
783. Minimum Distance Between BST Nodes
Easy

https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

Given the root of a Binary Search Tree (BST), return the minimum difference between the values 
of any two different nodes in the tree.

Example 1:

Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 105
 

Note: This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
*/

/*
Algorithm

1. Find the inorder vector of the tree and then use two pointer approach on the ans.
2. We keep the first pointer at 0 index and 2nd pointer at 1 index and calculate the diff,
if the diff is smaller than the min we already have, we store this diff in min
3. This is repeated till we reach the end of the array and then 

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
    int minDiffInBST(TreeNode* root) {
        vector<int> a;
        inorder(root,a);
        int i=0;
        int j=1;
        int m=100000;
        while (j<a.size()){
            if (a[j]-a[i]<m){
                m= a[j]-a[i];
            }
            i++;
            j++;
        }
        return m;
    }
};
