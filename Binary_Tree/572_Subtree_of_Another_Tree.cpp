/*
572. Subtree of Another Tree
Easy

https://leetcode.com/problems/subtree-of-another-tree/description/

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same
structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants.
The tree tree could also be considered as a subtree of itself.



Example 1:


Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
Example 2:


Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false


Constraints:

The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-104 <= root.val <= 104
-104 <= subRoot.val <= 104


*/

/*
Algorithm

1. In issubtree function - traverse till the head node of subtree and the head node of the tree becomes the same
and then call issametree function
2. In issametree () - traverse through the tree and subtree in same direction and check if the value is same or not-
if not- return false - otherwise recursively call the left and right child of the tree. If tree and subtree node reach the null
nodes simentaneously, then return true, else false. 
3. In issubtree function - if root is null - return false directly.

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
    bool isSametree(TreeNode *s, TreeNode *t)
    {
        // if any of the tree is null then there is no need to compare
        if (!s || !t)
        {
            // if either of them are null both of them need to be null to be true
            return s == NULL && t == NULL;
        } // now since both are not null check if they have same value otherwise return false
        else if (s->val == t->val)
        {
            // if value is same then check if both its left and right sub-tree are same
            return isSametree(s->left, t->left) && isSametree(s->right, t->right);
        }
        else
        {
            return false;
        }
    }
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (!s)
        {
            // if main tree is null then return false
            return false;
        }
        else if (isSametree(s, t))
        {
            // check if s and t are same, if yes return true
            return true;
        }
        else
        {
            // if s and t are not same then pass left and right nodes, and check same for that nodes as well 
            // as its child nodes.
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }
};
