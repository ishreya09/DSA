/*
2078. Two Furthest Houses With Different Colors
EASY

https://leetcode.com/problems/two-furthest-houses-with-different-colors/


There are n houses evenly lined up on the street, and each house is beautifully painted. 
You are given a 0-indexed integer array colors of length n, where colors[i] represents the color of the ith house.

Return the maximum distance between two houses with different colors.

The distance between the ith and jth houses is abs(i - j), where abs(x) is the absolute value of x.

 

Example 1:


Input: colors = [1,1,1,6,1,1,1]
Output: 3
Explanation: In the above image, color 1 is blue, and color 6 is red.
The furthest two houses with different colors are house 0 and house 3.
House 0 has color 1, and house 3 has color 6. The distance between them is abs(0 - 3) = 3.
Note that houses 3 and 6 can also produce the optimal answer.
Example 2:


Input: colors = [1,8,3,8,3]
Output: 4
Explanation: In the above image, color 1 is blue, color 8 is yellow, and color 3 is green.
The furthest two houses with different colors are house 0 and house 4.
House 0 has color 1, and house 4 has color 3. The distance between them is abs(0 - 4) = 4.
Example 3:

Input: colors = [0,1]
Output: 1
Explanation: The furthest two houses with different colors are house 0 and house 1.
House 0 has color 0, and house 1 has color 1. The distance between them is abs(0 - 1) = 1.
 

Constraints:

n == colors.length
2 <= n <= 100
0 <= colors[i] <= 100
Test data are generated such that at least two houses have different colors.

*/


// Runtime: 4 ms, faster than 65.93% of C++ online submissions for Two Furthest Houses With Different Colors.
// Memory Usage: 9.1 MB, less than 18.34% of C++ online submissions for Two Furthest Houses With Different Colors.



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        /*
        Algorithm -         
        Greedily, the maximum distance will come from either the pair of the leftmost house and possibly some house 
        on the right with a different color, or the pair of the rightmost house and possibly some house on 
        the left with a different color.

        1. start checking from the index 0 and the last element
        2. The first element which we encounter as different is stored in max
        3. Check Further for any other chance of getting any maximum element 
        4. Since the constraint is less, this method works but might fail if larger constraints are given
        */
        int max=0;
        int l = colors.size();
        int k;

        for (int i=0; i <l/2+1;i++)
        {
            k=0;
            while(k<l-i) // think of more memory efficient prg
            {
                if (colors[i] != colors[l-k-1])
                {   
                    if (max < l-k-1-i)
                    {
                        max= l-k-1-i; // index of later house - index of previous house

                    }
                }
                k++;
            
            }
        }

        return max;
    }
};

int main()
{
    Solution A;
    vector <int> color={1,1,1,6,1,1,1};
    // [4,4,4,11,4,4,11,4,4,4,4,4] - output -8 getting -6
    int k=A.maxDistance(color);
    cout<< k<< endl;
    return 0;
}