/*
2442. Count Number of Distinct Integers After Reverse Operations
Medium

https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/description/

You are given an array nums consisting of positive integers.

You have to take each integer in the array, reverse its digits, and add it to the end of the array. 
You should apply this operation to the original integers in nums.

Return the number of distinct integers in the final array.

 

Example 1:

Input: nums = [1,13,10,12,31]
Output: 6
Explanation: After including the reverse of each number, the resulting array is [1,13,10,12,31,1,31,1,21,13].
The reversed integers that were added to the end of the array are underlined. Note that for the integer 10, 
after reversing it, it becomes 01 which is just 1.
The number of distinct integers in this array is 6 (The numbers 1, 10, 12, 13, 21, and 31).
Example 2:

Input: nums = [2,2,2]
Output: 1
Explanation: After including the reverse of each number, the resulting array is [2,2,2,2,2,2].
The number of distinct integers in this array is 1 (The number 2).
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
*/

/*
Algorithm

1. write a func to reverse the num 
2. iterate through the nums and store the freq of nums[i] and reverse of it in a map
3. The map's size is the number of distinct elements in the final array

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseNum(int n){
        int r=0;
        while(n!=0){
            int d=n%10;
            r=r*10+d;
            n=n/10;
        }
        return r;
    }
    int countDistinctIntegers(vector<int>& nums) {
        map<int,int> f;
        for(auto i:nums){
            f[i]++;
            f[reverseNum(i)]++;
        }
        return f.size();
    }
};