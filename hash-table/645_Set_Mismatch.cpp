/*
645. Set Mismatch
Easy

https://leetcode.com/problems/set-mismatch/

You have a set of integers s, which originally contains all the numbers from 1 to n. 
Unfortunately, due to some error, one of the numbers in s got duplicated to another 
number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and 
return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
 

Constraints:

2 <= nums.length <= 104
1 <= nums[i] <= 104


*/

/*
Algorithm

1. count the frequency of all the elements and check for the number whose frequency is 2 using map
2. go from 1 to nums.size() and check whose frequency is zero then
3. Return the array.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        map<int,int> f;
        for (int i=0;i<nums.size();i++){
            f[nums[i]]++;
            if (f[nums[i]]==2){
                ans.push_back(nums[i]);
            }
        }
        int k=1;
        while(f[k]>0 && k<=nums.size()){
            k++;
        }
        ans.push_back(k);
        return ans;
    }
};