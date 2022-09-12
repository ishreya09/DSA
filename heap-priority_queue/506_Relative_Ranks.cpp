/*
506. Relative Ranks
Easy

https://leetcode.com/problems/relative-ranks/

You are given an integer array score of size n, where score[i] is the score of the ith 
athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, 
the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number 
(i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.


Example 1:

Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].
Example 2:

Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].

 

Constraints:

n == score.length
1 <= n <= 104
0 <= score[i] <= 106
All the values in score are unique.
*/

/*
Algorithm 

1. Make a priority queue containing pair. We set pq in default- so its already in decending order. Make
sure that first element is score of the player and 2nd element is index of ith player
2. Make a vector ans of score vector's length and then go on adding the values at p.top().second index and pop accordingly
3. Use to_string  function to convert integers to string.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> p;
        for (int i=0;i<score.size();i++){
            p.push(make_pair(score[i],i));
        }
        
        string st;
        int len=score.size();
        vector<string> ans(len);

        if(!p.empty()){
            ans[p.top().second]="Gold Medal";
            p.pop();
        }
        if(!p.empty()){
            ans[p.top().second]="Silver Medal";
            p.pop();
        }
        if(!p.empty()){
            ans[p.top().second]="Bronze Medal";
            p.pop();
        }

        int k=4;
        while(!p.empty()){
            // to_string is used to convert numbers(int) to string
            // append adds the value to the end of the string
            st =st.append(to_string(k++));
            ans[p.top().second]= st;
            p.pop();
            st="";
        }
        return ans;
    }
};