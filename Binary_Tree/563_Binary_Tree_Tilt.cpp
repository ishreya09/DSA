/*
563. Binary Tree Tilt
Easy

https://leetcode.com/problems/binary-tree-tilt/description/

Given the root of a binary tree, return the sum of every tree node's tilt.

The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right 
subtree node values. If a node does not have a left child, then the sum of the left subtree node values is treated as 0. 
The rule is similar if the node does not have a right child.

 

Example 1:


Input: root = [1,2,3]
Output: 1
Explanation: 
Tilt of node 2 : |0-0| = 0 (no children)
Tilt of node 3 : |0-0| = 0 (no children)
Tilt of node 1 : |2-3| = 1 (left subtree is just left child, so sum is 2; right subtree is just right child, so sum is 3)
Sum of every tilt : 0 + 0 + 1 = 1
Example 2:


Input: root = [4,2,9,3,5,null,7]
Output: 15
Explanation: 
Tilt of node 3 : |0-0| = 0 (no children)
Tilt of node 5 : |0-0| = 0 (no children)
Tilt of node 7 : |0-0| = 0 (no children)
Tilt of node 2 : |3-5| = 2 (left subtree is just left child, so sum is 3; right subtree is just right child, so sum is 5)
Tilt of node 9 : |0-7| = 7 (no left child, so sum is 0; right subtree is just right child, so sum is 7)
Tilt of node 4 : |(3+5+2)-(9+7)| = |10-16| = 6 (left subtree values are 3, 5, and 2, which sums to 10; right 
subtree values are 9 and 7, which sums to 16)
Sum of every tilt : 0 + 0 + 0 + 2 + 7 + 6 = 15
Example 3:


Input: root = [21,7,14,1,1,2,2,3,3]
Output: 9
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000

*/

/*
Algorithm

1. Firstly, we change the nodes, by calculating the tilt for each node. We start by bottom up approach.
we make makeTilt function in recurrsive logic. We find the sum of the left nodes and the right nodes and change the value on the abs difference
of left and right sum values.
If we reach to the null, we return null. So all the leaf nodes will have their values as 0. We add the original value to sum 
and then update the root->val and return that sum.
2. We make a calculate function to calculate the sum once we make the tree tilted. We add the root's value and recurrsively call
the same for right and left nodes.
3. We return the sum at the end.

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
    int calculate(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return root->val+ calculate(root->left)+ calculate(root->right);
    }

    int makeTilt(TreeNode* root) { // we will return sum at each level
        if (!root){
            return 0;
        }
        int l= makeTilt(root->left);
        int r=makeTilt(root->right);
        int sum = l+r+root->val;
        root->val= abs(l-r);
        return sum;
    }
    int findTilt(TreeNode *root){
        makeTilt(root);
        return calculate(root);
    }
};