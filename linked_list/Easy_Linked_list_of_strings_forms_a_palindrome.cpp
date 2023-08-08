/*
linked list of strings forms a palindrome
Easy

https://practice.geeksforgeeks.org/problems/linked-list-of-strings-forms-a-palindrome/1?page=3&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Given a linked list of strings having n nodes check to see whether the combined string formed is palindrome or not. 

Input:
You have to complete the method which takes one argument: the head of the linked list . You should not read any input from stdin/console.. There are multiple test cases. For each test case, this method will be called individually.

Output:
Your function should return True if the combined string is pallindrome else it should return False.

User Task:
The task is to complete the function compute() which returns true or false.

Constraints:
1 <=T<= 103
1 <=n<= 103

Example:
Input :
2
5
a bc d dcb a
4
a bc d ba

Output :
True
False

Explanation:
case 1 : as String "abcddcba" is palindrome the function should return true
case 2 : as String "abcdba" is not palindrome the function should return false
     
*/

/*
Algorithm

1. find the length of the string and return a s variable with the whole string 
2. Traverse through the string now to check if its palindrome or not

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    struct Node* next;

    Node(string x){
        data =x;
        next = NULL;
    }
};


int length(Node *head, string *s){ // using pass by reference of string s
    Node *temp= head;
    int c=0;
    while(temp != NULL){
        c+= (temp->data).length();
        *s+= temp->data;
        temp= temp->next;
    }
    return c;
}
bool compute(Node* root)
{
   //Your code goes here
   string s;
   int len = length(root,&s); // is string s is treated as a variable instead of an array?
   for (int i=0; i<len/2 + 1; i++ ){
       if (s[i]!= s[len-i-1]){
           return false;
       }
   }
   return true;
   
}

