/*
Merge Lists Alternatingly
Easy

https://practice.geeksforgeeks.org/problems/merge-list-alternatingly/1?page=3&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given two linked lists, your task is to complete the function mergeList() which inserts nodes of 
second list into first list at alternate positions of first list.

Input:
First line of input contains number of testcases T. For each testcase there will be 4 lines. First line 
consists of the length of the first linked list, next line contains elements of the linked list inreverse order. 
Third line contains length of another linked list and next line contains elements of the linked list.

Output:
For each test case first print space separated vales of the first linked list, then in the next line print 
space separated values of the second linked list.

User Task:
The task is to complete the function mergeList() which should merge the two lists as required.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
2
9 10
6
5 4 3 2 1 6
5
99 88 77 66 55
5
55 44 33 22 11

Output:
10 6 9 12 3 4 5
55 11 66 22 77 33 88 44 99 55

Explanation:
Testcase 1:

The two linked list are 10 -> 9 and 6 -> 1-> 2 -> 3 -> 4 -> 5

After merging the two lists as required, the new list is like: 10-> 6-> 9-> 1-> 2-> 3-> 4-> 5.



*/

/*
Algorithm

1. take temp pointer pointing to the first list's head
2. Add the nodes from second list's head and traverse through the second linked list
3. and traverse temp skiping one node then as next node currently contains node from q. 

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

// complete this function
void mergeList(struct Node **p, struct Node **q)
{
    // Code here
    Node *temp=(*p);
    Node *c;
    while (temp!= NULL && (*q)!=NULL)
    {
        c= (*q)->next;
        (*q)->next = temp->next;
        temp->next = (*q);
        (*q)= c;
        temp= temp->next->next;
    }
    
}
