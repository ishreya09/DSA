/*
637. Average of Levels in Binary Tree
Easy

https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. 
Answers within 10-5 of the actual answer will be accepted.
 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].
Example 2:


Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-2^31 <= Node.val <= 2^31 - 1

*/

/*
Algorithm

1. Do level order traversal with a queue and the length of the queue will give us the number of nodes in that particular level.
2. We add the root node in the queue. Since the queue is not empty and size is 1, we add the children of root and then also find
the avg of the nodes in the level and append it to ans( vector<double>) using another vector of int values and we repeat the process
until the queue is empty.
3. At the end, we return the vector of ans.

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            vector<double> temp;
            int i=0;
            int a= q.size();
            while(i<a){
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node->val);

                /* Enqueue left child */
                if (node->left != NULL)
                    q.push(node->left);
        
                /*Enqueue right child */
                if (node->right != NULL)
                    q.push(node->right);
                i++;

            }
            double sum=accumulate(temp.begin(),temp.end(),0.0)/a;
            ans.push_back(sum);
            
        }  
        return ans;      
    }
};