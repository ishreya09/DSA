/*
1705. Maximum Number of Eaten Apples
Medium

https://leetcode.com/problems/maximum-number-of-eaten-apples/

There is a special kind of apple tree that grows apples every day for n days. On the ith day, 
the tree grows apples[i] apples that will rot after days[i] days, that is on day i + days[i] the 
apples will be rotten and cannot be eaten. On some days, the apple tree does not grow any apples, 
which are denoted by apples[i] == 0 and days[i] == 0.

You decided to eat at most one apple a day (to keep the doctors away). Note that you can keep eating after the first n days.

Given two integer arrays days and apples of length n, return the maximum number of apples you can eat.

 

Example 1:

Input: apples = [1,2,3,5,2], days = [3,2,1,4,2]
Output: 7
Explanation: You can eat 7 apples:
- On the first day, you eat an apple that grew on the first day.
- On the second day, you eat an apple that grew on the second day.
- On the third day, you eat an apple that grew on the second day. After this day, 
the apples that grew on the third day rot.
- On the fourth to the seventh days, you eat apples that grew on the fourth day.
Example 2:

Input: apples = [3,0,0,0,0,2], days = [3,0,0,0,0,2]
Output: 5
Explanation: You can eat 5 apples:
- On the first to the third day you eat apples that grew on the first day.
- Do nothing on the fouth and fifth days.
- On the sixth and seventh days you eat apples that grew on the sixth day.
 

Constraints:

n == apples.length == days.length
1 <= n <= 2 * 104
0 <= apples[i], days[i] <= 2 * 104
days[i] = 0 if and only if apples[i] = 0.

*/

/*
Algorithm 

1. assign k which will store the day number (index) at which the current apples will rot and if apples[i]>0 and k>i - we push
it to a min heap priority queue of pairs with first element as the day number when apples will rot.
2. if priority_queue is not empty, we first pop out the old rotten apples first and then pop the non rotten apple once again. We take this element and
decrement the number of apples and push back if ( apples[i]>0 and k>i )
3. in case the current apple is getting rotten today itself, rather than the other apples, we eat that current day's apple first. 
This case is valid when k is equal to index i.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > p; // min heap
        int k=0; // day no at which apples will rot
        // k= i+day[i]-1
        int i;
        int count=0;
        for(i=0;i<days.size();i++){
            k=i+days[i]-1;
            
            if ((p.empty() && apples[i]!=0)){
                apples[i]--;
                count++;
                if (apples[i]>0 && k>i){
                    p.push(make_pair(k,apples[i]));
                }
            }
            else if (!p.empty() && k==i && p.top().first > k){
                // when there is a decision on whether to eat today's apple or the left apple
                apples[i]--;
                count++;
                if (apples[i]>0 && k>i){
                    p.push(make_pair(k,apples[i]));
                }
            }
            else if (!p.empty()){
                if (apples[i]>0 && k>i)
                    p.push(make_pair(k,apples[i]));
                while (p.top().first < i){
                    p.pop();
                }
                auto it= p.top();
                p.pop();
                it.second--; // decrementing one apple
                count++;
                if(it.first>i && it.second>0){
                    p.push (it);
                }                
            }
        }
        while(!p.empty()){
            auto it = p.top();
            p.pop();
            if (it.first>= i){
                it.second--;
                i++;
                count++; 
                if (it.second>0 and it.first>=i){
                    p.push(it);
                }
            
            }
        }
        return count;
    }
};