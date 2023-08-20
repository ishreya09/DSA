/*
Partition a Linked List around a given value
Medium

https://practice.geeksforgeeks.org/problems/partition-a-linked-list-around-a-given-value/1?page=2&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given a linked list and a value x, partition it such that all nodes less than x come first, 
then all nodes with value equal to x and finally nodes with value greater than x. 
The original relative order of the nodes in each of the three partitions should be preserved. 
The partition must work in-place.
 
Example 1:
Input:
1->4->3->2->5->2->3,
x = 3
Output:
1->2->2->3->3->4->5
Explanation: 
Nodes with value less than 3 come first, 
then equal to 3 and then greater than 3.
Example 2:
Input:
1->4->2->10 
x = 3
Output: 
1->2->4->10
Explanation:
Nodes with value less than 3 come first,
then equal to 3 and then greater than 3.
Your task:
You don't need to read input or print anything. Your task is to complete the function partition()
 which takes the head of the inked list and an integer x as input, and returns the head of the 
 modified linked list after arranging the values according to x.
 
Expected time complexity : O(n)
Expected Auxiliary Space: O(n)
 
Constraints:
1 <= N <= 105
1 <= k <= 105


*/

/*
Algorithm


1) Initialize first and last nodes of below three linked lists as NULL. 
    a) Linked list of values smaller than x.
    b) Linked list of values equal to x.
    c) Linked list of values greater than x.
2) Now iterate through the original linked list. If a node’s value is less than x then 
append it at the end of the smaller list. If the value is equal to x, then at the end 
of the equal list. And if a value is greater, then at the end of the greater list.
3) Now concatenate three lists.

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

// Function to make two separate lists and return
// head after concatenating
struct Node* partition(struct Node* head, int x)
{
    /* Let us initialize first and last nodes of
      three linked lists
        1) Linked list of values smaller than x.
        2) Linked list of values equal to x.
        3) Linked list of values greater than x.*/
    struct Node *smallerHead = NULL, *smallerLast = NULL;
    struct Node *greaterLast = NULL, *greaterHead = NULL;
    struct Node *equalHead = NULL, *equalLast = NULL;
  
    // Now iterate original list and connect nodes
    // of appropriate linked lists.
    while (head != NULL) {
        // If current node is equal to x, append it
        // to the list of x values
        if (head->data == x) {
            if (equalHead == NULL)
                equalHead = equalLast = head;
            else {
                equalLast->next = head;
                equalLast = equalLast->next;
            }
        }
  
        // If current node is less than X, append
        // it to the list of smaller values
        else if (head->data < x) {
            if (smallerHead == NULL)
                smallerLast = smallerHead = head;
            else {
                smallerLast->next = head;
                smallerLast = head;
            }
        }
        else // Append to the list of greater values
        {
            if (greaterHead == NULL)
                greaterLast = greaterHead = head;
            else {
                greaterLast->next = head;
                greaterLast = head;
            }
        }
  
        head = head->next;
    }
  
    // Fix end of greater linked list to NULL if this
    // list has some nodes
    if (greaterLast != NULL)
        greaterLast->next = NULL;
  
    // Connect three lists
  
    // If smaller list is empty
    if (smallerHead == NULL) {
        if (equalHead == NULL)
            return greaterHead;
        equalLast->next = greaterHead;
        return equalHead;
    }
  
    // If smaller list is not empty and equal list is empty
    if (equalHead == NULL) {
        smallerLast->next = greaterHead;
        return smallerHead;
    }
  
    // If both smaller and equal list are non-empty
    smallerLast->next = equalHead;
    equalLast->next = greaterHead;
    return smallerHead;
}