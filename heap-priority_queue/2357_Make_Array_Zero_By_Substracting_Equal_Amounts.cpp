/*
TIME LIMIT EXCEEDED
2357. Make Array Zero by Subtracting Equal Amounts
Easy

https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/

You are given a non-negative integer array nums. In one operation, you must:

Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
Subtract x from every positive element in nums.
Return the minimum number of operations to make every element in nums equal to 0.

 

Example 1:

Input: nums = [1,5,0,3,5]
Output: 3
Explanation:
In the first operation, choose x = 1. Now, nums = [0,4,0,2,4].
In the second operation, choose x = 2. Now, nums = [0,2,0,0,2].
In the third operation, choose x = 2. Now, nums = [0,0,0,0,0].
Example 2:

Input: nums = [0]
Output: 0
Explanation: Each element in nums is already 0 so no operations are needed.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100

*/

/*
Algorithm 

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> a;
        //Assign nums to pq
        for(int i=0;i<nums.size();i++){
            a.push(nums[i]);
        }
        int c=0;
        while(a.top()==0){
            a.pop();
        }
        while(!a.empty()){
            if (a.top()==0)
                a.pop();
            else{
                c++;
                int x= a.top();
                a.pop();
                int y = a.top();
                a.pop();
                if (y-x!=0){
                    a.push(y-x);
                }
            }
        }
        return c;
    }
};