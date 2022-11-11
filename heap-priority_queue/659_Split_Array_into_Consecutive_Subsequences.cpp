/*
659. Split Array into Consecutive Subsequences
Medium

You are given an integer array nums that is sorted in non-decreasing order.

Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:

Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
All subsequences have a length of 3 or more.
Return true if you can split nums according to the above conditions, or false otherwise.

A subsequence of an array is a new array that is formed from the original array by deleting some (can be none) of the elements 
without disturbing the relative positions of the remaining elements. (i.e., [1,3,5] is a subsequence of [1,2,3,4,5] while [1,3,2] is not).

 

Example 1:

Input: nums = [1,2,3,3,4,5]
Output: true
Explanation: nums can be split into the following subsequences:
[1,2,3,3,4,5] --> 1, 2, 3
[1,2,3,3,4,5] --> 3, 4, 5
Example 2:

Input: nums = [1,2,3,3,4,4,5,5]
Output: true
Explanation: nums can be split into the following subsequences:
[1,2,3,3,4,4,5,5] --> 1, 2, 3, 4, 5
[1,2,3,3,4,4,5,5] --> 3, 4, 5
Example 3:

Input: nums = [1,2,3,4,4,5]
Output: false
Explanation: It is impossible to split nums into consecutive increasing subsequences of length 3 or more.
 

Constraints:

1 <= nums.length <= 104
-1000 <= nums[i] <= 1000
nums is sorted in non-decreasing order.

*/

/*
Algorithm 

1. Add elements dynamically in the priority queue (add a pair with first element as current num and other as a subsequence count)
(always put the smallest and shortest sequence on the top of the heap)
2. if pq is not empty, add the num element
3. if num[i]==top[i] - start a new subsequence, otherwise keep adding to the previous one
4. 

*/

#include<bits/stdc++.h>
using namespace std;

struct compare{
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        if(a.first==b.first){
            return a.second > b.second;
        }
        else{
            return a.first> b.first;
        }
    }
};

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        int i=0;
        while(i<nums.size()){
            if(pq.empty()){
                pq.push(make_pair(nums[i],1));
                i++;
            }
            else{
                auto temp= pq.top();
                cout<< temp.first<<" "<<temp.second<<endl;
                if(temp.first==nums[i]){
                    pq.push(make_pair(nums[i],1));
                    i++;
                }
                else if(temp.first+1==nums[i]){
                    pq.pop();
                    temp.second+=1;
                    temp.first= nums[i];
                    i++;
                    pq.push(temp);
                }
                else{
                    if(temp.second<3){
                        return false;      
                    }    
                    pq.pop();          
                }
            }
        }
        while (!pq.empty()){
            if(pq.top().second<3){
                return false;
            }
            pq.pop();
        }
        return true;
    }
};
