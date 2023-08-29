/*
2186. Minimum Number of Steps to Make Two Strings Anagram II
Medium

https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/description/

You are given two strings s and t. In one step, you can append any character to either s or t.

Return the minimum number of steps to make s and t anagrams of each other.

An anagram of a string is a string that contains the same characters with a different 
(or the same) ordering.

 

Example 1:

Input: s = "leetcode", t = "coats"
Output: 7
Explanation: 
- In 2 steps, we can append the letters in "as" onto s = "leetcode", forming s = "leetcodeas".
- In 5 steps, we can append the letters in "leede" onto t = "coats", forming t = "coatsleede".
"leetcodeas" and "coatsleede" are now anagrams of each other.
We used a total of 2 + 5 = 7 steps.
It can be shown that there is no way to make them anagrams of each other with less than 7 steps.
Example 2:

Input: s = "night", t = "thing"
Output: 0
Explanation: The given strings are already anagrams of each other. Thus, we do not need any further steps.
 

Constraints:

1 <= s.length, t.length <= 2 * 105
s and t consist of lowercase English letters.

*/

/*
Algorithm

1. Make a map for both strings seperately
2. we try the logic of intersection of two maps and traverse and calculate the difference of characters
in both maps in ans variable
3. Return ans.

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSteps(string s, string t) {
        if(t.empty()){
            return s.length();
        }

        if(s.empty()){
            return t.length();
        }
        map<int,int> fs;
        map<int,int> ft;
        for(auto i:s){
            fs[i]++;
        }
        for(auto i:t){
            ft[i]++;
        }
        int ans=0;


        // similar to intersection of two maps 
        auto is=fs.begin();
        auto it=ft.begin();
        while(is!=fs.end() && it!=ft.end()){
            if(is->first==it->first){//"abbc","abc"
                ans+= abs(is->second-it->second);
                it++;
                is++;
            }
            else if(is->first>it->first){
                ans+= it->second;
                it++;
            }
            else{
                ans+= is->second;
                is++;
            }
        }
        while (is!=fs.end()){
            ans+=is->second;
            is++;
        }
        while (it!=ft.end()){
            ans+=it->second;
            it++;
        }
        return ans;
    }
};