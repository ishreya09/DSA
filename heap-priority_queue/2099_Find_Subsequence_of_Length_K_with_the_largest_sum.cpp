/*
2099. Find Subsequence of Length K With the Largest Sum
Easy

https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

You are given an integer array nums and an integer k. You want to find a subsequence of nums of 
length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements 
without changing the order of the remaining elements.

 

Example 1:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.
Example 2:

Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation: 
The subsequence has the largest sum of -1 + 3 + 4 = 6.
Example 3:

Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7. 
Another possible subsequence is [4, 3].
 

Constraints:

1 <= nums.length <= 1000
-105 <= nums[i] <= 105
1 <= k <= nums.length
*/

/*
Algorithm 
1. make a pq using pairs containing number and their index. 
2. store the first k pairs in a vector storing index as first element
3. sort the index now and store it in a vector of integers and return this vector

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> p;
        
        for (int i=0;i<nums.size();i++){
            p.push(make_pair(nums[i],i));
        }
        vector<pair<int,int>> t;
        while(k--){
            auto i=p.top();
            t.push_back(make_pair(i.second,i.first));
            p.pop();
        }
        sort(t.begin(),t.end());
        
        for (int i=0;i<t.size();i++){
            ans.push_back(t[i].second);
        }
        
        return ans;
    }
};
