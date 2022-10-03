/*
1801. Number of Orders in the Backlog
Medium

https://leetcode.com/problems/number-of-orders-in-the-backlog/

You are given a 2D integer array orders, where each orders[i] = [pricei, amounti, orderTypei] denotes that amounti orders 
have been placed of type orderTypei at the price pricei. The orderTypei is:

0 if it is a batch of buy orders, or
1 if it is a batch of sell orders.
Note that orders[i] represents a batch of amounti independent orders with the same price and order type. All orders represented 
by orders[i] will be placed before all orders represented by orders[i+1] for all valid i.

There is a backlog that consists of orders that have not been executed. The backlog is initially empty. When an order 
is placed, the following happens:

If the order is a buy order, you look at the sell order with the smallest price in the backlog. If that sell order's price is 
smaller than or equal to the current buy order's price, they will match and be executed, and that sell order will be removed 
from the backlog. Else, the buy order is added to the backlog.
Vice versa, if the order is a sell order, you look at the buy order with the largest price in the backlog. If that buy order's 
price is larger than or equal to the current sell order's price, they will match and be executed, and that buy order will be 
removed from the backlog. Else, the sell order is added to the backlog.
Return the total amount of orders in the backlog after placing all the orders from the input. Since this number can be large, 
return it modulo 109 + 7.

 

Example 1:


Input: orders = [[10,5,0],[15,2,1],[25,1,1],[30,4,0]]
Output: 6
Explanation: Here is what happens with the orders:
- 5 orders of type buy with price 10 are placed. There are no sell orders, so the 5 orders are added to the backlog.
- 2 orders of type sell with price 15 are placed. There are no buy orders with prices larger than or equal to 15, so the 2 orders are added to the backlog.
- 1 order of type sell with price 25 is placed. There are no buy orders with prices larger than or equal to 25 in the backlog, so this order is added to the backlog.
- 4 orders of type buy with price 30 are placed. The first 2 orders are matched with the 2 sell orders of the least price, which is 15 and these 2 sell orders are removed from the backlog. The 3rd order is matched with the sell order of the least price, which is 25 and this sell order is removed from the backlog. Then, there are no more sell orders in the backlog, so the 4th order is added to the backlog.
Finally, the backlog has 5 buy orders with price 10, and 1 buy order with price 30. So the total number of orders in the backlog is 6.
Example 2:


Input: orders = [[7,1000000000,1],[15,3,0],[5,999999995,0],[5,1,1]]
Output: 999999984
Explanation: Here is what happens with the orders:
- 109 orders of type sell with price 7 are placed. There are no buy orders, so the 109 orders are added to the backlog.
- 3 orders of type buy with price 15 are placed. They are matched with the 3 sell orders with the least price which is 7, and those 3 sell orders are removed from the backlog.
- 999999995 orders of type buy with price 5 are placed. The least price of a sell order is 7, so the 999999995 orders are added to the backlog.
- 1 order of type sell with price 5 is placed. It is matched with the buy order of the highest price, which is 5, and that buy order is removed from the backlog.
Finally, the backlog has (1000000000-3) sell orders with price 7, and (999999995-1) buy orders with price 5. So the total number of orders = 1999999991, which is equal to 999999984 % (109 + 7).
 

Constraints:

1 <= orders.length <= 105
orders[i].length == 3
1 <= pricei, amounti <= 109
orderTypei is either 0 or 1.


*/

/*
Algorithm 

1. Make 2 priority queue for buy and sell orders. buy pq is a max heap where as sell pq is min heap (should contain 
a pair of price and amount)
2. in case of buying,
i) if sell pq is empty - directly put all the amount of any price in the buy stack
ii) if sell pq is not empty - pop the min element and check if it is less than or equal to the value- 
if false, directly push all the amount and pop the top ele from sell stack, 
if true, go on decreasing the amount until the condition ii remains true and then push the remaining amount into the buy queue
3. in case of selling, its same as 2 - the changes are only in the case that we pop the max element from buy queue and check 
if buy price is greater than current sell price.
4. Count the total amount of the orders present in buy and sell pq and take the mod and return the ans.

*/

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& order) {
        priority_queue<pair<int,int>> buy; //price,amt
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> sell;
        
        for (int i=0; i<order.size();i++){
            if (order[i][2]==0){
                if (sell.empty()){
                    buy.push(make_pair(order[i][0],order[i][1]));
                }
                else{
                    int l= order[i][1];
                    while(l!=0){
                        auto it =sell.top();
                        sell.pop();
                        int k=l;
                        if(it.first<= order[i][0]){
                            l-=min<int>(l,it.second);
                            it.second-=min<int>(k,it.second);
                        }
                        else{
                            buy.push(make_pair(order[i][0],l));
                            sell.push(it);
                            break;
                        }
                        if(it.second>0){
                            sell.push(it);
                        }
                        if(sell.empty() && l>0){
                            buy.push(make_pair(order[i][0],l));
                            break;
                        }
                    }
                    
                }
            }
            else if (order[i][2]==1){
                if(buy.empty()){
                    sell.push(make_pair(order[i][0],order[i][1]));
                }
                else{
                    int l= order[i][1];
                    while(l!=0){
                        auto it = buy.top();
                        buy.pop();
                        if(it.first>= order[i][0]){
                            int k= l;
                            l-=min(l,it.second);
                            it.second -= min(k,it.second);
                        }
                        else{
                            sell.push(make_pair(order[i][0],l));
                            buy.push(it);
                            break;
                        }
                        if(it.second>0){
                            buy.push(it);
                        }
                        if(buy.empty() && l>0){
                            sell.push(make_pair(order[i][0],l));
                            break;
                        }  
                    }
                }
            }
        }
        
        int amt=0;
        
        while(!buy.empty()){
            auto it = buy.top();
            buy.pop();
            amt+=it.second;
            cout<<it.first<<"\t"<<it.second<<"\t"<< amt<<endl;
            amt=amt%MOD;
        }

        while(!sell.empty()){
            auto it = sell.top();
            sell.pop();
            amt+=it.second;
            cout<<it.first<<"\t"<<it.second<<"\t"<< amt<<endl;
            amt = amt%MOD;
        }
        

        
        return amt%MOD;
    }
};