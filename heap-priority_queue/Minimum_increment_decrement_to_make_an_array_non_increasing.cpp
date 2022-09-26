/*
Minimum increment/decrement to make array non-Increasing
Medium

https://practice.geeksforgeeks.org/problems/bf249fb32af71fc4e294b123d99e668a91652be4/1?page=1&category[]=priority-queue&sortBy=submissions

Given an array a of length n, find the minimum number of operations required to make it non-increasing. 
You can select any one of the following operations and preform it any number of times on an array element.

increment the array element by 1.
decrement the array element by 1. 
Example 1:

Input:
N = 4 
array = {3, 1, 2, 1}
Output: 1
Explanation: 
Decrement array[2] by 1. 
New array becomes {3,1,1,1} which is non-increasing. 
Therefore, only 1 step is required. 

Example 2:

Input:
N = 4 
array = {3, 1, 5, 1}
Output: 4

Your Task:
You don't need to read input or print anything. Complete the function minOperations() 
that takes n and array a as input parameters and returns the minimum number of operations required. 

Expected time complexity: O(nlogn)
Expected space complexity: O(n)


Constraints:
1 <= n <= 10^4
1 <= a[i] <= 10^4
*/

/*
Algorithm 

1. traverse the array till we find the min element.
2. Calculate the sum of absolute differences between the min array element and the current array element.
3. To do the above, we maintain a priority queue and we decrement or increment the value when pq.top()<a[i]
and pop the top element and push the current element, otherwise we simply push the element to the pq directly.
4. return the total count (gives min no of increment/decrement operation required to perform )

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minOperations(int *a,int n)
    { 
        int sum = 0, dif = 0; 
      
        priority_queue<int, vector<int>, greater<int> > pq; 
      
        for (int i = 0; i < n; i++) { 
            if (!pq.empty() && pq.top() < a[i]) { 
                dif = a[i] - pq.top(); 
                sum += dif; 
                pq.pop(); 
                pq.push(a[i]); 
            } 
            pq.push(a[i]); 
        } 
      
        return sum; 
    } 
};