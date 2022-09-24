/*
TIME LIMIT EXCEEDED

Cereals Box
Easy

https://practice.geeksforgeeks.org/problems/cereals-box0644/1?page=1&category[]=priority-queue&sortBy=submissions

You are given N numbers you can decrease each number by 10 % or K kg whichever is more. If the number you choose is less than K you can make it zero. Your task is to minimize the sum of the number as small as possible by performing N operations only

Note: Final answer should be typecasted to the nearest integer smaller or equal to the value.
 

Example 1:

Input:
N = 2
k = 10
arr = 100 15
Output:
95
Explanation:
You will remove 10 from 100
then once again remove 10 
90.
Example 2:

Input:
N = 2
K = 10
arr = 90 100
Output
170
Explanation:
remove 10 each time
from either 100 or 90.

Your Task:
You don't need to read input or print anything. Your task is to complete the function minSum() which takes an array of integer, its size N, and an integer K  as input parameters and returns an integer, minimum sum of all the elements after performing N operations.


Expected Time Complexity: O(log N)
Expected Space Complexity: O(1)
 

Constraints:
1<=N,K<=104
1<=A[i]<=106
*/

/*
Algorithm 

1. make a priority queue and push the values into the priority queue of float numbers
2. either remove 10% of the number or K from the number and push back the highest number
3. calculate sum as float nd return back as long long int
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	long long minSum(vector<int> a,int N,int K){
	    // code here
	    priority_queue<float> maxh;
	    for(int i = 0; i < N; i++)
	    {
	        maxh.push(a[i]);
	    }
	    for(int i = 0; i < N; i++)
	    {
	        float t = maxh.top();
	        maxh.pop();
	        if(t < K)
	        {
	            t = 0;
	        }
	        else
	        {
	            float p = 0.1 * t;
	            if(p > K)
	            {
	                t -= p;
	            }
	            else
	            {
	                t -= K;
	            }
	        }
	        maxh.push(t);
	    }
	    float sum = 0;
	    for(int i = 0; i < N; i++)
	    {
	        sum += maxh.top();
	        maxh.pop();
	    }
	    return (long long)sum;
	}
};