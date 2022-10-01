// Logical ERROR

/*

*/

/*
Algorithm 

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
                    int l= order[i][2];
                    while(l!=0){
                        auto it = buy.top();
                        buy.pop();
                        if(it.second<= order[i][0]){
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
                            buy.push(make_pair(order[i][0],l));
                        }  
                    }
                }
            }
        }
        
        int amt=0;
        
        while(!buy.empty()){
            auto it = buy.top();
            buy.pop();
            cout<<it.second<<"\t"<< amt<<endl;
            amt+=it.second;
            amt=amt%MOD;
        }
        while(!sell.empty()){
            auto it = sell.top();
            sell.pop();
            cout<<it.second<<"\t"<< amt<<endl;
            amt+=it.second;
            amt = amt%MOD;
        }
        
        return amt%MOD;
    }
};