/*
2344. Minimum Deletions to Make Array Divisible
Hard

https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/

You are given two positive integer arrays nums and numsDivide. 
You can delete any number of elements from nums.

Return the minimum number of deletions such that the smallest element in nums 
divides all the elements of numsDivide. 
If this is not possible, return -1.

Note that an integer x divides y if y % x == 0.

 

Example 1:

Input: nums = [2,3,2,4,3], numsDivide = [9,6,9,3,15]
Output: 2
Explanation: 
The smallest element in [2,3,2,4,3] is 2, which does not divide all the elements of numsDivide.
We use 2 deletions to delete the elements in nums that are equal to 2 which makes nums = [3,4,3].
The smallest element in [3,4,3] is 3, which divides all the elements of numsDivide.
It can be shown that 2 is the minimum number of deletions needed.
Example 2:

Input: nums = [4,3,6], numsDivide = [8,2,6,10]
Output: -1
Explanation: 
We want the smallest element in nums to divide all the elements of numsDivide.
There is no way to delete elements from nums to allow this.
 

Constraints:

1 <= nums.length, numsDivide.length <= 105
1 <= nums[i], numsDivide[i] <= 109
*/

/*
Algorithm 

1. Make a priority queue containing all the values of nums (min heap)
2. Get the top element and check if its divisible by the top element- if any element
of the array is not divisible at any point, pop all the occurences of that element
3. if we traversed the array successfully once of numsDivide - then return the number of 
deletions we did till now
4. If the priority queue becomes empty- then we return -1.

*/

#include<bits/stdc++.h>
using namespace std;    

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        priority_queue<int,vector<int>, greater<int> > p(begin(nums),end(nums));
        int del=0;
        while (!p.empty()){
            int k= p.top();
            int flag=0;
            for(int i=0; i<numsDivide.size();i++){
                if (numsDivide[i]%k != 0){
                    // delete k 
                    while (!p.empty() && p.top()==k){
                        p.pop();
                        del++;
                    }
                    flag=1;
                    break;
                }
            }
            if (flag ==0){
                return del;
            }
        }
        return -1;
        
    }
};