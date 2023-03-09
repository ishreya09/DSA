/*
1302. Deepest Leaves Sum
Medium

https://leetcode.com/problems/deepest-leaves-sum/description/

Given the root of a binary tree, return the sum of values of its deepest leaves.
 

Example 1:


Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 100

*/

/*
Algorithm

1. Do a level order traversal
2. Calculate sum for each level and return the sum directly as 
the last sum calculated will be the deepest leaf nodes sum.

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
    int deepestLeavesSum(TreeNode* root) {
        // do level order traversal 
        queue<TreeNode* > q;
        q.push(root);
        int s=0;
        while(!q.empty()){
            int n= q.size();
            s=0;
            while(n--){
                s+= q.front()->val;
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
            }

        }
        return s;
    }
};