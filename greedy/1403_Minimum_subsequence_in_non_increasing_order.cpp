/*
1403. Minimum Subsequence in Non-Increasing Order
Easy

https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/

Given the array nums, obtain a subsequence of the array whose sum of elements is strictly greater than the 
sum of the non included elements in such subsequence. 

If there are multiple solutions, return the subsequence with minimum size and if there still exist multiple 
solutions, return the subsequence with the maximum total sum of all its elements. A subsequence of an array 
can be obtained by erasing some (possibly zero) elements from the array. 

Note that the solution with the given constraints is guaranteed to be unique. Also return the answer sorted 
in non-increasing order.

 

Example 1:

Input: nums = [4,3,10,9,8]
Output: [10,9] 
Explanation: The subsequences [10,9] and [10,8] are minimal such that the sum of their elements is strictly greater than the sum of elements not included, however, the subsequence [10,9] has the maximum total sum of its elements. 
Example 2:

Input: nums = [4,4,7,6,7]
Output: [7,7,6] 
Explanation: The subsequence [7,7] has the sum of its elements equal to 14 which is not strictly greater than the sum of elements not included (14 = 4 + 4 + 6). Therefore, the subsequence [7,6,7] is the minimal satisfying the conditions. Note the subsequence has to returned in non-decreasing order.  
Example 3:

Input: nums = [6]
Output: [6]
 

Constraints:

1 <= nums.length <= 500
1 <= nums[i] <= 100
*/

// https://leetcode.com/submissions/detail/762655865/



        /*
        Algoritm

        1. sort the array in accending order
        2. sum1 contains sum of elements in decending order/ or from the back
        3. sum2 contains sum of elements from the start
        4. Calculate simetaneously and check - faster than previous one
        
        */

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) 
    {
        vector<int>result;
        sort(nums.begin(), nums.end());
        int sum1 =0;
        for(int i = nums.size()-1; i >= 0; i--){

            sum1 += nums[i]; 
            int sum2 = accumulate(nums.begin(), nums.end()+i-nums.size(), 0);
            
            cout<< sum1 << "\t" << sum2<<endl;
            result.push_back(nums[i]); //
            if(sum1 > sum2){
                
                break;
            }

        }
        
        
        return result;
    }
    
};


int main(int argc, char const *argv[])
{
    vector <int> a= {4,3,10,9,8};

    a= {86,86,33,25,65,77,33,50,32,86,38,80,33,92,19,92,81,35,47,75,93,36,65,83,29,99,25,69,85,3,14,28,36,22,95,42,29,21,84,83,5,78,29,50,34,33,28,82,34,49,6,99,5,20,93,64,56,39,47,52,100,46,80,26,37,36,34,62,80,20,75,46,19,50,8,10,34,10,100,64,27,59,40,6,35,44,1,89,87,79,64,56,56,55,97,47,78,93,63,98,25,95,56,51,38,13,11,94,21,91,44,47,73,55,91,49,16,49,7,56,78,26,15,30,89,62,50,23,88,18,29,80,13,89,45,42,65,57,99,22,49,81,62,73,24,5,65,26,88,32,98,17,16,36,72,2,1,48,37,28,7,40,85,87,19,17,9,92,21,76,54,35,98,17,10,25,98,21,78,54,28,51,70,63,23,78,9,64,32,27,10,88,20,32,25,79,79,90,19,71,34,9,99,97,74,48,11,46,68,36,23,85,73,61,56,72,74,91,72,29,17,71,76,16,56,95,55,48,29,57,87,72,51,43,86,73,24,7,99,7,48,80,60,21,85,93,60,74,48,46,20,59,26,70,62,69,37,77,27,17,78,29,37,14,86,12,84,30,55,66,28,86,39,64,92,8,49,27,82,90,7,40,96,39,80,27,55,2,98,59,42,54,32,83,14,22,65,7,95,49,21,3,66,64,63,48,71,55,4,83,77,86,56,50,31,67,2,72,81,6,84,26,83,41,5,18,57,90,23,58,19,19,33,65,49,89,12,66,16,10,90,50,62,47,27,5,68,53,29,62,26,22,31,26,68,86,44,83,90,39,62,99,79,74,65,31,98,28,37,16,99,73,2,98,5,80,41,12,68,84,23,59,70,11,53,93,18,70,6,92,18,41,86,96,46,58,96,25,52,60,11,51,47,2,37,28,
    75,46,48,81,1,13,58,98,52,40,90,23,39,95,84,29,96,43,43,28,6,7,3,91,24,77,60,42,92,5,35,76,68,35,9,92};
    
    a = Solution().minSubsequence(a);
    cout << "Elements are \n";
    for (int i=0; i<a.size(); i++){
        cout << a[i] << endl;
    }
    return 0;
}