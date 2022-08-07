/*
1855. Maximum Distance Between a Pair of Values
Medium

https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/

You are given two non-increasing 0-indexed integer arrays nums1​​​​​​ and nums2​​​​​​.

A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both i <= j 
and nums1[i] <= nums2[j]. The distance of the pair is j - i​​​​.

Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.

An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length.

 

Example 1:

Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
Output: 2
Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
The maximum distance is 2 with pair (2,4).
Example 2:

Input: nums1 = [2,2,2], nums2 = [10,10,1]
Output: 1
Explanation: The valid pairs are (0,0), (0,1), and (1,1).
The maximum distance is 1 with pair (0,1).
Example 3:

Input: nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
Output: 2
Explanation: The valid pairs are (2,2), (2,3), (2,4), (3,3), and (3,4).
The maximum distance is 2 with pair (2,4).
 

Constraints:

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[j] <= 105
Both nums1 and nums2 are non-increasing.


*/

/*
Algorithm

1. take the first element of both the arrays, if num2[j]>num1[i] - then increase j to see if 
there is any further number which satisfies the condition again
2. If the above condition is false there is no use to check further for j and also there 
is no use in making j as 0 again as the array is strictly decreasing, so increase i by 1.
3. In this process we find the maximum difference using Two pointer method.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        int i=0, j=0;
        while (i<nums1.size() && j<nums2.size()){
            if (nums1[i]<= nums2[j]){
                ans = max(ans,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return ans;  
    }
};

/*
// Brute Force method - gives time limit exceeded error

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        for (int i=0; i<nums1.size();i++){
            for (int j=0; j<nums2.size();j++){
                if(nums1[i]<=nums2[j]){
                    ans= max(ans,j-i);
                }
            }
        }
        return ans;
    }
};

*/
