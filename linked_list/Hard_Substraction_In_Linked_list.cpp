/*
Subtraction in Linked List
Hard

https://practice.geeksforgeeks.org/problems/subtraction-in-linked-list/1?page=1&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given two linked lists that represent two large positive numbers. The task is to subtract the given two numbers 
represented by the linked list. Subtract the smaller from the larger one.

Example 1:

Input:
L1 = 1->0->0
L2 = 1->2
Output: 8 8
Explanation:  12 subtracted from 100
gives us 88 as result.

Your Task:
The task is to complete the function subLinkedList() which should subtract the numbers represented by the 
linked list and return the head of the linked list representing the result.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Length of the Linked List <= 10000
*/

/*
Algorithm

To find the greater no and store in l1 list and smaller in l2 list. This is done by NodeGreater function
1. Remove the starting zeros and then calculate the length of the linked list
2. If length is not equal - then check if l2's len is greater than l1's len - if true - then swap them and pad l2 with
zeros in front to avoid segmentation fault during substraction
3. If they are equal - traverse and whichever number turns out to be larger at first will by default will be larger

then we reverse the linked list for easy substraction from right to left(without reversing - it could be difficult and 
increase time complexity)

For subLinkedList function- check which is greater and set l1 to greater
reverse both linked list and traverse together

a) If l1->data>= l2->data - apply direct substraction
b) Otherwise we have to borrow until l1->data-l2->data >0 is greater than zero.
and then perform normal substraction. We add 10 for the one which borrows and substract 1 from the next node's data.

lastly we reverse the l1 linked list and then remove the zeros in front and return the output list as ans
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
    
int length(Node *head){
    int c=1;
    while (head!=NULL){
        head=head->next;
        c++;
    }
    return c;
}

// this function makes sure that l1 has the larger number
void NodeGreater(Node* &l1,Node* &l2){
    while (l1->next!=NULL && l1->data==0){
        l1=l1->next;
    }
    while (l2->next!=NULL && l2->data==0){
        l2=l2->next;
    }
    int a= length(l1);
    int b= length(l2);
    if(a!=b){
        if(b>a){
            Node *tmp=l1;
            l1=l2;
            l2=tmp;
            // add padding to a
            int i=b-a;
            while(i--){
                Node *tmp = new Node(0);
                tmp->next=l2;
                l2=tmp;
            }
            // return;
        }
        if (a>b){
            int i=a-b;
            while(i--){
                Node *tmp = new Node(0);
                tmp->next=l2;
                l2=tmp;
            }
        }
    }
    else{
        Node *k1=l1,*k2=l2;
        while(k1!=NULL && k2!=NULL){
            if(k2->data>k1->data){
                Node *tmp=l1;
                l1=l2;
                l2=tmp;
                return;
            }
            if (k1->data>k2->data)
                return;
            k1=k1->next;
            k2=k2->next;
        }
    }
}

Node* reverse(Node *head){
    if (head==NULL || head->next==NULL){
        return head;
    }
    Node *rest = reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return rest;
}


//You are required to complete this method

Node* subLinkedList(Node* l1, Node* l2)
{
    //Your code here
    NodeGreater(l1,l2);
    // printList(l1);
    // printList(l2);
    l1= reverse(l1);
    l2= reverse(l2);
    
    Node* a=l1,*b=l2;
    
    while (a!=NULL && b!=NULL){
        
        if(a->data >= b->data){
            // cout<< a->data <<"- "<< b->data<<endl;
            a->data= a->data-b->data;
            a= a->next;
            b=b->next;
        }
        else{
            // a->data < b->data
            // cout<< a->data <<"- "<< b->data<<endl;
            Node *t1=a;
            Node *t2=b;
            while(t1!=NULL && t2!=NULL && t1->next!=NULL && ((t1->data -t2->data<0 )) ){
                t1->data=t1->data+10;
                // cout<<t1->data<<"-"<<t2->data<<endl;
                t1->next->data--;
                t1=t1->next;
                t2=t2->next;
            }
            // cout<<t1->data<<"-"<<t2->data<<endl;
            a->data= a->data-b->data;
            a=a->next;
            b=b->next;
        }
    }
    l1= reverse(l1);
    while (l1->next!=NULL && l1->data==0){
        l1=l1->next;
    }
    
    return l1;
}