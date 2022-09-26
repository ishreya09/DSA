/*
1424. Diagonal Traverse II
Medium

https://leetcode.com/problems/diagonal-traverse-ii/

Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.

 

Example 1:


Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,4,2,7,5,3,8,6,9]
Example 2:


Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i].length <= 105
1 <= sum(nums[i].length) <= 105
1 <= nums[i][j] <= 105
*/

/*
Algorithm 

1. Notice that numbers with equal sums of row and column indexes belong to the same diagonal.
2. Store them in priority queue of vector (sum, row, val), sort them, and then regroup the answer.
3. store row as negative so that its sorted in default max heap but for negative numbers
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> p;
        // sum,row,val

        for (int i=0;i<nums.size();i++){
            for(int j=0; j<nums[i].size();j++){
                vector<int> k;
                k.push_back(i+j);
                k.push_back(-i);
                k.push_back(nums[i][j]);
                p.push(k);
            }
        }
        vector<int> ans;
        while(!p.empty()){
            ans.push_back(p.top()[2]);
            p.pop();
        }
        return ans;
    }
};