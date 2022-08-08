/*
1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
Medium

https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided 
in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 10^9 + 7.



Example 1:


Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.
Example 2:


Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.
Example 3:

Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
Output: 9


Constraints:

2 <= h, w <= 109
1 <= horizontalCuts.length <= min(h - 1, 105)
1 <= verticalCuts.length <= min(w - 1, 105)
1 <= horizontalCuts[i] < h
1 <= verticalCuts[i] < w
All the elements in horizontalCuts are distinct.
All the elements in verticalCuts are distinct.

*/

/*
Algorithm

1. Add 0 and h to horizontalCuts array and 0 and w to verticalCuts array 
2. Sort the arrays in accending order
3. Now find the maximum difference in horizontal form and then in vertical form
4. Since the answer can be a large number, return this modulo 10^9 + 7-  defined with a long int or long long int.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        long long int maxh = horizontalCuts[0];
        long long int maxv = verticalCuts[0];
        long long int mod= pow(10,9)+7;

        for (int i = 1; i < horizontalCuts.size(); i++)
        {
            if (horizontalCuts[i] - horizontalCuts[i - 1] > maxh)
            {
                maxh = horizontalCuts[i] - horizontalCuts[i - 1];
            }
        }
        for (int i = 1; i < verticalCuts.size(); i++)
        {
            if (verticalCuts[i] - verticalCuts[i - 1] > maxv)
            {
                maxv = verticalCuts[i] - verticalCuts[i - 1];
            }
        }

        return (maxh * maxv)%mod ;
    }
};