/*
1331. Rank Transform of an Array
Easy

https://leetcode.com/problems/rank-transform-of-an-array/description/

Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.
 

Example 1:

Input: arr = [40,10,20,30]
Output: [4,1,2,3]
Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
Example 2:

Input: arr = [100,100,100]
Output: [1,1,1]
Explanation: Same elements share the same rank.
Example 3:

Input: arr = [37,12,28,9,100,56,80,5,12]
Output: [5,3,4,2,8,6,7,1,3]
 

Constraints:

0 <= arr.length <= 105
-109 <= arr[i] <= 109

*/

/*
Algorithm

1. Store all values in min heap priority queue- and then assign a rank in map
2. Map those rank in arr.
3.

*/

#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==1){
            return {1};
        }
        if(arr.size()==0){
            return arr;
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto i:arr){
            pq.push(i);
        }
        map<int,int> rank;
        int k=pq.top();
        int r=1;
        while(!pq.empty()){
            rank[k]=r;
            pq.pop();
            if (pq.top()!=k){
                r++;
                k=pq.top();
            }
        }
        for (int i=0; i<arr.size();i++){
            arr[i]= rank[arr[i]];
        }
        return arr;
    }
};