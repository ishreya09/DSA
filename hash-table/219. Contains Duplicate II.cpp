/*
219. Contains Duplicate II
Easy

https://leetcode.com/problems/contains-duplicate-ii/description/

Given an integer array nums and an integer k, return true if there are two distinct indices i and j 
in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
*/

/*
Algorithm

1. Store index in a map
2. Check if the key is already present in map, if yes - then substract i-f[nums[i]] and check if its less than k
3. If true, return true- else iterate through whole array to find such pair
4. If after traversal no pair could be found - return false.

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> f;
        for(int i=0; i<nums.size();i++){
            if(f.count(nums[i])!=0){
                cout<<i-f[nums[i]]<<" "<<k<<endl;
                if(i-f[nums[i]]<=k)
                    return true;
            }
            f[nums[i]]=i;
            cout<<nums[i]<<" "<<f[nums[i]]<<endl;
        }
        // after the complete traversal, if we don't find a pair to satisfy the condition, return false
        return false;
    }
};