/*
1. Two Sum
Easy

https://leetcode.com/problems/two-sum/

Given an array of integers nums and an integer target, return indices of the two numbers 
such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the 
same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

*/

/*
Algorithm

1. 
2. 
3.

*/

#include<bits/stdc++.h>
using namespace std;


// TC : O(n2)
class Solution {

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int i, j;
        for (i = 0; i < nums.size(); i++) {
            for (j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};

// Better Solution using map
// make a custom map where we store a vector of index and present index
// check if nums[i] and target-nums[i] is present in the list or not- 
// if the values are same - then check if vector has that number of index or not

struct Node {
    vector<int> index;
    int p=0;
};

// TC : O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int,Node> f;
        for(int i=0;i< nums.size();i++){
            f[nums[i]].index.push_back(i);
        }
        for (int i=0; i<nums.size();i++){
            int k=target-nums[i];
            cout<<k<<endl;
            if (f.find(k) != f.end() && f[k].p < f[k].index.size()) {
                if(nums[i]!=k){
                    result.push_back(i);
                    result.push_back(f[k].index[f[k].p++]);
                }
                else{
                    int j=f[k].p;
                    if(j+1< f[k].index.size()){
                        result.push_back(f[k].index[j]);
                        result.push_back(f[k].index[++j]);
                    }
                    else
                        continue;


                }
                break;
            }
        }
        return result;
    }
    
};

