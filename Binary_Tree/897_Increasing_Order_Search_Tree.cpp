/*
897. Increasing Order Search Tree
Easy

https://leetcode.com/problems/increasing-order-search-tree/description/

Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node 
in the tree is now the root of the tree, and every node has no left child and only one right child.

 

Example 1:


Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
Example 2:


Input: root = [5,1,7]
Output: [1,null,5,null,7]
 

Constraints:

The number of nodes in the given tree will be in the range [1, 100].
0 <= Node.val <= 1000

*/

/*
Algorithm

1. Do the inorder traversal for the Binary tree and add the order into a vector
2. Traverse through the vector and make a singly linked list using right pointer as the next.

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
    void inorder(TreeNode* root, vector<int> &ans){
        if (root==NULL){
            return ;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> a;
        inorder(root, a);
        int i=0;
        TreeNode *head =NULL;
        while (i<a.size()){
            TreeNode *temp = new TreeNode(a[i]);
            if (head==NULL){
                head= temp;
            }
            else {
                TreeNode * start=head;
                while (start->right!=NULL){
                    start= start->right;
                }
                start->right=temp;
            }
            i++;
        }
        return head;
    }
};