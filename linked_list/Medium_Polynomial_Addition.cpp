/*
Polynomial Addition
Medium

https://practice.geeksforgeeks.org/problems/polynomial-addition/1?page=1&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given two polynomial numbers represented by a linked list. The task is to complete the function 
addPolynomial() that adds these lists meaning adds the coefficients who have the same variable powers.
Note:  Given polynomials are sorted in decreasing order of power.

Example 1:

Input:
LinkedList1:  (1,x2) 
LinkedList2:  (1,x3)
Output:
1x^3 + 1x^2
Explanation: Since, x2 and x3 both have
different powers as 2 and 3. So, their
coefficient can't be added up.
Example 2:

Input:
LinkedList1:  (1,x3) -> (2,x2)
LinkedList2:  (3,x3) -> (4,x2)
Output:
4x^3 + 6x^2
Explanation: Since, x3 has two different
coefficients as 3 and 1. Adding them up
will lead to 4x3. Also, x2 has two
coefficients as 4 and 2. So, adding them
up will give 6x2.
Your Task:
The task is to complete the function addPolynomial() which should add the polynomial with same powers 
return the required polynomial in decreasing order of the power in the form of a linked list.
Note: Try to solve the question without using any extra space.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N, M <= 105
1 <= x, y <= 106
*/

/*
Algorithm

1. if any one of the polynomial is null, return the other polynomial directly
2. If both are not empty - then add all results to p1 and return p1.
3. For doing so - take a t1, t2 and prev pointer initialized to p1, p2 and NULL respectively where
prev is the previous pointer of t1.
4. Traverse both the lists. 
a) If powers are equal - add the coef and update in p1 and move t1 and t2 to next ptr and store prev as well
b) If t1->pow > t2->pow - then traverse t1 to next ptr and store the prev as well
c) If t2->pow > t1->pow - We need to check prev
    if prev==NULL denotes that head nodes needs to be changed - 
    so we add a node from t2 to t1 and change head of p1 to t2. 
    We don't traverse further in list to further compare in t1 list. t2 is moved on with its next node. 
    We also let the prev stay as NULL

    if prev!=NULL denotes we need to add after null
    so we store t2->next in tmp
    and then t2->next=prev->next and prev->next = t2 and make prev as t2 
    and reinitialize t2 to tmp ptr for the next node in p2 list. 

5. At last we check if t2==NULL - if not - we make prev->next point to t2 list
and return p1 as answer.

*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};

class Solution{
  public:
    /* The below method print the required sum of polynomial
    p1 and p2 as specified in output  */
    Node* addPolynomial(Node *p1, Node *p2)
    {
        //Your code here
        if(p1==NULL){
            return p2;
        }
        if(p2==NULL){
            return p1;
        }
        // now add everything to p1 list
        Node *t1=p1,*t2=p2;
        Node *prev=NULL; // previous node of t1 
        
        while(t1!=NULL && t2!=NULL){
            if (t1->pow == t2->pow){
                t1->coeff= t1->coeff+t2->coeff;
                prev=t1;
                t1=t1->next;
                t2=t2->next;
            }
            else if(t2->pow< t1->pow)
            {
                prev=t1;
                t1=t1->next;
            }
            else if(t2->pow > t1->pow )
            {
                if(prev!=NULL){
                    Node *t=t2->next;
                    t2->next=prev->next;
                    prev->next= t2;
                    prev=t2;
                    t2=t;
                }
                else{ // insert at head
                    Node *t=t2->next;
                    t2->next=t1;
                    p1=t2;
                    t1=p1;
                    p2=t;
                    t2=p2;
                }
                
                
            }
        }
        
        if(t2!=NULL){
            prev->next=t2;
        }
        
        return p1;
    }
};
