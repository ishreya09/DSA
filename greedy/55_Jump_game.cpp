/*
55. Jump Game
Medium

https://leetcode.com/problems/jump-game/

You are given an integer array nums. You are initially positioned at the array's first index,
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.



Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it
impossible to reach the last index.


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105

*/

/*
Algorithm

1. take a variable reach as a counter, and i to traverse through the array 
2. we would reach the end if reach >=i 
3. if reach >= i we change reach to be either itself or i+nums[i]- whichever is maximum

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int reach = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (reach < i)
            {
                return 0;
            }
            reach = max<int>(reach, i + nums[i]);
        }
        return 1;
    }
};
