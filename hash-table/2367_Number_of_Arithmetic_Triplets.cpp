/*
2367. Number of Arithmetic Triplets
Easy

https://leetcode.com/problems/number-of-arithmetic-triplets/

You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. 
A triplet (i, j, k) is an arithmetic triplet if the following conditions are met:

i < j < k,
nums[j] - nums[i] == diff, and
nums[k] - nums[j] == diff.
Return the number of unique arithmetic triplets.

 

Example 1:

Input: nums = [0,1,4,6,7,10], diff = 3
Output: 2
Explanation:
(1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
(2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3. 
Example 2:

Input: nums = [4,5,6,7,8,9], diff = 2
Output: 2
Explanation:
(0, 2, 4) is an arithmetic triplet because both 8 - 6 == 2 and 6 - 4 == 2.
(1, 3, 5) is an arithmetic triplet because both 9 - 7 == 2 and 7 - 5 == 2.
 

Constraints:

3 <= nums.length <= 200
0 <= nums[i] <= 200
1 <= diff <= 50
nums is strictly increasing.

*/

/*
Algorithm

1. We can use three loops, each iterating through the array to go through every possible triplet. 
Be sure to not count duplicates.
2. We use 2 pointer method here and use 3 times and keep a count.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int i=0;
        int count=0;
        while(i<nums.size()){
            int j=nums.size()-1;
            while(j>i){
                if (nums[j]-nums[i]==diff){
                    int k=j;
                    while(k<nums.size()){
                        if(nums[k]-nums[j]==diff){
                            count++;
                        }
                        k++;
                    }
                }
                j--;
            }
            i++;
        }
        return count;
    }
};
