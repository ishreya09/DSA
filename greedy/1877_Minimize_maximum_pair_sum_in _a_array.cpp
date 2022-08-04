/*
1877. Minimize Maximum Pair Sum in Array
Medium

https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum is the largest pair sum in a list of pairs.

For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:

Each element of nums is in exactly one pair, and
The maximum pair sum is minimized.
Return the minimized maximum pair sum after optimally pairing up the elements.



Example 1:

Input: nums = [3,5,2,3]
Output: 7
Explanation: The elements can be paired up into pairs (3,3) and (5,2).
The maximum pair sum is max(3+3, 5+2) = max(6, 7) = 7.
Example 2:

Input: nums = [3,5,4,2,4,6]
Output: 8
Explanation: The elements can be paired up into pairs (3,5), (4,4), and (6,2).
The maximum pair sum is max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8.


Constraints:

n == nums.length
2 <= n <= 105
n is even.
1 <= nums[i] <= 105

*/

        /*
        Algorithm

        1. Sort in decending order
        2. Now add the first and last elements to create a pair
        3. repeat the same all the way till the middle
        ( 8,6,5,2 - in this case pairwise sum max can be in the middle)
        4. create another vector to store the pairwise sum of size len/2
        5. find the maximum number
        */


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {

        // Sort the vector in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> pair;
        int n = nums.size();
        for (int i = 0; i < n / 2; i++)
        {
            pair.push_back( nums[i] + nums[n - i - 1]);
            cout<< pair[i];
        }

        // find maximum value in the vector
        int m = pair[0];
        for (int i = 1; i < n / 2; i++)
        {
            if (pair[i] >m)
            {
                m = pair[i];
            }
        }

        return m;
    }
};


int main(int argc, char const *argv[])
{
    Solution a;
    vector <int> num = {3,5,2,3};
    cout<<a.minPairSum(num);
    return 0;
}
