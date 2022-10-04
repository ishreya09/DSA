/*
2006. Count Number of Pairs With Absolute Difference K
Easy

https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.

The value of |x| is defined as:

x if x >= 0.
-x if x < 0.
 

Example 1:

Input: nums = [1,2,2,1], k = 1
Output: 4
Explanation: The pairs with an absolute difference of 1 are:
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
Example 2:

Input: nums = [1,3], k = 3
Output: 0
Explanation: There are no pairs with an absolute difference of 3.
Example 3:

Input: nums = [3,2,1,5,4], k = 2
Output: 3
Explanation: The pairs with an absolute difference of 2 are:
- [3,2,1,5,4]
- [3,2,1,5,4]
- [3,2,1,5,4]
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
1 <= k <= 99

*/

/*
Algorithm

1. make a map for keeping track of frequency of numbers and find maximum element as well
2. traverse through the map and  check if frequency is greater than one - if it is - 
then increment count by freq of first * freq of k+ first (mC1 * nC1)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        map<int,int> f;
        // avoids time limit exceeded error as map goes on increasing
        int m=0;
        for(int i=0; i<nums.size();i++){
            m=max<int>(m,nums[i]);
            f[nums[i]]++;
        }
        int count=0;
        for(auto i= f.begin();i->first<=m ;i++ ){
            if (f[i->first + k] >0){
                count+= (i->second * f[i->first+k]);
                cout<< count<<endl;
            }
            else{
                f[i->first + k]=0;
            }
            cout<< "i= "<<i->first<< endl;
            
        }
        return count;
    }
};

