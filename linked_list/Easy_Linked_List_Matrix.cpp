/*
Linked List Matrix
Easy

https://practice.geeksforgeeks.org/problems/linked-list-matrix/1?page=3&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a Matrix mat of N*N size, the task is to complete the function constructLinkedMatrix(), that constructs a 2D linked list representation of the given matrix.

Input : 2D matrix 
1 2 3
4 5 6
7 8 9

Output :
1 -> 2 -> 3 -> NULL
|    |    |
v    v    v
4 -> 5 -> 6 -> NULL
|    |    |
v    v    v
7 -> 8 -> 9 -> NULL
|    |    |
v    v    v
NULL NULL NULL
Input:
The fuction takes 2 argument as input, first the 2D matrix mat[][] and second an integer variable N, denoting the size of the matrix.
There will be T test cases and for each test case the function will be called separately.

Output:
The function must return the reference pointer to the head of the linked list.

Constraints:
1<=T<=100
1<=N<=150

Example:
Input:
2
3
1 2 3 4 5 6 7 8 9
2
1 2 3 4
Output:
1 2 3 4 5 6 7 8 9
1 2 3 4

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used 
by a user for Expected Output only. As it is a function problem, hence a user should not read any input 
from stdin/console. The task is to complete the function specified, and not to write the full code.

*/

/*
Algorithm

1. Create a head pointer pointing to first element
2. Create a row pointer that will point to the row's first element when j==0
3. create a loop where j<n and keep on adding nodes of right and down and traverse through the linked list by going right
using temp pointer
4. When j==n - increment i and initialize j=0 and put the temp pointer pointing to row pointer and loop 
through the above steps again


*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* right;
    struct Node* down;


    Node(int x){
        data =x;
        right = NULL;
        down = NULL;
    }
};


// n is the size of the matrix
// function must return the pointer to the first element 
// of the in linked list i.e. that should be the element at arr[0][0]
// MAX =20
#define MAX 20

Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    // code here
    Node *head= new Node(mat[0][0]);
    Node *rowptr= head;
    Node *temp =  head;
    int i=0,j=0;
    while (i<n){
        if (j<n){
            Node *right =(j+1<n) ? new Node(mat[i][j+1]) : NULL ;
            Node *down = (i+1<n) ? new Node(mat[i+1][j]) : NULL ;
            if (j==0){
                rowptr = down;
            }
            temp->right = right;
            temp->down = down;
            temp = temp->right;
            j++;
            continue;
        }
        if (j==n){
            j=0;
            i++;
            temp= rowptr;
        }
    }
    return head;
    
}
