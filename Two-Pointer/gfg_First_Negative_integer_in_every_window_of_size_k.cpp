/*
First negative integer in every window of size k
Easy

https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1?page=1&difficulty[]=0&category[]=two-pointer-algorithm&sortBy=submissions


Given an array A[] of size N and a positive integer K, find the first negative integer for each and 
every window(contiguous subarray) of size K.

 

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 
Example 2:
Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function printFirstNegativeInteger() 
which takes the array A[], its size N and an integer K as inputs and returns the first negative number in every 
window of size K starting from the first till the end. If a window does not contain a negative integer , 
then return 0 for that window.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(K)

Constraints:
1 <= N <= 105
-105 <= A[i] <= 105
1 <= K <= N
*/

/*
Algorithm

https://www.geeksforgeeks.org/deque-cpp-stl/

1. We create a Dequeue, Di of capacity k, that stores only useful elements of the current window of k elements.
An element is useful if it is in the current window and it is a negative integer. 
2. We process all array elements one by one and maintain Di to contain useful elements of current window 
and these useful elements are all negative integers. 
3. For a particular window, if Di is not empty then the element at front of the Di is the first negative integer 
for that window, else that window does not contain a negative integer.

*/

#include<bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    long long i=0;
    long long int j= K-1;                                           
    vector<long long> ans;
    deque<long long> q;
    for (long long int k=0;k<=min<long long int>(N-1,j);k++){
        if(A[k]<0)
        q.push_back(A[k]);
    }
    
    while(i<N && j<N ){
        if (!q.empty()){
            ans.push_back(q.front());
        }
        else{
            // q is empty and no negative num present
            ans.push_back(0);
        }
        if(!q.empty() && q.front()==A[i]){
            q.pop_front();
        }
        if (++j<N && A[j]<0){
            q.push_back(A[j]);
        }
        i++;
    }
    return ans;
 }