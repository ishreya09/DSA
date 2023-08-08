/*
Count Pairs whose sum is equal to X
Easy

https://practice.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1?page=1&status[]=unsolved&category[]=Linked%20List&sortBy=submissions

Given two linked list of size N1 and N2 respectively of distinct elements, your task is to complete the function countPairs(),
which returns the count of all pairs from both lists whose sum is equal to the given value X.
Note: The 2 numbers of a pair should be parts of different lists.

Example 1:

Input:
L1 = 1->2->3->4->5->6
L2 = 11->12->13
X = 15
Output: 3
Explanation: There are 3 pairs that
add up to 15 : (4,11) , (3,12) and (2,13)
Example 2:

Input:
L1 = 7->5->1->3
L2 = 3->5->2->8
X = 10
Output: 2
Explanation: There are 2 pairs that add up
to 10 : (7,3) and (5,5)
Your Task:
You only need to implement the given function countPairs() and return the count.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(N+M)

Constraints:
1<=size of linked list<=10000
1<=X<=10000

Note : All elements in a linked list are unique.

*/

/*
Algorithm

1. Take a set and store one linked list data in that set. Since the number of elements in a linked list, we need not worry about duplicates
2. Traverse through the other linked list and find if x-temp->data is present in the set or not.
3. If it is increment the count and then go to the next node until the whole second linked list is traversed

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
    int recCountPairs(struct Node* h1, struct Node* h2,int x, int c){
        set<int> s1;        
        // traverse and add the data into s1 and s2
        while(h1!=NULL){
            s1.insert(h1->data);
            h1=h1->next;
        }
        Node *temp=h2;
        while(temp!=NULL){
            if(s1.find(x-temp->data)!= s1.end()){
                c++;
            }
            temp=temp->next;
        }
        return c;        
    }
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        // think recursively
        int count= recCountPairs(head1,head2,x,0);
        return count;
    }
};