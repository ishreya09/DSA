/*
905. Sort Array By Parity
Easy

https://leetcode.com/problems/sort-array-by-parity/

Given an integer array nums, move all the even integers at the beginning of the 
array followed by all the odd integers.

Return any array that satisfies this condition.

 

Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 5000
0 <= nums[i] <= 5000
*/

/*
Algorithm

1. Use two pointers, one at start and one at end of the array
2. If the start value is even, go on incrementing i - 
and then search even number from the end of the array and swap with i
3. Return the array.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            if (nums[i]%2==0){
                i++;
                continue;
            }
            if (nums[j]%2 == 0){
                int k=nums[j];
                nums[j]=nums[i];
                nums[i]=k;
                i++;
            }
            j--;
            
        }
        return nums;
    }
};