/*
75. Sort Colors
Medium

https://leetcode.com/problems/sort-colors/

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects 
of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?

*/

/*
Algorithm

1. Use counting sort technique - count red white and blue colors and then sort the array with their count values.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // counting sort
        int r=0,w=0,b=0;
        for (auto i:nums){
            if (i==0)
                r++;
            if (i==1)
                w++;
            if(i==2)
                b++;
        }
        int i=0;
        while (r--){
            nums[i]=0;
            i++;
        }
        while(w--){
            nums[i]=1;
            i++;
        }
        while(b--){
            nums[i]=2;
            i++;
        }
    }
};