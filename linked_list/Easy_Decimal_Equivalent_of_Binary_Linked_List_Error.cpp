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

1. reverse the linked list and initialize num as 0
2. take a variable for varying powers of 2 (do not use pow)
3. multiply both the data of the linked list and powers of two in increasing order from 0, and add to num
4. return num % 1000000007

*/

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

const long long unsigned int MOD= 1000000007;

struct Node *reverseList(struct Node *head)
{
    // return head of reversed list
    struct Node *temp = head;
    struct Node *prev = temp;
    struct Node *next = temp->next;

    temp->next = NULL;

    while (temp != NULL && next != NULL)
    {
        temp = next;
        if (temp->next != NULL)
        {

            next = temp->next;
        }
        else
        {
            next = NULL;
        }
        temp->next = prev;
        prev = temp;
    }
    return temp;
}

// Should return decimal equivalent modulo 1000000007 of binary linked list
long long unsigned int decimalValue(Node *head)
{
    // Your Code Here
    if (head == NULL)
    {
        return 0;
    }

    long long unsigned int num = 0;
    head = reverseList(head);
    long long unsigned int p = 1;

    Node *temp = head;
    while (temp != NULL)
    {

        num += temp->data * p;
        // num += (num<<2) +  temp->data;
        // if we write the above line, reversing of the linked list is not required
        p = p * 2;

        temp = temp->next;
        // num = num % 1000000007;
    }

    return num % MOD;
}
