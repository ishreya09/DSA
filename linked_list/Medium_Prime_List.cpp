// WRONG ANSWER
/*
Prime List
Medium

https://practice.geeksforgeeks.org/problems/6cb0782855c0f11445b8d70e220f888e6ea8e22a/1?page=1&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

*/

/*
Algorithm

1. Use sqrt method to check if number is prime or not
2. Simentaneously move back and front and check if number is prime or not
3. Whenever one of the flags become true (Flags initailized as false - one front larger nums - one 
for smaller nums)
4. check if both are true - then return smaller no
else return whichever is true
5. Iterate through the list and change through these func

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    struct Node* next;

    Node(int x){
        val =x;
        next = NULL;
    }
};


class Solution{
public:
    bool isPrime(int n){
        if(n<0) return false;
        if (n==0 || n==1)
            return false;
        if (n==2 || n==3 || n==5)
            return true;
        if(n%2==0 || n%3==0 || n%5==0) 
            return false;
        for (int i=5;i<=sqrt(n); i+=6){
            if(n%i==0 || n%(i+2)==0){
                return false;
            }
        }
        return true;
    }
    int nearestPrime(int n){
        if(n==1 || n==0){
            return 2;
        }
        int rev=n;
        int next=n;
        bool fr=0,fn=0;
        while (!fr && !fn){
            rev--;
            next++;
            fr= isPrime(rev);
            fn= isPrime(next);
        }
        if (fr && fn){
            return rev;
        }
        else if(fn){
            return next;
        }
        else{
            return rev;
        }
        
    }
    Node *primeList(Node *head){
        Node *t =head;
        while(t!=NULL){
            if(!isPrime(t->val)){
                t->val= nearestPrime(t->val);
            }
            t=t->next;
        }
        return head;
    }
};