/*
1827. Minimum Operations to Make the Array Increasing

Easy * #

https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/

You are given an integer array nums (0-indexed). In one operation, you can choose an element 
of the array and increment it by 1.

For example, if nums = [1,2,3], you can choose to increment nums[1] to make nums = [1,3,3].
Return the minimum number of operations needed to make nums strictly increasing.

An array nums is strictly increasing if nums[i] < nums[i+1] for all 0 <= i < nums.length - 1. 
An array of length 1 is trivially strictly increasing.

 

Example 1:

Input: nums = [1,1,1]
Output: 3
Explanation: You can do the following operations:
1) Increment nums[2], so nums becomes [1,1,2].
2) Increment nums[1], so nums becomes [1,2,2].
3) Increment nums[2], so nums becomes [1,2,3].
Example 2:

Input: nums = [1,5,2,4,1]
Output: 14
Example 3:

Input: nums = [8]
Output: 0
 

Constraints:

1 <= nums.length <= 5000
1 <= nums[i] <= 104
*/

/*
Algorithm

Since we have to make the Array Strictly increasing in minimum number of operations
1. Iterate through the vector and check if the previous number in the array is greater than the next number
2. If the above condition is true, take the difference of both of them 
3. Add that difference +1 to the next number in the vector
4. add difference+1 to the count as well as we can increment one element only once
            
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int minOperations(vector<int> &num){

            int count=0;

            for (int i=0; i<num.size()-1; i++){ // num.size()-1 is done so as to avoid index error
                if (num[i]>= num[i+1]){
                    int m = num[i]-num[i+1]; 
                    num[i+1] += m+1; 
                    count += m+1;  // number of times required to make the 
                    // next number greater the previous number
                }
            }


            return count;
        }

};

int main(int argc, char const *argv[])
{
    Solution a;
    vector<int> v= {1,5,2,4,1};
    int k=a.minOperations(v);  
    cout<< k;  
    return 0;
}
