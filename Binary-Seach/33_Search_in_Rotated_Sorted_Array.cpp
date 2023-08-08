/*
33. Search in Rotated Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if 
it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-10^4 <= target <= 10^4

*/

/*
Algorithm

Initialize two pointers i and j to represent the current search interval, where i is the left boundary and j is the right boundary.

Enter a loop that continues as long as i is less than or equal to j.

Calculate the middle index mid as i + (j - i) / 2.

Check if the element at index mid is equal to the target. If it is, return mid as the index where the target is found.

Check if the left part of the interval (from i to mid) is sorted:

a. If nums[mid] >= nums[i], then the left part is sorted.

b. Check if the target is within the range of values in the left sorted part (nums[i] to nums[mid]). If yes, update j = mid - 1 to search in the left part; otherwise, update i = mid + 1 to search in the right part.

Check if the right part of the interval (from mid to j) is sorted:

a. If nums[mid] <= nums[j], then the right part is sorted.

b. Check if the target is within the range of values in the right sorted part (nums[mid] to nums[j]). If yes, update i = mid + 1 to search in the right part; otherwise, update j = mid - 1 to search in the left part.

If none of the conditions above is satisfied, return -1 to indicate that the target element is not found in the array.

After the loop ends (when i > j), return -1 to indicate that the target element is not found in the rotated sorted array.

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int low= 0;
            int high = nums.size()-1;
            int mid;
            while(low <= high){
                mid= low + (high-low)/2;
                if(target==nums[mid]){
                    return mid;
                }
                else if (nums[mid]>= nums[low]){ // left part of the array is sorted
                    if(target<nums[mid] && target>= nums[low]){
                        high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                }
                else if(nums[mid]<=nums[high]){ // right part of the array is sorted
                    if (target>nums[mid] && target<=nums[high]){
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }
                }

            }
            return -1;
        }
            
};
