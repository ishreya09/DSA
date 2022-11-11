/*
1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
Easy

https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree

Given two binary trees original and cloned and given a reference to a node target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two trees or the target node and the answer must be 
a reference to a node in the cloned tree.

 

Example 1:


Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node 
from the original tree. The answer is the yellow node from the cloned tree.
Example 2:


Input: tree = [7], target =  7
Output: 7
Example 3:


Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
Output: 4
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
The values of the nodes of the tree are unique.
target node is a node from the original tree and is not null.
 

Follow up: Could you solve the problem if repeated values on the tree are allowed?


*/

/*
Algorithm

1. If cloned==Null, return NULL
2. if target->val == cloned->val, return NULL
3. Then traverse the left subtree and then the right subtree and check if which one is not NULL and return that 
node, otherwise return null.

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(cloned==NULL){
            return NULL;
        }
        if (target->val == cloned->val){
            return cloned;
        }
        TreeNode *left = getTargetCopy(original,cloned->left,target);
        TreeNode *right = getTargetCopy(original,cloned->right,target);
        if (left!=NULL){
            return left;
        }
        else if(right!=NULL){
            return right;
        }
        else{
            return NULL;
        }
    }
};