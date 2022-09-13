/*
767. Reorganize String
Medium

https://leetcode.com/problems/reorganize-string/

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/

/*
Algorithm 

1. Make a map for frequency of characters
2. Store the map's data in a priority_queue  
3. To make the string alternatively, store the prev item that's poped in block and add one character of it into
the new string and decrease its frequency. Store this in block and initialize another iterator to p.top()
and add one element from there and pop it from there.
4. if (block.first>0 )- means frequency of previous character which was popped earlier 
is still there and so we push it back
in the priority queue and store the current iterator in the block.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        map <char,int> freq; 
        for(auto i:s){
            freq[i]++;
        }
        priority_queue<pair<int,char>> p;
        for(auto i=freq.begin();i!=freq.end();i++){
            p.push(make_pair(i->second,i->first));
        }
        
        string ans = "";
    
        auto it = p.top();
        p.pop();
        ans+=it.second; 
        it.first--; 
        auto block = it;
        
        while(!p.empty())
        {
            auto it = p.top();
            p.pop();
            ans+=it.second;
            it.first--;
            
            if(block.first>0)
            {
                p.push(block);
            }
            block = it;
        }
        if(block.first>0) 
            return "";
        return ans;
        
    }
};