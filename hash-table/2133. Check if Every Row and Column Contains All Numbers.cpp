/*
2133. Check if Every Row and Column Contains All Numbers
Easy

https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/description/

An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).

Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.

 

Example 1:

Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
Output: true
Explanation: In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
Hence, we return true.


Example 2:

Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
Output: false
Explanation: In this case, n = 3, but the first row and the first column do not contain the numbers 2 or 3.
Hence, we return false.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
1 <= matrix[i][j] <= n

*/

/*
Algorithm

1. Take a map and add the elements horizontally for a row and vertically for a column 
and check if all elements from 1 to n are equal to 1 in map or not.
2. If not - return false
3. If it satisfies for all - return true

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        map<int,int>fh;
        map<int,int>fv;

        int flag=1;
        int n=matrix.size();
        for (int i=0; i<n;i++){ // for rows
            for(int j=0; j<n;j++){
                fh[matrix[i][j]]++;
                fv[matrix[j][i]]++;
            }
            for(int i=1;i<=n;i++){
                if(fh[i]!=1){
                    return false;
                }
                if(fv[i]!=1){
                    return false;
                }

            }
            fh.clear();
            fv.clear();
        }
        
        return true;
    }
};