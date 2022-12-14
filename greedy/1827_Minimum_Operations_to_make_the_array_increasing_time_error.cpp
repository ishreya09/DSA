/*
// causes Time Limit Exceeded error - not efficient

1827. Minimum Operations to Make the Array Increasing
* # Easy

https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/

You are given an integer array nums (0-indexed). In one operation, you can choose an element of the array and increment it by 1.

For example, if nums = [1,2,3], you can choose to increment nums[1] to make nums = [1,3,3].
Return the minimum number of operations needed to make nums strictly increasing.

An array nums is strictly increasing if nums[i] < nums[i+1] for all 0 <= i < nums.length - 1. An array of length 1 is trivially strictly increasing.

 

Example 1:

Input: nums = [1,1,1]
Output: 3
Explanation: You can do the following operations:
1) Increment nums[2], so nums becomes [1,1,2].
2) Increment nums[1], so nums becomes [1,2,2].
3) Increment nums[2], so nums becomes [1,2,3].
Example 2:

Input: nums = [1,5,2,4,1]
Output: 14
Example 3:

Input: nums = [8]
Output: 0
 

Constraints:

1 <= nums.length <= 5000
1 <= nums[i] <= 104
*/

// Gives Time Exceeded Error 

#include<bits/stdc++.h>
using namespace std;


// Function to check if the vetor is strictly incresing or not
// causes Time Limit Exceeded error - not efficient
int isOrder(vector<int> &nums){ // why are we using & over here?
    // could not imagine the pointer working 
    int r=1; // return value
    
    for (int i=0;i<nums.size();i++){
        if (nums[i]>= nums[i+1])
            r=0;
    }
    return r;
}

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count =0; // counts the minimum number of operations required to make 
        // the array strictly increasing
        
        int i=0;
        
        while(isOrder(nums)==0) //  not efficient
        {
            if(nums[i]>=nums[i+1])
            {
                nums[i]++;
                count++;               
            }
            // if (nums[i]>= nums[i+1])
            //     r=0;
            
            if (i== nums.size()){
                i=0;
            }
            
            i++;
            
        }
        
        return count;
    }
};

int main(){
    Solution s;
    vector<int> v = {1,5,2,4,1};
    int k=s.minOperations(v);
    cout<< k<< endl;

    return 0;
}