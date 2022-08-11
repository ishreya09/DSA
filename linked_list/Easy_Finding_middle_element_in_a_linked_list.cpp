/*
Finding middle element in a linked list
Easy

https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1?page=1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a singly linked list of N nodes.
The task is to find the middle of the linked list. For example, if the linked list is
1-> 2->3->4->5, then the middle node of the list is 3.
If there are two middle nodes(in case, when N is even), print the second middle element.
For example, if the linked list given is 1->2->3->4->5->6, then the middle node of the list is 4.

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 3 
Explanation: 
Middle of linked list is 3.
Example 2: 

Input:
LinkedList: 2->4->6->7->5->1
Output: 7 
Explanation: 
Middle of linked list is 7.
Your Task:
The task is to complete the function getMiddle() which takes a head reference as the only argument
and should return the data at the middle node of the linked list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 5000

*/

/*
Algorithm 

1. Check if head is null or not - checking if the linked list is empty and if its true then return -1.
2. Check if head->next is null or not- if that is the case - we can surely say that we only have one element in
the linked list and we can return node->data directly
3. If its not the above two cases, instead of finding the length and traversing through the linked list again and again - 
its better to define a fast pointer(Pointing to head initially) which moves 2 indexes at a time and a 
slow pointer (Pointing to head initially) and traverse the list element by element.
4. When the fast->next pointer becomes Null, the slow pointer remains exactly in the middle of the list.

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

void printList(Node* node){
    while (node!=NULL){
        cout<< node->data<< " ";
        node= node->next;
    }
    cout<<endl;
}

class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getMiddle(Node *head)
    {
        // Your code here
        if(head == NULL){
            return -1;
        }
        else if (head->next==NULL){
            return head->data; // linked list has only one element 
        }
        Node *slow = head;
        Node *fast = head;
        
        while (fast !=NULL && fast->next !=NULL){
            fast = fast ->next->next;
            slow = slow->next;
        }
        return slow->data;
    }
};

int main (){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;

        for(int i=0; i<N-1; i++){
            cin>> data;
            tail->next= new Node(data);
            tail = tail->next;
        }
        Solution ob;
        cout<< ob.getMiddle(head) << endl;
    }
    return 0;
}