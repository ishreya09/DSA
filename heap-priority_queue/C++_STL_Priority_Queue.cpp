/*
ERROR

C++ STL Priority Queue
Easy

https://practice.geeksforgeeks.org/problems/c-stl-priority-queue/1?page=1&category[]=priority-queue&sortBy=submissions

Implement different operations on Priority Queue .i.e. adding element, removing element, size of priority queue, print the queue and top element of queue. 

Input:
The first line of input contains an integer T denoting the no of test cases. For each test case, the first line of input contains an integer Q denoting the no of queries followed by Q space separated queries. 
A query can be of the following types:
1 x (Adding x to the priority queue and print the queue)
2 (Removing the element from the top of the priority queue and printing that element )
3 (Get the element at the top of the priority queue)
4 (Get the size of the priority queue)
5 (Print the priority queue) 

Note: In each case return or print -1 if priority queue is empty

Output:
For each test case, the output is according to the query Q performed and if the priority queue is empty the output is -1.

Constraints:
1<=T<=100
1<=Q<=100

Example:
Input:
1
8
1 6
1 1
1 7
4
3
2
5
2
Output:
6
6 1
7 6 1
3
7
7 
6 1 
6

Explanation:
1 6 means adding 6 in the queue and printing that, similarly adding 1 and 7 in the queue and printing the queue 
i.e. 7 6 1. By 4 it returns the size of the queue i.e 3. With 3 as input, it returns the element at the top i.e 7. 
With 2 it removes the top element i.e 7 from the queue and prints the element i.e. 7. Having 5 as input, it prints 
the queue i.e. 6 1 and again 2 remove the element and prints that i.e 6.
*/

/*
Algorithm 

*/

#include<bits/stdc++.h>
using namespace std;

//User function Template for C++
/*add the element in the
priority queue*/
void addElement(priority_queue<int> & A, int x)
{
    //your code here
    
    A.push(x);
    // print(A);
}

/* remove top element from 
the priority queue*/
void remove_Element(priority_queue<int> &A)
{
    //your code here
    if(!A.empty()){
        cout<<A.top()<<endl;
        A.pop();
        
    }
    else {
        cout<<-1<<endl;
    }
}

/*  returns the top element 
of the priority queue*/
int getElement_at_top(priority_queue<int> &A)
{
    //your code here
    return A.empty() ? -1 : A.top();
}

/* returns the size of
the priority queue*/
int getSize(priority_queue<int> &A)
{
    //your code here
    return A.empty() ? -1 :A.size();
    
}

/* prints the element in 
the priority queue*/
void print(priority_queue<int> &A)
{
    //your code here
    priority_queue <int> q = A;
    if (q.empty()){
        cout<<-1<<endl;
        return;
    }
    while(!q.empty()){
        cout<< q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}