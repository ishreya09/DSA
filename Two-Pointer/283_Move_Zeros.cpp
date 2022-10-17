/*
283. Move Zeroes
Easy

https://leetcode.com/problems/move-zeroes/

Given an integer array nums, move all 0's to the end of it while maintaining 
the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?

*/

/*
Algorithm

1. Take 2 pointers at i =0 and j = i+1 and traverse for first zero for i and the next non zero 
number after index i  and point it using j.
2. Once both are found, swap the elements of i to j and vice versa.


*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int j=i+1;
        while(i<nums.size() && j<nums.size()){
            while (i<nums.size() && nums[i]!=0){
                i++;
            }
            j=i;
            while(j<nums.size() && nums[j]==0){
                j++;
            }
            if(i>=nums.size() && j>=nums.size()){
                break;
            }
            else if(i<nums.size() && j<nums.size()){
                nums[i]=nums[j];
                nums[j]=0;
                cout<<nums[i]<<" "<< nums[j]<<endl;
                i++;
                j++;
            }
        }
        // return nums;
    }
};