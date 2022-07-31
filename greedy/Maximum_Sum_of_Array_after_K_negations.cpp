/*
1005. Maximize Sum Of Array After K Negations

Given an integer array nums and an integer k, modify the array in the following way:

choose an index i and replace nums[i] with -nums[i].
You should apply this process exactly k times. You may choose the same index i multiple times.

Return the largest possible sum of the array after modifying it in this way.



Example 1:

Input: nums = [4,2,3], k = 1
Output: 5
Explanation: Choose index 1 and nums becomes [4,-2,3].
Example 2:

Input: nums = [3,-1,0,2], k = 3
Output: 6
Explanation: Choose indices (1, 2, 2) and nums becomes [3,1,0,2].
Example 3:

Input: nums = [2,-3,-1,5,-4], k = 2
Output: 13
Explanation: Choose indices (1, 4) and nums becomes [2,3,-1,5,4].


Constraints:

1 <= nums.length <= 104
-100 <= nums[i] <= 100
1 <= k <= 104

*/

// Runtime: 16 ms, faster than 23.06% of C++ online submissions for Maximize Sum Of Array After K Negations.
// Memory Usage: 9.2 MB, less than 24.04% of C++ online submissions for Maximize Sum Of Array After K Negations.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {

        /*
        Algorithm

        1. Sort the array in accending order
        2. If there is a negative number - turn that into positive at once
        3. If there is a 0 in the array - it should be the second point to place all the negations
        as we can do negations on a single number more than once - creating maximum sum
        4. If the above 2 cases are taken care of - then use negation on the smallest number after sorting the array again-
        this minimum positive number can be applied with negation multiple times to get the maximum sum.
        Zero is surely not encountered if we come to this case and so , nums[0] will be the minimum number to flip for max sum


        */
        sort(nums.begin(), nums.end()); // sorts in accending order

        int i = 0;
        while (k > 0)
        {

            if (nums[i] < 0)
            {
                nums[i] = -nums[i];
                cout << nums[i]<< endl;
                k--; // decrementing value of k
                i++;
            }
            else if (nums[i] == 0)
            {
                cout << nums[i] << endl;
                k = 0; // all k to be applied on zero after negative numbers
            }
            else if (nums[i] > 0)
            {
               sort(nums.begin(), nums.end()); // sort in accending order again to check which is the minimum number now
                // Zero is surely not encountered if we come to this case and so , nums[0] will be the minimum number to flip for max sum
                nums[0] = pow(-1, k) * nums[0];
                cout << nums[0]<<endl;
                k=0;
            }
            if (i== nums.size()){
                i--;
            }
        }

        int max = accumulate(nums.begin(), nums.end(), 0); // maximum sum

        // stl gives a  accumulate() function in stl library
        // SYNTAX
        // accumulate(iterator start, iterator end, initial_sum_value);

        return max;
    }
};

int main(int argc, char const *argv[])
{
    // [2,-3,-1,5,-4]
    // 2
    vector<int> num = {-4,-2,-3};

    int k = 4;
    Solution a;
    cout << a.largestSumAfterKNegations(num, k);
    return 0;
}
