
/*
767. Reorganize String
Medium

https://leetcode.com/problems/reorganize-string/

Given a string s, rearrange the characters of s so that any
two adjacent characters are not the same.

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

1.
2.
3.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reorganizeString(string s)
    {
        sort(s.begin(),s.end());
        vector<pair<int,char>> freq;
        pair<int,char> t;
        t.second= s[0];
        t.first =1;
        for (int i=1; i<s.length();i++){
            if(t.second== s[i]){
                t.first+=1;
            }
            if (t.second !=s[i]){
                freq.push_back(t);
                t.first=1;
                t.second=s[i];
            }   
        }
        freq.push_back(t);

        sort (freq.begin(), freq.end(), greater<int>());

        string st;
        st.resize(s.length());
        int idx=0,k=1;
        for (int i=0;i<freq.size();i++){

            while (freq[i].first!=0){
                    st[idx] = freq[i].second;
                    freq[i].first --;
                    idx+=2; // for adding on alternate positions
            }
            idx=0;
        }
        

        return st;
    }
};