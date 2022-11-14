/*
653. Two Sum IV - Input is a BST
Easy

https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

Given the root of a Binary Search Tree and a target number k, return true if there exist two elements 
in the BST such that their sum is equal to the given target.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-10^5 <= k <= 10^5

*/

/*
Algorithm

1. Do Inorder traversal of the BST. We will get a acending order array.
2. We use two pointer approach in this array to find the two elements which is equal to k
3. If we find a pair, we return true, else false otherwise.

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
    bool findTarget(TreeNode* root, int k) {
        vector<int> a;
        inorder(root,a);
        int i=0,j=a.size()-1;
        while (i<j){
            if (a[i]+a[j]==k){
                return true;
            }
            else if(a[i]+a[j]>=k){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};