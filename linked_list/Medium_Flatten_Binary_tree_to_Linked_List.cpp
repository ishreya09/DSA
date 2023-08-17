/*
Flatten binary tree to linked list
Medium

https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1?page=1&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same Node class where the right child pointer points to the next   
node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
Example 1:

Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output :
1 2 3 4 5 6 
Explanation: 
After flattening, the tree looks 
like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 2 3 4 5 6.
Example 2:

Input :
        1
       / \
      3   4
         /
        2
         \
          5 
Output : 
1 3 4 2 5  
Explanation : 
After flattening, the tree looks 
like this 
     1
      \
       3
        \
         4
          \
           2
            \ 
             5 
Here, left of each node points 
to NULL and right contains the 
next node in preorder.The inorder 
traversal of this flattened tree 
is 1 3 4 2 5.
Your task:
You don't have to read input or print anything. Your task is to complete the function flatten() 
which takes the root of the tree and flattens the tree into a linkes list without using any auxiliary space.
Note : The driver code prints the inorder traversal of the flattened binary tree.
 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
 
Constraints :
1<=n<=10^5

*/

/*
Algorithm

1. It is similar to Binary tree to DLL 
2. For this - we need the order as preorder which is root left right
3. So we recurse in opposite direction making rightmost as the head and then leftmost and then finally the root
4. Make sure that root->right =head where head is the  most recent 
visited node after the recursion stack starts to backtrack and root is the current node 
(in a way -1st rightmost node then 2nd rightmost node and then so on)
5. We do head = root so that we move the head to the most recent visited element in recursion stack.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data =x;
    }
};



class Solution
{
    public:
    void flattenrec(Node *root,Node* &head){
        if (root==NULL ){
            return;
        }
        flattenrec(root->right,head);
        flattenrec(root->left,head);
        root->right=head; 
        root->left=NULL;
        if(head!=NULL){
            head->left=NULL;
        }
        head=root;
    }

    void flatten(Node *root)
    {
        //code here
        Node* head=NULL;
        flattenrec(root,head);
        // root=head;
    }
};


/*
Alternative Algorithm

1. Recursively look for node with no grandchildren and both left and right in left subtree.
2. Then store node->right in tmp and make node->right= node->left.
3. Insert tmp in first node NULL on right of node by node=node->right. 
4. Repeat until converted to linked list

Space : Recursion stack space
Time Complexity :  O(n)
*/
void Flatten(Node* root){
    if (root==NULL || !root->left && !root->right)
        return;
    // if root->left exists then we have to make it root->right
    if (root->left!=NULL){
        Flatten(root->left);
        Node *tmp= root->right;
        root->right = root->left;
        root->left=NULL;
        // find pos to store and insert
        Node *t=root->right;
        while (t->right!=NULL){
            t=t->right;
        }
        // Insert the stored val
        t->right=tmp;

    }
    Flatten(root->right);
}

