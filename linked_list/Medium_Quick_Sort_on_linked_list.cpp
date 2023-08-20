/*
Quick Sort on Linked List
Medium

https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1?page=2&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Sort the given Linked List using quicksort. which takes O(n^2) time in worst case and O(nLogn) in average and best cases, otherwise you may get TLE.

Input:
In this problem, method takes 1 argument: address of the head of the linked list. The function should not read any input from stdin/console.
The struct Node has a data part which stores the data and a next pointer which points to the next element of the linked list.
There are multiple test cases. For each test case, this method will be called individually.

Output:
Set *headRef to head of resultant linked list.

User Task:
The task is to complete the function quickSort() which should set the *headRef to head of the resultant linked list.

Constraints:
1<=T<=100
1<=N<=200

Note: If you use "Test" or "Expected Output Button" use below example format

Example:
Input:
2
3
1 6 2
4
1 9 3 8

Output:
1 2 6
1 3 8 9

Explanation:
Testcase 1: After sorting the nodes, we have 1, 2 and 6.
Testcase 2: After sorting the nodes, we have 1, 3, 8 and 9.
*/

/*
Algorithm

1. Call partition function to get a pivot node placed at its correct position
    a) In the partition function, the last element is considered a pivot
    b) Then traverse the current list and if a node has a value greater than the pivot, 
    then move it after the tail. If the node has a smaller value, then keep it at its current position. 
    c) Return pivot node
2. Find the tail node of the list which is on the left side of the pivot and recur for the left list
3. Similarly, after the left side, recur for the list on the right side of the pivot
4. Now return the head of the linked list after joining the left and the right list, as the whole 
linked list is now sorted

Time Complexity: O(N * log N), It takes O(N2) time in the worst case and O(N log N) in the average or best case.
Auxiliary Space: O(N), As extra space is used in the recursion call stack.
*/

#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* next;

    node(int x){
        data =x;
        next = NULL;
    }
};

// Returns the last node of the list
struct node* getTail(struct node* cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
  
// Partitions the list taking the last element as the pivot
struct node* partition(struct node* head, struct node* end,
                       struct node** newHead,
                       struct node** newEnd)
{
    struct node* pivot = end;
    struct node *prev = NULL, *cur = head, *tail = pivot;
  
    // During partition, both the head and end of the list
    // might change which is updated in the newHead and
    // newEnd variables
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            // First node that has a value less than the
            // pivot - becomes the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;
  
            prev = cur;
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change
            // tail
            if (prev)
                prev->next = cur->next;
            struct node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
  
    // If the pivot data is the smallest element in the
    // current list, pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;
  
    // Update newEnd to the current last node
    (*newEnd) = tail;
  
    // Return the pivot node
    return pivot;
}
  
// here the sorting happens exclusive of the end node
struct node* quickSortRecur(struct node* head,
                            struct node* end)
{
    // base condition
    if (!head || head == end)
        return head;
  
    node *newHead = NULL, *newEnd = NULL;
  
    // Partition the list, newHead and newEnd will be
    // updated by the partition function
    struct node* pivot
        = partition(head, end, &newHead, &newEnd);
  
    // If pivot is the smallest element - no need to recur
    // for the left part.
    if (newHead != pivot) {
        // Set the node before the pivot node as NULL
        struct node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
  
        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);
  
        // Change next of last node of the left half to
        // pivot
        tmp = getTail(newHead);
        tmp->next = pivot;
    }
  
    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);
  
    return newHead;
}
  
// The main function for quick sort. This is a wrapper over
// recursive function quickSortRecur()
void quickSort(struct node** headRef)
{
    (*headRef)
        = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
