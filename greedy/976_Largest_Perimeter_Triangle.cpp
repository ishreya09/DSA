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

/*
Algorithm

1. sort in decending order 
2. initialize first and second side of triangle as first two elements of the array
3. Iterate through the rest of the array and find a pair which satisfies triangle law
4. If we don't find any third side in first iteration, shift first and second side of the triangle to adjacent sides
and then check for third side for the rest of the array. 
*/

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
                i=k;
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
