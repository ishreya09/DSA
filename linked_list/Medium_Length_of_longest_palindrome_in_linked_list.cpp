/*
Length of longest palindrome in linked list
Medium

https://practice.geeksforgeeks.org/problems/length-of-longest-palindrome-in-linked-list/1?page=1&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given a linked list, the task is to complete the function maxPalindrome() which returns an integer 
denoting  the length of the longest palindrome list that exist in the given linked list.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains an integer N denoting the size of the linked list . 
Then in the next line are N space separated values of the given linked list.

Output:
For each test case output will be the required max length of the palindrome present in the given linked list.

User Task:
The task is to complete the function maxPalindrome() which should count the length of longest palindrome in the 
given list and return it.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
7
2 3 7 3 2 12 24
5
12 4 4 3 14

Output:
5
2

Explanation:
Testcase 1: 2 -> 3 -> 7 -> 3 -> 2 is the linked list whose nodes leads to a palindrome as 2 3 7 3 2.

*/

/*
Algorithm

A simple solution could be to copy linked list content to array and 
then find the longest palindromic subarray in the array, but this 
solution is not allowed as it requires extra space.

1. The idea is based on iterative linked list reverse process. 
2. We iterate through the given a linked list and one by one reverse 
every prefix of the linked list from the left. 
3. After reversing a prefix, we find the longest common list beginning from reversed prefix and 
the list after the reversed prefix. 

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


// function for counting the common elements
int countCommon(Node *a, Node *b)
{
    int count = 0;
 
    // loop to count common in the list starting
    // from node a and b
    for (; a && b; a = a->next, b = b->next){
 
        // increment the count for same values
        if (a->data == b->data)
            ++count;
        else
            break;
    }
    return count;
}
 
// Returns length of the longest palindrome
// sublist in given list
int maxPalindrome(Node *head)
{
    int result = 0;
    Node *prev = NULL, *curr = head;
 
    // loop till the end of the linked list
    while (curr)
    {
        // The sublist from head to current
        // reversed.
        Node *next = curr->next;
        curr->next = prev;
 
        // check for odd length palindrome
        // by finding longest common list elements
        // beginning from prev and from next (We
        // exclude curr)
        result = max(result,
                     2*countCommon(prev, next)+1);
 
        // check for even length palindrome
        // by finding longest common list elements
        // beginning from curr and from next
        result = max(result,
                     2*countCommon(curr, next));
 
        // update prev and curr for next iteration
        prev = curr;
        curr = next;
    }
    return result;
}
