/*
861. Score After Flipping Matrix
Medium

https://leetcode.com/problems/score-after-flipping-matrix/

You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).



Example 1:


Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
Example 2:

Input: grid = [[0]]
Output: 1


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 20
grid[i][j] is either 0 or 1.


*/

/*
Algorithm

1. First flip the rows so that we get maximum binary number. SO if we have 0 as first element of each row, then flip 
the matrix
2. Now when it comes to columns, count 0s and 1s in a column and if count of 0s > count of 1's - then flip that particular
column
3. At last use left shift to find the binary numbers and return the ans.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        for(int i=0;i<grid.size();i++)
        {
            if(grid[i][0]==0)
            {
                for(int j=0;j<grid[0].size();j++)
                {
                    if(grid[i][j]==0)
                        grid[i][j]=1;
                    else
                        grid[i][j]=0;
                }
            }
        }
        
        for(int i=0;i<grid[0].size();i++)
        {
            int count0=0;
            int count1=0;
            
            for(int j=0;j<grid.size();j++)
            {
                if(grid[j][i]==0)
                    count0++;
                else
                    count1++;
            }
            
            if(count0>count1)
            {
                for(int j=0;j<grid.size();j++)
                {
                    if(grid[j][i]==0)
                        grid[j][i]=1;
                    else
                        grid[j][i]=0;
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            int x=0;
            for(int j=grid[0].size()-1;j>=0;j--)
            {
                ans+=grid[i][j]<<x;
                x++;
            }
        }
        
        return ans;
    }
};


