// Runtime Error

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

1. Write a function to calculate binary numbers and calculate the sum of the grid
2. Create a function to flip the binary number of a row and compare the value of number without flipping
3. If after flipping , the number is more, then toggle the numbers in that row
4. the same logic is repeated for column - taking 0th col as LSB. 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // function to calculate binary numbers and calculate the sum of the grid
    int binarySum(vector<vector<int>> &grid){
        int sum=0;
        int k;
        for (int i=0; i<grid.size();i++){
            k=0;
            for (int j=grid[i].size()-1; j>=0;j--){
                k+= grid[i][j] << j-grid[i].size()+1; // left shift to multiply multiples of 2
            }
            sum=sum+k;
        }
        return sum;
    }

    bool flipRow(vector<vector<int>> &grid,int idx){
        int sumf =0;
        int sum =0;
        for (int j= grid[idx].size()-1;j>=0;j--){
            int k = !grid[idx][j];
            sumf += k<< j-grid[idx].size()+1;
            sum+= grid[idx][j]<< j-grid[idx].size()+1;
        }
        return (sum <= sumf);
    }

    bool flipCol(vector<vector<int>> &grid,int idx){
        int sumf=0;
        int sum=0;
        for (int j= grid.size()-1;j>=0;j--){
            int k = !grid[j][idx];
            sumf +=k << j-grid.size()+1;
            sum+= grid[j][idx]<<j-grid.size()+1;
        }
        return (sum <= sumf);

    }

    int matrixScore(vector<vector<int>> &grid)
    {
        int sum=0;
        // checking for row;
        for (int i=0; i<grid.size();i++){
            if (flipRow(grid,i)){
                // flip logic
                for (int p=0;p<grid[0].size();p++){
                    if (grid[i][p]==1){
                        grid[i][p]=0;
                    }
                    else {
                        grid[i][p]=1;

                    }
                }
            }
        }

        // checking for col
        for (int i=0; i<grid[0].size(); i++){
            if (flipCol(grid,i)){
                // flip logic
                for (int p=0;p<grid[0].size();p++){
                    if (grid[p][i]==1){
                        grid[p][i]=0;
                    }
                    else {
                        grid[p][i]=1;

                    }
                }

            }
        }

        return binarySum(grid);


    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}

