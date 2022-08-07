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

1. Use two pointer method 
2. and check from start and end if area is max or not
3. time ineffiecient and works only for small ranges

*/



#include<bits/stdc++.h>
using namespace std;

// time exceeded error - brute force method

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int x=0,y=0; // for width and height
        int area=0;
        for (int i =0 ; i<n; i++){
            for (int j=n-1;j>i;j--){
                x= (j-i);
                y= min (height[i],height[j]);
                if (x*y>area){
                    area=x*y;
                }
            }
        }
        return area;      
    }
};