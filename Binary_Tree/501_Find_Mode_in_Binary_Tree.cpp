/*
501. Find Mode in Binary Search Tree
Easy

https://leetcode.com/problems/find-mode-in-binary-search-tree/description/

Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., 
the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [1,null,2,2]
Output: [2]
Example 2:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
 

Follow up: Could you do that without using any extra space? 
(Assume that the implicit stack space incurred due to recursion does not count).

*/

/*
Algorithm

1. Make a map and call the count function. The count function counts the frequency of the nodes in a map
2. For count function - we add the root node's freq in the map and then move left and then right.
3. We then check the maximum frequency, and then store all elements with same frequency into the vector.

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
    void count(TreeNode* root, map<int,int> &f){
        if(root==NULL){
            return;
        }
        f[root->val]++;
        count(root->left,f);
        count(root->right,f);
    }
    vector<int> findMode(TreeNode* root) {
        map<int, int> f;
        count(root,f);
        int m= 0;
        vector<int> val;
        for(auto i= f.begin(); i!= f.end();i++){
            if (m< i->second){
                m=i->second;
            }
        }
        for(auto i= f.begin(); i!= f.end();i++){
            if (m== i->second){
                val.push_back(i->first);
            }
        }
        return val;
    }
};