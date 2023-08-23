/*
2475. Number of Unequal Triplets in Array
Easy

https://leetcode.com/problems/number-of-unequal-triplets-in-array/

You are given a 0-indexed array of positive integers nums. Find the number of triplets (i, j, k) that meet the following conditions:

0 <= i < j < k < nums.length
nums[i], nums[j], and nums[k] are pairwise distinct.
In other words, nums[i] != nums[j], nums[i] != nums[k], and nums[j] != nums[k].
Return the number of triplets that meet the conditions.

 

Example 1:

Input: nums = [4,4,2,4,3]
Output: 3
Explanation: The following triplets meet the conditions:
- (0, 2, 4) because 4 != 2 != 3
- (1, 2, 4) because 4 != 2 != 3
- (2, 3, 4) because 2 != 4 != 3
Since there are 3 triplets, we return 3.
Note that (2, 0, 4) is not a valid triplet because 2 > 0.
Example 2:

Input: nums = [1,1,1,1,1]
Output: 0
Explanation: No triplets meet the conditions so we return 0.
 

Constraints:

3 <= nums.length <= 100
1 <= nums[i] <= 1000
*/

/*
Algorithm

First, we count numbers using a hash map m.

For numbers a, b and c, we can form m[a] * m[b] * m[c] unique triplets.

Say we have 26 numbers (a...z). Number n forms these number of triplets:

m[a] * m[n] * m[o] + ... + m[a] * m[n] * m[z] +
m[b] * m[n] * m[o] + ... + m[b] * m[n] * m[z] +
...
m[m] * m[n] * m[o] + ... + m[m] * m[n] * m[z].
This formula can be simplified as sum(m[a]...m[m]) * m[n] * sum(m[o]...m[z]).

We can track sum on the left and right of m[n] as we go.

What about 0 <= i < j < k condition? Actually, the relation does not matter.
What matters is that [i, j, k], [i, k, j], [k, i, j] and [k, j, i] represent the same triplet, so it should only be counted once.

*/

#include<bits/stdc++.h>
using namespace std;

// Assume that we have 4 kinds of numbers a, b, c, and d in the count map.
//
// What we want is:
//   cnt[a] * cnt[b] * cnt[c]
//   cnt[a] * cnt[b] * cnt[d]
//   cnt[a] * cnt[c] * cnt[d]
//   cnt[b] * cnt[c] * cnt[d]
//
// The above combinations can be reduced as:
//
// prev                       | curr   | next
// ----------------------------------------------------------------
// (0)                        * cnt[a] * (cnt[b] + cnt[c] + cnt[d])
// (cnt[a])                   * cnt[b] * (cnt[c] + cnt[d])
// (cnt[a] + cnt[b])          * cnt[c] * (cnt[d])
// (cnt[a] + cnt[b] + cnt[c]) * cnt[d] * (0)

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> unor;
        for(int i : nums){
            unor[i]++;
        }
        int left = 0,right=n,count=0;
        for(auto it = unor.begin();it!=unor.end();it++){
            right-=it->second;
            count+=left*it->second*right;
            left+=it->second;
        }
        return count;
    }
};

