/*
1861. Rotating the Box
Medium

https://leetcode.com/problems/rotating-the-box/


You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box 
is one of the following:

A stone '#'
A stationary obstacle '*'
Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls 
down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' 
positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.

 

Example 1:



Input: box = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]
Example 2:



Input: box = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]
Example 3:



Input: box = [["#","#","*",".","*","."],
              ["#","#","#","*",".","."],
              ["#","#","#",".","#","."]]
Output: [[".","#","#"],
         [".","#","#"],
         ["#","#","*"],
         ["#","*","."],
         ["#",".","*"],
         ["#",".","."]]
 

Constraints:

m == box.length
n == box[i].length
1 <= m, n <= 500
box[i][j] is either '#', '*', or '.'.
*/

/*
Algorithm

1. Start iterating from the bottom of the box and for each empty cell check if 
there is any stone above it with no obstacles between them. (using j and k)
2. Rotate the box using the relation rotatedBox[i][j] = box[m - 1 - j][i].

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n= box[0].size();
        for (int i=0; i<box.size();i++){
            int j =box[i].size()-1; // for #
            int k =box[i].size()-1; // for .
            while(j>=0 && k>= 0){
                if(box[i][k]!='.'){
                    k--;
                    j=k;
                    continue;
                }
                if (box[i][j]=='*'){
                    j--;
                    k=j;
                    continue;
                }
                if(box[i][j]!='#'){
                    j--;
                    continue;
                }
                swap(box[i][k],box[i][j]);
            }
        }
        vector<vector<char>> ans(n,vector<char>(m));
        int s=0;
        for (int i=0; i<n; i++){
            int t=0;
            for (int j=m-1; j>=0; j--){
                ans[s][t]=box[j][i];
                t++;
            }
            s++;
        }
        return ans;
    }
};