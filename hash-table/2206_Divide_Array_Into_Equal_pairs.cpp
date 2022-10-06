/*
2206. Divide Array Into Equal Pairs
Easy

https://leetcode.com/problems/divide-array-into-equal-pairs/

You are given an integer array nums consisting of 2 * n integers.

You need to divide nums into n pairs such that:

Each element belongs to exactly one pair.
The elements present in a pair are equal.
Return true if nums can be divided into n pairs, otherwise return false.

 

Example 1:

Input: nums = [3,2,3,2,2,2]
Output: true
Explanation: 
There are 6 elements in nums, so they should be divided into 6 / 2 = 3 pairs.
If nums is divided into the pairs (2, 2), (3, 3), and (2, 2), it will satisfy all the conditions.
Example 2:

Input: nums = [1,2,3,4]
Output: false
Explanation: 
There is no way to divide nums into 4 / 2 = 2 pairs such that the pairs satisfy every condition.
 

Constraints:

nums.length == 2 * n
1 <= n <= 500
1 <= nums[i] <= 500

*/

/*
Algorithm

1. Find the freq of each element
2. If freq is even - then only pairs could be made - for each number


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int> f;
        for(int i=0;i<nums.size();i++){
            f[nums[i]]++;
        }
        for(auto i=f.begin();i!=f.end();i++){
            if(i->second % 2 !=0){
                return false;
            }
        }
        return true;
    }
};