/*
Segregate even and odd nodes in a Link List
Easy

https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1?page=2&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a link list of size N, modify the list such that all the even numbers appear before all the
odd numbers in the modified list. The order of appearance of numbers within each segregation should
be same as that in the original list.

NOTE: Don't create a new linked list, instead rearrange the provided one.


Example 1:

Input:
N = 7
Link List:
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

Output: 8 2 4 6 17 15 9

Explaination: 8,2,4,6 are the even numbers
so they appear first and 17,15,9 are odd
numbers that appear later.

Example 2:

Input:
N = 4
Link List:
1 -> 3 -> 5 -> 7

Output: 1 3 5 7

Explaination: There is no even number.
So ne need for modification.

Your Task:
You do not need to read input or print anything. Your task is to complete the function divide()
which takes N and head of Link List as input parameters and returns the head of modified link list.
Don't create a new linked list, instead rearrange the provided one.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 105
1 ≤ Each element of the list ≤ 105

*/

/*
Algorithm

1. Keep a even pointer initialized to null. If the head data is equal a even number, then initialize the 
even pointer to head pointer
2. Keep track of prev and next(temp) pointers and go on checking if  there is a even number present, if we find
the even number, push it to head if even number is null or else make the next pointer of even number point to this node
and change the node's pointer to even->next
3. Also change the prev's next pointer to temp's next pointer and shift the even pointer to the present node - 
keep a track of temp->next pointer and if prev->next != temp->next - then change previous and temp pointers accodingly 
as well as they start looping at the same place
4. Traverse through the linked list in this way and return the head pointer again in the end
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *divide(int N, Node *head)
    {
        // code here
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *even = NULL;
        Node *temp = head->next;
        Node *prev = head;
        Node *c;
        if (head->data % 2 == 0)
        {
            even = head;
        }
        while (temp != NULL)
        {
            if (temp->data % 2 == 0)
            {
                if (even == NULL)
                {
                    // insertion at head
                    prev->next = temp->next;
                    even = temp;
                    temp->next = head;
                    head = temp;
                    temp = prev->next;
                    continue;
                }
                else
                {
                    // insertion after even pointer and deletion after prev pointer
                    
                    prev->next = temp->next; // define prev->next to temp->next
                    c = temp->next; // this is to check later on

                    temp->next = even->next; // even pointer's next will become temp's next
                    even->next = temp; 
                    even = even->next;

                    if (prev->next != c) // this is to check if temp->next pointer is same or not 
                    // this could happen if prev and even pointer are at the same place at the same time and thus causing 
                    // a loop (the number is also even)
                    {
                        prev = prev->next; // changing the prev pointer 
                        temp = c; // and setting pointer to original temp's next value in start
                    }
                    else
                    {
                        temp = prev->next; // if we are not looping then temp can directly be changed with prev->next
                    }

                    continue;
                }
            }
            prev = prev->next;
            temp = temp->next;
        }
        return head;
    }
};