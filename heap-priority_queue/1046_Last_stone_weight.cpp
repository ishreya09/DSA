/*
1046. Last Stone Weight
Easy

https://leetcode.com/problems/last-stone-weight/

You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. 
Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

 

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
Example 2:

Input: stones = [1]
Output: 1
 

Constraints:

1 <= stones.length <= 30
1 <= stones[i] <= 1000
*/

/*
Algorithm 
1. If the vector size is 0 or 1, return 0 and stone[0] respectively
2. Otherwise, enter all the elements into a priority queue of intergers and then go on poping the first 2 elements of the 
priority queue and store their difference in diff
3. If diff is not zero, we push diff into the priority queue and we repeat the same until pq.size()!=1 or it is empty.
4. We return 0 if pq is empty otherwise pq.top().
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1){
            return stones[0];
        }
        if(stones.size()==0){
            return 0;
        }
        
        priority_queue<int> s;
        for (int i=0;i<stones.size();i++){
            s.push(stones[i]);
        } // pq is sorted in decending order

        int diff=0;
        int x,y;
        while (!s.empty() && s.size()!=1){
            y=s.top();
            s.pop();
            x=s.top();
            s.pop();
            diff=y-x;
            if(diff!=0){
                s.push(diff);
            }
        }
        return s.empty()? 0 : s.top();
        

    }
};