/*
11. Container With Most Water
Medium

https://leetcode.com/problems/container-with-most-water/

You are given an integer array height of length n. There are n vertical lines drawn 
such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

*/

/*
Algorithm

1. Using two pointer method but using a single loop
2. Here we are greedy by sticking to a height which is higher and moving accross the vector accordingly
3. if start height is more , we cross check area by varying height from the end
4. if end height is more, we check area by varying height from the start

*/



#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size(),start=0,end=n-1;
        int area=0,ans=0;
        while(start<end){
            area= min(height[start], height[end]) * (end-start);
            ans = max(ans, area);
            
            if(height[start] > height[end])
                end--;
            else
                start++;
        }
        
        return ans;
    }
};