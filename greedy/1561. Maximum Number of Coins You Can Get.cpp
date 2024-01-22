/*
1561. Maximum Number of Coins You Can Get
Medium

https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/

*/

/*
Algorithm

First, arrange the piles of coins from largest to smallest.
Then, calculate the number of rounds we can play. In each round, we pick the second-largest pile.
Finally, it returns the total number of collected coins.

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans=0;
        sort(piles.begin(), piles.end(), greater<int>());
        int len=piles.size()/3;
        for(int i=1;i<piles.size()-len;i+=2){
            ans+=piles[i];
        }
        return ans;
    }
};