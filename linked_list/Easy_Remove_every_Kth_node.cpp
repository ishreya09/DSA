/*
Remove every k'th node
Easy

https://practice.geeksforgeeks.org/problems/remove-every-kth-node/1?page=2&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a singly linked list, your task is to remove every kth node from the linked list.

Input:
The first line of input contains number of test cases T. Then T test cases follow. 
Every test case contains 3 lines. First line of every test case contains an integer 
N denoting the size of the linked list . The second line contains N space separated 
values of the linked list. The third line contains an integer K.

Output:
Output for each test case will be space separated values of the nodes of the new transformed linked list.

User Task:
The task is to complete the function deleteK() which should delete every kth nodes from the linked list.

Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= element of linked list <= 1000
0 <= k <= 100

Example:
Input:
2
8
1 2 3 4 5 6 7 8
3
4
1 2 3 4
2

Output:
1 2 4 5 7 8
1 3

Explanation:
Testcase 1: After removing every 3rd element from the linked list, we have updated list 
as 1, 2, 4, 5, 7 and 8, and the elements which are removed are 3 and 6.

*/

/*
Algorithm

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


/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */

Node* deleteK(Node *head,int K)
{
  //Your code here
  int c=1;
  if (K==1){
      return NULL;
  }
  if (K==0){
      return head;
  }
  Node *temp=head;
  Node*prev = head;
  while(temp!= NULL){
      if(c%K ==0){
          // Delete the node
          prev->next= temp->next;
          delete (temp);
        //   continue;
      }
      if (c%K !=0)
        prev=temp;
      temp=prev->next;
      c++;
  }
  return head;
}
