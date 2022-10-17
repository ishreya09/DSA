/*
922. Sort Array By Parity II
Easy

https://leetcode.com/problems/sort-array-by-parity-ii/

Given an array of integers nums, half of the integers in nums are odd, and the other half are even.

Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

Return any answer array that satisfies this condition.

 

Example 1:

Input: nums = [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
Example 2:

Input: nums = [2,3]
Output: [2,3]
 

Constraints:

2 <= nums.length <= 2 * 104
nums.length is even.
Half of the integers in nums are even.
0 <= nums[i] <= 1000
 

Follow Up: Could you solve it in-place?

*/

/*
Algorithm

1. Take i and j pointers which we traverse alternatingly
i points to odd numbers at even index and j points to even number at odd index
2. When we find such pair, we swap both of them
3. Once we reach the end of the array, we return the array.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0; // check for odd num at even index
        int j=i+1; // check for even num at odd index
        while(i<nums.size() && j<nums.size()){
            if(nums[i]%2==0){
                i+=2;
                continue;
            }
            if(nums[j]%2!=0){
                j+=2;
                continue;
            }
            int k=nums[i];
            nums[i]=nums[j];
            nums[j]=k;
            i+=2;
            j+=2;
        }
        return nums;
    }
};