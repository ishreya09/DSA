/*
1636. Sort Array by Increasing Frequency
Easy

https://leetcode.com/problems/sort-array-by-increasing-frequency/

Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.

 

Example 1:

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
Example 2:

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
Example 3:

Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
 

Constraints:

1 <= nums.length <= 100
-100 <= nums[i] <= 100

*/

/*
Algorithm

1. Make a priority_queue of a pair (frequency, number) 
2. Use a custom Compare to compare values by their frequency. 
If two values have the same frequency, compare their values.
3. Keep on poping the value from pq and add it back in ans.

*/

#include<bits/stdc++.h>
using namespace std;

struct Compare{
    bool operator()(pair<int,int> a, pair<int,int>b){
        if (a.first == b.first){
            return a.second < b.second;
        }
        else{
            return a.first> b.first;
        }
    }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> f;
        for(int i=0;i<nums.size();i++){
            f[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>> , Compare > pq;
        for (auto i=f.begin();i!=f.end();i++){
            pq.push(make_pair(i->second,i->first));
        }
        vector<int> ans;
        while(!pq.empty()){
            int k=pq.top().first;
            while(k--)
                ans.push_back(pq.top().second);
            pq.pop();
            
        }
        return ans;
    }
};