/*
Intersection of two sorted Linked lists
Easy

https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1?page=1&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given two lists sorted in increasing order, create a new list representing the intersection of the two lists. 
The new list should be made with its own memory — the original lists should not be changed.
Note: The list elements are not necessarily distinct.

Example 1:

Input:
L1 = 1->2->3->4->6
L2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given first two
linked list, 2, 4 and 6 are the elements
in the intersection.
Example 2:

Input:
L1 = 10->20->40->50
L2 = 15->40
Output: 40
Your Task:
The task is to complete the function intersection() which should find the intersection of two 
linked list and add all the elements in intersection to the third linked list and return the head 
of the third linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(n+m)
Note: n,m are the size of the linked lists.

Constraints:
1 <= size of linked lists <= 5000
1 <= Data in linked list nodes <= 1000

*/

/*
Algorithm

1. take a prev pointer and temp pointer for list 1 and traverse list2 simentaneously
2. if temp->data > head2->data - traverse to head2->next (we don't care about the previous head2 node now) 
3. if temp->data < head2->data - then remove the node from the list using prev pointer (prev->next = temp->next ) and
let prev pointer remain to the same position and let temp point to prev->next. In case, temp was a head node, change head1 to 
head1->next and delete temp
4. if temp->data == head2->data - then traverse one place for both temp and head2 and assign prev as previous value of temp

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

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node *temp = head1;
    Node *prev= temp;
    while (temp!=NULL && head2 !=NULL){
        if (temp->data <head2->data){ // surely head1->data is not present
            if (temp==head1){
                head1= head1->next;
                delete(temp);
                temp=head1;
                prev=temp; 
            }
            else{
                prev->next = temp->next;
                delete(temp);
                temp = prev->next;
            }
        } 
        else if(temp->data > head2->data){
            if (temp->next == NULL && head2->next==NULL){
                // detete this temp node
                if (temp==head1){
                    head1= head1->next;
                    delete(temp);
                    temp=head1;
                    prev=temp; 
                }
                else{
                    prev->next = temp->next;
                    delete(temp);
                    temp = prev->next;
                }
                
            }
            head2 = head2->next; // no need to add
        }
        else if (temp->data== head2->data){
            // do nothing
            prev = temp;
            temp= temp->next;
            head2= head2->next;
        }
    }
    return head1;
}