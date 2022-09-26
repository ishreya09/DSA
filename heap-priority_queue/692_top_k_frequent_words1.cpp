// https://leetcode.com/submissions/detail/503791717/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        auto cmp=[](pair<int,string> &a, pair<int,string> &b){
            if(a.first==b.first)return a.second>b.second;
            return a.first<b.first;
        };
        
        
        map<string,int>m;
        for(string i:words)
        {
            m[i]++;
        }
        
        vector<string>res;
        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(cmp)>q(cmp);
        for(auto i:m)
        {
            q.push(make_pair(i.second,i.first));
        }
        set<string>s;
        while(k--)
        {
        res.push_back(q.top().second);
        q.pop();
        }
        
        return res;
    }
};


// another sol
struct Compare {
    bool operator() (pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};

class Solution1 {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(int i=0; i<words.size(); i++)
            m[words[i]]++;
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> q;
        for(auto p : m)
            q.push({p.second, p.first});
        
        vector<string> ans;
        while(k--) {
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};