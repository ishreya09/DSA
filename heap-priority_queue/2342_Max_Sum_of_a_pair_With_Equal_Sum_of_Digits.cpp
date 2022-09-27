/*
TIME LIMIT EXCEEDED
2342. Max Sum of a Pair With Equal Sum of Digits
Medium

https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

You are given a 0-indexed array nums consisting of positive integers. You can choose two indices 
i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

 

Example 1:

Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.
Example 2:

Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

/*
Algorithm 

1. Make a pq to store the pairs with same sum of digits
2. To find the digit pairs we add using O(n2) technique
3. 

*/

#include<bits/stdc++.h>
using namespace std;

int sod(int n){
    if(n==0){
        return 0;
    }
    return n%10+sod(n/10);
}

struct Compare {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.first+a.second < b.first+b.second;
    }
};

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, Compare> p;
        for (int i=0; i<nums.size();i++){
            for(int j=i+1; j<nums.size();j++){
                int x= sod(nums[i]);
                int y= sod(nums[j]);
                if(x==y){
                    p.push(make_pair(nums[i],nums[j]));
                }
                
            }
        }
        if (p.empty()){
            return -1;
        }
        return p.top().first+p.top().second;
    }
};