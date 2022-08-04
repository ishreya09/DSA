/*
561. Array Partition
Easy

https://leetcode.com/problems/array-partition/

Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) 
such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

 

Example 1:

Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.
Example 2:

Input: nums = [6,2,6,5,1,2]
Output: 9
Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.
 

Constraints:

1 <= n <= 104
nums.length == 2 * n
-104 <= nums[i] <= 104
*/

/*
        Algorithm
        
        1. Sort the array in accending order. Length of array is always even 
        so think of making pairs now.
        2. Start taking 2 elements at a time and take the minimum of those 2. 
        This should give us the minimum sum. 
        3. The above step now basically means to add alternate elements of the array.
        
*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort (nums.begin(),nums.end());
        int sum=0;
        for (int i=0; i<nums.size(); i+=2){
            sum += nums[i]; 
        }
        
        
        return sum;
    }
};