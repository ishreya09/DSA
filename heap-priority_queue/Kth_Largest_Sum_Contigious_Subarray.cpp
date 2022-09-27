/*
K-th Largest Sum Contiguous Subarray
Medium

https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1?page=1&category[]=priority-queue&sortBy=submissions

You are given an array Arr of size N. You have to find the K-th largest sum of contiguous 
subarray within the array elements.

 

Example 1:

Input:
N = 3
K = 2
Arr = {3,2,1}
Output:
5
Explanation:
The different subarray sums we can get from the array
are = {6,5,3,2,1}. Where 5 is the 2nd largest.
 

Example 2:

Input:
N = 4
K = 3
Arr = {2,6,4,1}
Output:
11
Explanation:
The different subarray sums we can get from the array
are = {13,12,11,10,8,6,5,4,2,1}. Where 11 is the 3rd largest.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the 
array Arr[] and its size N as inputs and returns the Kth largest subarray sum.

 

Expected Time Complexity: O(N2 * log K)
Expected Auxiliary Space: O(K)

 

Constraints:
1 <= N <= 100
1 <= K <= (N*(N+1))/2
-105 <= Arr[i] <= 105
Sum of N over all test cases doesn't exceed 1000.
Array may contain duplicate elements
*/

/*
Algorithm 

1. Write a find_sum function which calculates the Sum from the given start value and adds only N elements from there
2. In the kth largest function, take c=1 which is acting as the number of times the inner loop should run and N acts 
as the number of elements to be counted. 
We can also notice that if N= size of array-then sum had only 1 possibility
If N= size-1, then sum has 2 possibility
when N=1; then sum has size of array possibilty.
3. Make a pq nd store the sums in the same.
4. Remove the k-1 nodes and return the top element of the pq. 


*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int find_sum(vector<int>&Arr,int i,int N){
        if (Arr.size()-1<i+N-1){
            return -9999;
        }
        else{
            int sum=0;
            for(int it=i;it<i+N;it++ ){
                sum=sum+Arr[it];
            }
            return sum;
        }
    }
    
    int kthLargest(vector<int> &Arr,int N,int K){
        int sum=0;
        int c=1;
        priority_queue<int> p;
        while(N){
            for (int i=0;i<c;i++){
                sum =find_sum(Arr,i,N);
                if (sum!=-9999){
                    p.push(sum);
                }
            }
            c++;
            N--;
        }
        while(--K){
            p.pop();
        }
        return p.top();
    }
};