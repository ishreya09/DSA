// some error
/*
Decimal Equivalent of Binary Linked List
Easy

https://practice.geeksforgeeks.org/problems/decimal-equivalent-of-binary-linked-list/1?page=3&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a singly linked list of 0s and 1s, the task is to find its decimal equivalent.
Decimal Value of an empty linked list is considered as 0.

Since the answer can be very large, answer modulo 1000000007 should be printed.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains

Output:
The function should return should decimal equivalent modulo 1000000007.

User Task:
The task is to complete the function decimalValue() which should find the decimal value of
the given binary value in the linked list.

Constraints:
1 <= T <= 200
0 <= N <= 100
Data of Node is either 0 or 1

Example:
Input:
2
3
0 1 1
4
1 1 1 0

Output:
3
14

Explanation:
Testcase 1: 1*20 + 1*21 + 0*22 =  1 + 2 + 0 = 3.


*/

/*
Algorithm

1. take res =0
2. Take right shift into the res every loop (or multiply by 2) and add the data of next node 
3. In the end - we get the required number % MOD

*/
const long long unsigned int MOD= 1000000007;

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Should return decimal equivalent modulo 1000000007 of binary linked list 
long long unsigned int decimalValue(struct Node *head)
{
    long long unsigned int  res = 0;
    while (head != NULL)
    {
        res = ((res  * 2) % MOD + head->data)%MOD; // honestly a bit wrong in calculations
        head = head->next;
    }
    return res;
}