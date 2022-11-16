/*
671. Second Minimum Node In a Binary Tree
Easy

https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/

Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in 
this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller 
value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in 
the whole tree.

If no such second minimum value exists, output -1 instead.

 

 

Example 1:


Input: root = [2,2,5,null,null,5,7]
Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:


Input: root = [2,2,2]
Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
 

Constraints:

The number of nodes in the tree is in the range [1, 25].
1 <= Node.val <= 231 - 1
root.val == min(root.left.val, root.right.val) for each internal node of the tree.


*/

/*
Algorithm

1. Create another func to find next minimum and pass root's value as parameter
2. In this func, if we reach null- all numbers are same- so return -1. If we find that the number is different
from the root - return the root's value then and there. - otherwise - make a function( fun() ) and recusively
call the elements on left and right side of the tree.
3. The fun() function - takes 3 parameters, a ,b, root node's value - acts as compare
If both are negative no. return -1.
If a>r and b>r - then return min of a and b
if any one value is greater than r and other is smaller than r- return max of them.


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
    int fun(int a,int b,int r){
        if (a<0 && b<0){
            return -1;
        }
        else if(a>r && b>r){
            return min<int>(a,b);
        }
        else if ((a>r && b<r) || (a<r && b>r) ){
            return max<int> (a,b);
        }
        return 0;
    }
    int SecondMinimumValue(TreeNode* root,int r) {
        if (root==NULL){
            return -1;
        }
        if (root->val != r){
            return root->val;
        }
        if(root->left && root->right){
            return fun(SecondMinimumValue(root->left,r),SecondMinimumValue(root->right,r),r);
        }
        return -1;
    }
    int findSecondMinimumValue(TreeNode* root) {
        return SecondMinimumValue(root,root->val);
    }
};