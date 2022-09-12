#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

// This function prints contents of linked list
// starting from the given node
void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

int main(int argc, char const *argv[])
{
    Node* head = new Node();
    head->data= 2;
    head->next= new Node();
    head->next->data = 5;
    head->next->next= NULL;

    // code to traverse through the linked list 
    printList(head);


    /*
    
    Time Complexity	    Worst Case	    Average Case
    Search	            O(n)	        O(n)
    Insert	            O(1)	        O(1)
    Deletion	        O(1)	        O(1)

    Auxiliary Space:  O(n)
    
    */

    return 0;
}

