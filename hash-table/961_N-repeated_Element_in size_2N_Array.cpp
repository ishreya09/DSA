/*
961. N-Repeated Element in Size 2N Array
Easy

https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

You are given an integer array nums with the following properties:

nums.length == 2 * n.
nums contains n + 1 unique elements.
Exactly one element of nums is repeated n times.
Return the element that is repeated n times.

 

Example 1:

Input: nums = [1,2,3,3]
Output: 3
Example 2:

Input: nums = [2,1,2,5,3,2]
Output: 2
Example 3:

Input: nums = [5,1,5,2,5,3,5,4]
Output: 5
 

Constraints:

2 <= n <= 5000
nums.length == 2 * n
0 <= nums[i] <= 104
nums contains n + 1 unique elements and one of them is repeated exactly n times.


*/

/*
Algorithm

1. Calculate freq of each element 
2. Traverse through the map and check if it is equals to nums.size()/2 or not
3. Return the num when step 2 is true.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,int> f;
        for(int i=0; i< nums.size();i++){
            f[nums[i]]++;
        }
        int n=nums[0];
        for (auto i = f.begin();i!= f.end();i++){
            if (i->second == nums.size()/2){
                n=i->first;
                break;
            }
        }
        return n;
    }
};