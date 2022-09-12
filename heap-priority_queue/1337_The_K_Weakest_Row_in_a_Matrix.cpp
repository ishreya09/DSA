/*
1337. The K Weakest Rows in a Matrix
Easy

https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). 
The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all 
the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

 

Example 1:

Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 2 
- Row 1: 4 
- Row 2: 1 
- Row 3: 2 
- Row 4: 5 
The rows ordered from weakest to strongest are [2,0,3,1,4].
Example 2:

Input: mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
Output: [0,2]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 1 
- Row 1: 4 
- Row 2: 1 
- Row 3: 1 
The rows ordered from weakest to strongest are [0,2,3,1].
 

Constraints:

m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] is either 0 or 1.


*/

/*
Algorithm 

1. Make a priority queue which contains pairs.
2. We can make the priority queue in ascending order using this line.
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> p;
Push the no of 1's in first position as first element is used for comparision and make the index as 2nd element
3. Use this pq and store the value in the a vector k times and return the vector
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> p;
        int j,c;
        for(int i=0; i<mat.size();i++){
            j=0;
            c=0;
            while(j<mat[i].size()){
                if (mat[i][j]==1){
                    c++;
                }
                j++;
            }
            p.push(make_pair(c,i));
        }
        vector <int> ans;
        
        while(k--){
            ans.push_back(p.top().second);
            p.pop();
        }

        return ans;

    }
};