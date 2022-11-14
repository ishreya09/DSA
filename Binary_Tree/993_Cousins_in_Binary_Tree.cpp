/*
993. Cousins in Binary Tree
Easy

https://leetcode.com/problems/cousins-in-binary-tree/description/

Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, 
return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.


Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:


Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Constraints:

The number of nodes in the tree is in the range [2, 100].
1 <= Node.val <= 100
Each node has a unique value.
x != y
x and y are exist in the tree.

*/

/*
Algorithm

1. Do level order traversal using a queue and store the depth and parent of nodes x and y.
2. If depth is same and parents are not same - we return true.

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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        int dx=0,dy=0,d=0;
        TreeNode* px;
        TreeNode* py;
        while(!q.empty()){
            int n= q.size();
            cout<<n<<"\n";
            d++;
            while(n--){
                auto node = q.front();
                q.pop();
                if(x==node->val){
                    dx=d; // storing depth
                }
                else if(y==node->val){
                    dy=d;
                }
                if(node->left){
                    if(node->left->val==x){// storing parents
                        px=node;
                    }
                    else if(node->left->val==y){
                        py=node;
                    }
                    q.push(node->left);
                }
                if(node->right){
                    if(node->right->val==x){ // storing parents
                        px=node;
                    }
                    else if(node->right->val==y){
                        py=node;
                    }
                    q.push(node->right);
                }
            }
        }
        cout<<dx<<" "<< dy<<endl;
        return dx==dy && px!=py;
        
    }
};