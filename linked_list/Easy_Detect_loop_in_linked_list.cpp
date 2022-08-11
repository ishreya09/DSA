/*
Detect Loop in linked list
Easy

https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1?page=1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.

Example 1:

Input:
N = 3
value[] = {1,3,4}
x(position at which tail is connected) = 2
Output: True
Explanation: In above test case N = 3.
The linked list with nodes N = 3 is
given. Then value of x=2 is given which
means last node is connected with xth
node of linked list. Therefore, there
exists a loop.
Example 2:

Input:
N = 4
value[] = {1,8,3,4}
x = 0
Output: False
Explanation: For N = 4 ,x = 0 means
then lastNode->next = NULL, then
the Linked list does not contains
any loop.
Your Task:
The task is to complete the function detectloop() which contains reference to the head as only argument. 
This function should return true if linked list contains loop, else return false.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 104
1 ≤ Data on Node ≤ 103
*/

/*
Algorithm

Implementation of Floyd’s Cycle-Finding Algorithm: 

1. Traverse linked list using two pointers.
2. Move one pointer(slow_p) by one and another pointer(fast_p) by two.
3. If these pointers meet at the same node then there is a loop. If pointers do 
not meet then linked list doesn’t have a loop.

*/


#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        Node *fast = head;
        Node *slow= head;
        
        while(fast!= NULL && slow !=NULL && fast->next != NULL){
            fast = fast->next->next;
            slow=slow->next;
            if (fast==slow){
                return true;
            }
        }
        return false;
        
    }
};