/*
Merge two sorted linked lists
Medium

https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1?page=1&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
 

Example 1:

Input:
N = 4, M = 3 
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
Explanation: After merging the two linked
lists, we have merged list as 2, 3, 5,
10, 15, 20, 40.
Example 2:

Input:
N = 2, M = 2
valueN[] = {1,1}
valueM[] = {2,4}
Output:1 1 2 4
Explanation: After merging the given two
linked list , we have 1, 1, 2, 4 as
output.
Your Task:
The task is to complete the function sortedMerge() which takes references to the heads of two linked lists as the arguments and returns the head of merged linked list.


Constraints:
1 <= N, M <= 10^4
0 <= Node's data <= 10^5

*/

/*
Algorithm

Time Complexity : O(n+m)
Auxilliary Space : O(1)

1. Merge list2 to list1.
2. Check if list2 has a smaller node and if true then make it the head of list1
3. Then traverse the l1 such that l1->next->data>l2->data is satisfied and we add that node as next to l1 
4. We repeat the step till l2 == NULL 
5. If l1->next==null and l2!= null - then l1->next=l2 is a necessary step

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


//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    // lets merge to list 1
    
    Node *l1=head1,*l2=head2;
    
    // add to head 
    if (l1!=NULL && l2!=NULL && l1->data>l2->data){
        // add l2 node at l1's head
        Node *tmp= l2->next;
        l2->next=l1;
        l1= l2;
        l2= tmp;
        head1= l1;
        head2=l2;
    }           
    
    while(l1!=NULL && l1->next!=NULL && l2!=NULL){
        if(l1->next->data>l2->data){
            Node *tmp = l2->next;
            l2->next=l1->next;
            l1->next = l2;
            // l1=l2;
            l2= tmp;
        }
        l1=l1->next;
    }
    
    if (l1==NULL){
        head1=l2;
    }
    else if (l1!=NULL && l2!=NULL){
        l1->next= l2;
    }
    
    return head1;
}  