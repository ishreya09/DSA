/*
Insert in a Sorted List
Easy

https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1?page=2&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a linked list sorted in ascending order and an integer called data, insert data in the linked list such that the list remains sorted.

Example 1:

Input:
LinkedList: 25->36->47->58->69->80
data: 19
Output: 19 25 36 47 58 69 80
Example 2:

Input:
LinkedList: 50->100
data: 75
Output: 50 75 100
Your Task:
The task is to complete the function sortedInsert() which should insert the element in sorted Linked List and return the head of the linked list

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 104
-99999 <= A[i] <= 99999, for each valid i

*/

/*
Algorithm

1. if head is equal to NULL, then set head to new node
2. If head's data is greater than new node's data, add data at the head and set temp->next to head and 
make head point to temp
3. If the above two cases is not there, then traverse to the linked list until we reach such that temp->next->data<data
(do not move to next pointer unless the data is less than the data we want to push)
once we find a node which has greater data than the data that needs to be inserted/ or we reach the end of the list, 
we set temp->next as current node's next and make current node point to temp.

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


class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code 
        // insertion at head
        Node *temp= new Node (data);
        if (head==NULL){
            head= temp;
        }
        else if(head->data > data){
            // insertion at head 
            temp->next = head;
            head= temp;
        }
        else{
            Node *cur=head;
            while(cur->next!=NULL && cur->next->data < data){
                cur= cur->next;
            }
            temp->next = cur->next;
            cur->next= temp;
        }
        return head;
    }
};
