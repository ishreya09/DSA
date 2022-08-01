/*
976. Largest Perimeter Triangle
Easy

https://leetcode.com/problems/largest-perimeter-triangle/

Given an integer array nums, return the largest perimeter of a triangle with a 
non-zero area, formed from three of these lengths. If it is impossible to form any 
triangle of a non-zero area, return 0.

 

Example 1:

Input: nums = [2,1,2]
Output: 5
Example 2:

Input: nums = [1,2,1]
Output: 0
 

Constraints:

3 <= nums.length <= 104
1 <= nums[i] <= 106
*/


// Runtime: 52 ms, faster than 63.20% of C++ online submissions for Largest Perimeter Triangle.
// Memory Usage: 21.9 MB, less than 72.31% of C++ online submissions for Largest Perimeter Triangle.

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // sort in decending order
        sort (nums.begin(),nums.end(),greater<int>());
        
        int a = nums[0], b= nums[1],c=0,p=0,k=2;
        
        for (int i=2; i<nums.size(); i++){
            c= nums[i];
            if (a+b>c && b+c >a && a+c >b){
                cout << "c= "<< c<< endl;
                p=1;
                break;
            }
            if (i== nums.size()-1 && p==0){
                i=(k);
                a= nums[k-1];
                b= nums[k];
                k++;
            }
        }
        
        if (p==1){
            return a+b+c;
        }        
        else{
            return 0;
        }
    }
};


int main(int argc, char const *argv[])
{
    vector <int> a= {6,3,3,2};
    a={18,8,4,2,2,1};
    cout <<Solution().largestPerimeter(a);
    return 0;
}
