/*
Node at a given index in linked list
Basic

https://practice.geeksforgeeks.org/problems/node-at-a-given-index-in-linked-list/1?page=2&difficulty[]=-2&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a singly linked list with N nodes and a number X. The task is to find the node at the given index (X)(1 based index) of linked list. 

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains space seperated two integers, length of linked list and X.

Output:
For each testcase, there will be single line of output containing data at Xth node.

User Task:
The task is to complete the function GetNth() which takes head reference and index as arguments and should return the data at Xth position in the linked list.

Constraints:
1 <= T <= 30
1 <= N <= 100
K <= N
1 <= value <= 103

Example:
Input:
2
6 5
1 2 3 4 657 76
10 2
8 7 10 8 6 1 20 91 21 2

Output:
657
7

Explanation:
Testcase 1: Element at 5th index in the linked list is 657 (1-based indexing).

*/

/*
Algorithm

1. Keep an index i starting from 1 and go on incrementing as we traverse through the elements
2. return the data when index == i

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


// Should return data of node at given index. The function may
//  assume that there are at least index+1 nodes in linked list
int GetNth(struct Node* head, int index){
  // Code here
  int i=1;
  while(head!=NULL){
      if (i==index){
          return head->data;
      }
      head = head->next;
      i++;
  }
}
