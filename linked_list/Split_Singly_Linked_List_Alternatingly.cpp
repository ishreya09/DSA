/*
Split Singly Linked List Alternatingly
Easy

https://practice.geeksforgeeks.org/problems/split-singly-linked-list-alternatingly/1?page=3&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a singly linked list of size N. Your task is to complete the function alternatingSplitList() that splits the given linked list into two smaller list. The sublists should be made from alternating elements from the original list.
Note: the sublist should in the order with respect to original list.

Input Format:
First line of input contains number of testcaes T. First line of each input contains length of the linked list and next line contains the elements of the linked list.

Output Format:
For each test case, in new lines, print the two sublists formed after the split.

User Task:
The task is to complete the function alternatingSplitList() which takes the head as parameter and splits the lists into two. The head of the first list should be stored in the provided variable a, and the head of the second should be stored in the provided variable b. The printing is done by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
6
0 1 0 1 0 1
5
2 5 8 9 6

Output:
0 0 0
1 1 1
2 8 6
5 9

Explanation:
Testcase 1: After forming two sublists of the given list as required, we have two lists as: 0->0->0 and 1->1->1.

*/

/*
Algorithm

1. Use tema and temb - temporary pointers for a and b to traverse the list/ otherwise we lose the head of the pointer
2. Take each node, store that node's next pointer in a temp pointer and set the next pointer to NULL 
for a list to avoid any error/ basically keep on changing the head pointer of the main linked list and 
keep adding the alternate nodes into one and then another and shift the temporary pointers to that node
and make head pointer point to temp pointer.
3. Use a variable k to keep track of alternating through the list such that k%2==0 when node in list b has to inserted
and 1 when node in list a has to be inserted
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

// These are global variables to store heads of split lists
struct Node* a; //store head of first list
struct Node* b; //store head of second list


void alternatingSplitList(struct Node* head) 
{
    if (head==NULL){
        return;
    }
    a= head;
    Node* temp = head->next;
    head->next = NULL;
    head= temp;
    b=NULL;
    int k=0;
    Node *temb=b;
    Node *tema=a;
    while(head!=NULL){
        temp = head->next;
        if (k%2==0){
            if(temb==NULL){
                b=head;
                temb=b;
                head->next = NULL;
            }
            else{
                temb->next = head;
                temb= temb->next;
                temb->next = NULL;
            }
        }
        else{
            tema->next = head;
            tema=tema->next;
            tema->next = NULL;
        }
        head= temp;
        k++;
    }
}
