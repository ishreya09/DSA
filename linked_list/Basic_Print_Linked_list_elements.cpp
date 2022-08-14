/*
Print Linked List elements
Basic

https://practice.geeksforgeeks.org/problems/print-linked-list-elements/1?page=1&difficulty[]=-2&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a linked list. Print all the elements of the linked list.

Example 1:

Input:
N=2
LinkedList={1 , 2}
Output:
1 2
Explanation:
The linked list contains two 
elements 1 and 2.The elements 
are printed in a single line.
Example 2:

Input:
N = 3
Linked List = { 49, 10, 30}
Output: 
49 10 30
Explanation:
The linked list contains 3 
elements 49, 10 and 30. The 
elements are printed in a single 
line.
Your task:
You don't need to read input or print anything. Your task is to complete the function display() which takes the head of the linked list as input and prints the linked list in a single line.
 
Expected Time Complexity : O(N)
Expected Auxiliary Space : O(1)
 
Constraints :
1 <= N <= 100

*/

/*
Algorithm
1. traverse through the linked list and print the data

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x){
        data =x;
        next = NULL;
    }
};

class Solution
{
    public:
    void display(Node *head)
    {
      //your code goes here

      while(head!=NULL){
          cout<< head->data<< " ";
          head= head->next;
      }
      cout<<endl;
    }
};