/*
2342. Max Sum of a Pair With Equal Sum of Digits
Medium

https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

You are given a 0-indexed array nums consisting of positive integers. You can choose two indices 
i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

 

Example 1:

Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.
Example 2:

Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

/*
Algorithm 

1. Make a pq p to store the numbers on the basis of sum of digits. If the sum of digit is same- then we give max number 
more priority
2. We take out the first 2 elements of the pq p and if they both are equal - we push the sum in another max heap pq sums.
We pop both the elements and we also now pop any more numbers with same sod. 
3. If they both are not equal - we pop the first element - but not the second and continue the loop
4. We check if sums pq is empty or it - if its empty - then return -1 otherwise return the top element.

*/

#include<bits/stdc++.h>
using namespace std;

int sod(int n){
    if(n==0){
        return 0;
    }
    return n%10+sod(n/10);
}

struct Compare {
    bool operator() (int a, int b) {
        if (sod(a)==sod(b)){
            return a<=b;
        }
        else {
            return sod(a)<sod(b);
        }
        
    }
};

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        priority_queue<int,vector<int>, Compare> p(begin(nums),end(nums));
        priority_queue<int> sums;
        
        while (!p.empty()){
            int a=p.top();
            p.pop();
            int b=0;
            if (!p.empty())
                b= p.top();
            else{
                break;
            }
            if (sod(a)!=sod(b)){
            
                continue;
            }
            else{
                p.pop();
                sums.push(a+b);
                while ( !p.empty() && sod(p.top())==sod(a)){
                    p.pop();
                }
            }
        }
        int ans;
        if (sums.empty()){
            ans=-1;
        }
        else{
            ans= sums.top();
        }
        return ans;
        
    }
};