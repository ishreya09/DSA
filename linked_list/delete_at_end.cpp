/*


*/

/*
Algorithm

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

Node * deleteatend(Node* head){
    if(head==NULL){
        return head;
    }
    if(head->next==NULL){
        delete (head);
        return NULL;
    }
    Node* curr = head;
    while(curr->next->next!=NULL){
        curr=curr->next;
    }
    delete (curr->next);
    curr->next=NULL;
    return head;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<endl;
        head=head->next;
    }
}

int main(){
    Node* head= new Node(5);
    head->next = new Node(7);
    head->next->next= new Node(6);
    print(head);
    head= deleteatend(head);
    print(head);
}