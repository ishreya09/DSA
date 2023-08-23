/*
1399. Count Largest Group
Easy

https://leetcode.com/problems/count-largest-group/description/

You are given an integer n.

Each number from 1 to n is grouped according to the sum of its digits.

Return the number of groups that have the largest size.

 

Example 1:

Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according 
sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
There are 4 groups with largest size.
Example 2:

Input: n = 2
Output: 2
Explanation: There are 2 groups [1], [2] of size 1.
 

Constraints:

1 <= n <= 104
*/

/*
Algorithm

1. Make a function for calculating sum of digits
2. Create a map and find which has the max frequency in it
3. Iterate through the map and check which groups are equal to max frequency and return that count.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sod(int n){
        if(n==0){
            return n;
        }
        return (n%10)+ sod(n/10);
    }
    int countLargestGroup(int n) {
        int m=0;
        map<int,int> f;
        for(int i=1; i<=n;i++){
            int k=sod(i);
            f[k]++;
            if(f[k]>m){
                m=f[k];
            }
        }
        int c=0;
        for(auto it=f.begin();it!=f.end();it++){
            if(it->second==m){
                c++;
            }
        }
        return c;
    }
};