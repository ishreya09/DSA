/*
2149. Rearrange Array Elements by Sign
Medium

https://leetcode.com/problems/rearrange-array-elements-by-sign/

You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should rearrange the elements of nums such that the modified array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

 

Example 1:

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they 
do not satisfy one or more conditions.  
Example 2:

Input: nums = [-1,1]
Output: [1,-1]
Explanation:
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].
 

Constraints:

2 <= nums.length <= 2 * 105
nums.length is even
1 <= |nums[i]| <= 105
nums consists of equal number of positive and negative integers.

*/

/*
Algorithm

TC - O(n)
1. Make another array ans and for every odd VALUE - add value to odd index of array and same for even
2. Return the array ans. 

Alternate
1. Take 2 queue and push all the elements into the queue checking if its positive or not
2. Now traverse the nums array and at even index pop the positive element and at odd, the negative element
3. Return the array at last.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int indexpos = 0, indexneg=1;
        for(auto num: nums){
            if(num>0){
                ans[indexpos] = num;
                indexpos+=2;
            }
            if(num<0){
                ans[indexneg] = num;
                indexneg += 2;
            }
        }
        return ans;
    }
};

class Solution1 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> q1;
        queue<int> q2;
        for(auto i:nums){
            if (i>0){
                q1.push(i);
            }
            else{
                q2.push(i);
            }
        }
        
        for (int i=0;i<nums.size();i++){
            if (i%2==0){
                nums[i]=q1.front();
                q1.pop();
            }
            else{
                nums[i]=q2.front();
                q2.pop();
            }
        }        
        return nums;
    }
};