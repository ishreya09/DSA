/*
594. Longest Harmonious Subsequence
Easy

https://leetcode.com/problems/longest-harmonious-subsequence/

We define a harmonious array as an array where the difference between 
its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious 
subsequence among all its possible subsequences.

A subsequence of array is a sequence that can be derived from the array 
by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Example 2:

Input: nums = [1,2,3,4]
Output: 2
Example 3:

Input: nums = [1,1,1,1]
Output: 0
 

Constraints:

1 <= nums.length <= 2 * 10^4
-10^9 <= nums[i] <= 10^9


*/

/*
Algorithm

1. Sort the array and get the frequency of each character and 
check simentaneously if the current number
and one less than current number's freq is greater than the max freq till now
2. Step one results in max freq which gives the length of longest Harmonious subsequence

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int findLHS(vector<int>& nums) {
            int a=0,b=0,f=0;
            map<int,int>freq;
            sort(nums.begin(),nums.end());
            for(int i=0;i<nums.size();i++){
                freq[nums[i]]++;
                if (freq[nums[i]]>0 && freq[nums[i]-1]>0  && freq[nums[i]]+freq[nums[i]-1]>f){
                    a= nums[i];
                    b=nums[i]-1;
                    f= freq[nums[i]]+ freq[nums[i]-1];
                }
            }
            return freq[a]+freq[b];
        }
};
