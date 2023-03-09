/*
 1315. Sum of Nodes with Even-Valued Grandparent
Medium

https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/description/

Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. 
If there are no nodes with an even-valued grandparent, return 0.

A grandparent of a node is the parent of its parent if it exists.

Example 1:
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 18
Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.

Example 2:
Input: root = [1]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 100
*/

/*
Algorithm

1. initialise a global variable sum equal to 0
2. if we reach null(after a leaf node) return 0 as it does not count into the tree
3. if root->val is even - check if it has left and right child and if those nodes have their left and right child- add 
them to sum - otherwise recursively call left and right subtree like in dfs
4. return sum in the end.

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
    int sum=0;  //global variable
    int sumEvenGrandparent(TreeNode* root) {
        
      if(!root) return 0;
       
        if(root->val%2==0)  // if grandparent is even
        {
           if(root->left)     // when root->left is present  , add values of grandchildren to sum if present
             {
              if(root->left->left) sum+=root->left->left->val;  
              if(root->left->right) sum+=root->left->right->val;
             }
           if(root->right)     // when root->right is present  , add values of grandchildren to sum if present
             {
              if(root->right->left) sum+=root->right->left->val;
              if(root->right->right) sum+=root->right->right->val;
             }
        }
        sumEvenGrandparent(root->left);  //traverse to left subtree
        sumEvenGrandparent(root->right); //traverse to right subtree
        
        return sum;
    }
};