/*
Binary Tree to CDLL
Medium

https://practice.geeksforgeeks.org/problems/binary-tree-to-cdll/1?page=1&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given a Binary Tree of N edges. The task is to convert this to a Circular Doubly Linked List(CDLL) in-place. 
The left and right pointers in nodes are to be used as previous and next pointers respectively in converted CDLL. 
The order of nodes in CDLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal 
(left most node in BT) must be head node of the CDLL.

Example 1:

Input:
      1
    /   \
   3     2
Output:
3 1 2 
2 1 3
Explanation: After converting tree to CDLL
when CDLL is is traversed from head to
tail and then tail to head, elements
are displayed as in the output.
Example 2:

Input:
     10
   /    \
  20    30
 /  \
40  60
Output:
40 20 60 10 30 
30 10 60 20 40
Explanation:After converting tree to CDLL,
when CDLL is is traversed from head to
tail and then tail to head, elements
are displayed as in the output.
Your Task:
You don't have to take input. Complete the function bTreeToCList() that takes root as 
a parameter and returns the head of the list. The printing is done by the driver code.

Constraints:
1 <= N <= 103
1 <= Data of a node <= 104

Expected time complexity: O(N)

Expected auxiliary space: O(h) , where h = height of tree

*/

/*
Algorithm

1. This was inoder traversal - so we traverse right first- then root and then left
2. we start by making head as the rightmost node and keep inserting at head through root
3. root->right= head sets the next ptr 
and head->left =root for next and prev pointers respectively
4. and then change head to root's position and then traverse the left part of the tree
5. The base condition is if root is NULL - we return

Time COmplexity - O(n)
Space Complexity - O(log n) - O (h) where h is height of the tree

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


class Solution
{
  public:
    void bTreetoCLLR(Node* root,Node* &head){ // inorder -left root right
        if (root==NULL){
            return;
        }
        bTreetoCLLR(root->right,head);
        // root
        root->right=head;
        if(head!=NULL){
            head->left=root;
        }
        head=root;
        bTreetoCLLR(root->left,head);
    }
    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root)
    {
        //add code here.
        Node *head=NULL;
        bTreetoCLLR(root,head);
        Node* last=head;
        while (last!=NULL && last->right!=NULL){
            last=last->right;
        }
        last->right= head;
        head->left= last;
        
        return head;
    }
};