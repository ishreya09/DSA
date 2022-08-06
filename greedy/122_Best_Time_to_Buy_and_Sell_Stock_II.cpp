/*
122. Best Time to Buy and Sell Stock II
Medium

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most 
one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock 
to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
*/

/*
Algorithm

1. make a switch to check if we have to buy or sell the stock 
2. if we have to buy a stock, then prices[i] < prices[i+1]
3. if we have to sell a stock, then prices[i]>prices[i+1]

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()==1){
            return 0;
        }
        bool buy =true;
        int profit=0;
        int i;
        for ( i=0;i<prices.size()-1;i++){
            if (buy){
                if (prices[i] <= prices[i+1]){
                    profit -= prices[i];
                    buy=false;
                }
            }
            else{
                if (prices[i+1]<= prices[i]){
                    profit+= prices[i];
                    buy=true;
                }
            }
        }
        if (prices[i] >= prices[i-1]){
            profit+= prices[i];
        }
        
        return profit;
    }
};