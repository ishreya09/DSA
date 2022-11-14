/*
1022. Sum of Root To Leaf Binary Numbers
Easy

https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/

You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a 
binary number starting with the most significant bit.

For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return
the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.

 

Example 1:


Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
Example 2:

Input: root = [0]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val is 0 or 1.

*/

/*
Algorithm

1. Do dfs and use different states of vector in recursion.
We call the function for left and right if both nodes are present and once if only one of them is present or once if
both are leading to null (leaf node) 
2. Once the root becomes null, we find the binary number from the vector and store it in our another vector.
3. this stores all the possible ways to traverse from root to leaf nodes and We accumulate the values and return them lastly.


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
    //dfs function
    void dfs(TreeNode *root,vector<int> &res,vector<int> ans){
        if (root==NULL){ // root is null- one possibility terminates
            int i=0;
            int n=0;
            while(i<ans.size()){
                n=2*n+ans[i];
                i++;
            }
            res.push_back(n);
            return;
        }
        ans.push_back(root->val);
        if (root->left==NULL && root->right==NULL){
            dfs(root->left,res,ans);
        }
        else if(root->right==NULL ){
            dfs(root->left,res,ans);
        }
        else if(root->left==NULL){
            dfs(root->right,res,ans);
        }
        else{
            dfs(root->left,res,ans);
            dfs(root->right,res,ans);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int> res;
        vector<int> ans;
        dfs(root,res,ans);
        return accumulate(res.begin(),res.end(),0);
    }
};