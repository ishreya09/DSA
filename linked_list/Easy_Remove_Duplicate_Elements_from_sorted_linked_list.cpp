/*
Remove duplicate element from sorted Linked List
Easy

https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1?page=1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.

Example 1:

Input:
LinkedList: 2->2->4->5
Output: 2 4 5
Explanation: In the given linked list
2 ->2 -> 4-> 5, only 2 occurs more
than 1 time.
Example 2:

Input:
LinkedList: 2->2->2->2->2
Output: 2
Explanation: In the given linked list
2 ->2 ->2 ->2 ->2, 2 is the only element
and is repeated 5 times.
Your Task:
The task is to complete the function removeDuplicates() which should remove the duplicates
from linked list and return the head of the linkedlist.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= Number of nodes <= 104

*/

/*
Algorithm

1. Create a map to see the frequency of the members
2. If the frequency of a number is greater than 1, then delete that particuar node.
3. Maintain a prev and next(here temp) pointers so as to remove the node from the linked list
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

// Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    // your code goes here
    Node *temp = head;
    Node *prev = head; // to store previous node data

    map<int, int> freq;
    while (temp != NULL)
    {
        freq[temp->data]++;
        if (freq[temp->data] > 1)
        {
            // delete temp node
            prev->next = temp->next;

            Node *del = temp;
            delete (del);
            del = NULL;
            temp = prev->next;
            continue;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}
