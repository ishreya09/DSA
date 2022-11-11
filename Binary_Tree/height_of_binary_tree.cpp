/*
Height of Binary Tree
Medium

https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

Given a binary tree, find its height.


Example 1:

Input:
     1
    /  \
   2    3
Output: 2
Example 2:

Input:
  2
   \
    1
   /
 3
Output: 3   

Your Task:
You don't need to read input or print anything. Your task is to complete the function height() which takes 
root node of the tree as input parameter and returns an integer denoting the height of the tree. If the tree is empty, return 0. 


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105

*/

/*
Algorithm

1. Treat left subtree as another tree with root as root->left and right subtree as another tree with root as root->right
2. So we make 2 recursive calls to the same function, once with right child as root and once with left child as root
3. Whichever is maximum, we keep adding one to it and we return zero if root becomes null (base condition)

*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* root){
        // code here 
        if(root ==NULL ){ // when root is null, we don't need to count that node
            return 0;
        }
        
        return max<int>(height(root->left),height(root->right))+1; 
    }
};