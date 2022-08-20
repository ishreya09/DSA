/*
Occurence of an integer in a Linked List
Easy

https://practice.geeksforgeeks.org/problems/occurence-of-an-integer-in-a-linked-list/1?page=2&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a singly linked list and a key, count the number of occurrences of given key in the linked list.

Example 1:

Input:
N = 7
Link List = 1->2->1->2->1->3->1
search_for = 1
Output: 4
Explanation:1 appears 4 times.
Example 2:

Input:
N = 5
Link List = 1->2->1->2->1
search_for = 3
Output: 0
Explanation:3 appears 0 times.

Your Task:
You dont need to read input or print anything. Complete the function count() which 
takes the head of the link list and search_for i.e- the key as input parameters and 
returns the count of occurrences of the given key.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
0 ≤ N ≤ 10^4

*/

/*
Algorithm

1. Keep a count =0 and traverse through the linked list
2. If head->data == value, then increment count

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
    int count(Node* head, int search_for)
    {
    //add your code here
    int count=0;
    while (head!= NULL){
        if (head->data ==search_for){
            count++;
        }
        head= head->next;
    }
    return count;
    }
};
