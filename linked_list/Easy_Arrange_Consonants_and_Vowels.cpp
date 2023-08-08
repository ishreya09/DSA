/*
Arrange Consonants and Vowels
Easy

https://practice.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1?page=3&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a singly linked list of size N containing only English Alphabets. Your task is to complete the function arrangeC&V(),
that arranges the consonants and vowel nodes of the list it in such a way that all the vowels nodes come before
the consonants while maintaining the order of their arrival.

Input:
The function takes a single argument as input, the reference pointer to the head of the linked list.
There will be T test cases and for each test case the function will be called separately.

Output:
For each test case output a single line containing space separated elements of the list.

User Task:
The task is to complete the function arrange() which should arrange the vowels and consonants as required.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
6
a e g h i m
3
q r t

Output:
a e i g h m
q r t

Explanation:
Testcase 1: Vowels like a, e and i are in the front, and consonants like
g, h and m are at the end of the list.

*/

/*
Algorithm

1. Keep a vowel pointer initialized to null. If the head data is equal a vowel, then initialize the 
vowel pointer to head pointer
2. Keep track of prev and next(temp) pointers and go on checking if  there is a vowel present, if we find
the vowel, push it to head if vowel is null or else make the next pointer of vowel point to this node and change the 
node's pointer to vowel->next
3. Also change the prev's next pointer to temp's next pointer and shift the vowel pointer to the present node - 
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

// task is to complete this function
// function should return head to the list after making
// necessary arrangements
struct Node *arrange(Node *head)
{
    // Code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *vowels = NULL;
    Node *temp = head->next;
    Node *prev = head;
    Node *c;
    if (head->data == 'a' || head->data == 'e' || head->data == 'i' || head->data == 'o' || head->data == 'u')
    {
        vowels = head;
    }
    while (temp != NULL)
    {
        if (temp->data == 'a' || temp->data == 'e' || temp->data == 'i' || temp->data == 'o' || temp->data == 'u')
        {
            if (vowels == NULL)
            {
                // insertion at head
                prev->next = temp->next;
                vowels = temp;
                temp->next = head;
                head = temp;
                temp = prev->next;
                continue;
            }
            else
            {
                prev->next = temp->next;
                c = temp->next;
                temp->next = vowels->next;
                vowels->next = temp;
                vowels = vowels->next;

                if (prev->next != c)
                {
                    prev = prev->next;
                    temp = c;
                }
                else
                {
                    temp = prev->next;
                }

                continue;
            }
        }
        prev = prev->next;
        temp = temp->next;
    }
    return head;
}
