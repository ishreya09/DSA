/*
Multiply two linked lists
Easy

https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1?page=1&status[]=unsolved&category[]=Linked%20List&sortBy=submissions

Given elements as nodes of the two linked lists. The task is to multiply these two linked lists, say L1 and L2. 

Note: The output could be large take modulo 109+7.

Example:

Input:
2
2
3 2
1
2
3
1 0 0
2
1 0 
Output:
64
1000

Explanation:
Testcase 1: 32*2 = 64.
Testcase 2: 100*10 = 1000.
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow, the first line of each test case contains an integer N denoting the size of the first linked list (L1). In the next line are the space-separated values of the first linked list. The third line of each test case contains an integer M denoting the size of the second linked list (L2). In the fourth line is space-separated values of the second linked list.

Output:
For each test case output will be an integer denoting the product of the two linked lists.

Your Task:
The task is to complete the function multiplyTwoLists() which should multiply the given two linked lists and return the result.

Constraints:
1 <= T <= 100
1 <= N, M <= 100
 


*/

/*
Algorithm

1. take mod at each step
2. Get the number in long long format
3. At last multiply it and return it after doing mod
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
long long  multiplyTwoLists (Node* first, Node* second)
{
  //Your code here
   long long N= 1000000007;
    long long num1 = 0, num2 = 0;
    while (first || second){
          
        if(first){
            num1 = ((num1)*10)%N + first->data;
            first = first->next;
        }
          
        if(second)
        {
            num2 = ((num2)*10)%N + second->data;
            second = second->next;
        }
          
    }
    return ((num1%N)*(num2%N))%N;
  
}