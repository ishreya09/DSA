/*
Implement Stack using Linked List
Basic

https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1?page=1&difficulty[]=-2&difficulty[]=-1&difficulty[]=0&category[]=Linked%20List&sortBy=submissions

Let's give it a try! You have a linked list and you have to implement the functionalities push and pop of stack using this given linked list. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack. 

Example 1:

Input: 
push(2)
push(3)
pop()
push(4) 
pop()
Output: 3 4
Explanation: 
push(2)    the stack will be {2}
push(3)    the stack will be {2 3}
pop()      poped element will be 3,
           the stack will be {2}
push(4)    the stack will be {2 4}
pop()      poped element will be 4
Example 2:

Input: 
pop()
push(4)
push(5)
pop()
Output: -1 5
Your Task: You are required to complete two methods push() and pop(). 
The push() method takes one argument, an integer 'x' to be pushed into the 
stack and pop() which returns an integer present at the top and popped out from the stack. 
If the stack is empty then return -1 from the pop() method.


Expected Time Complexity: O(1) for both push() and pop().
Expected Auxiliary Space: O(1) for both push() and pop().

Constraints:
1 <= Q <= 100
1 <= x <= 100


*/

/*
Algorithm

1. Stack is adding the element in the end- to implement stack using linked list
We push the elements from the top so that time complexity remains O(1)
and we pop elements from the top as well.

*/

#include<bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;
    StackNode (int a){
        data =a;
        next =NULL;
    }
};

class MyStack{
    private:
        StackNode *top;
    public :
        void push(int);
        int pop();
        MyStack(){
            top=NULL;

        }
};


//Function to push an integer into the stack.
void MyStack ::push(int x) 
{
    // Your Code
    StackNode *temp = new StackNode(x);
    if (top==NULL){
        top = temp;
    }
    else{
        temp->next = top;
        top= temp;
    }
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    // Your Code
    if (top== NULL){
        return -1;
    }
    else{
        StackNode *temp= top;
        top= top->next;
        int data= temp->data;
        delete(temp);
        return data;
        
    }
}
