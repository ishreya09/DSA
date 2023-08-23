/*
2506. Count Pairs Of Similar Strings
Easy

https://leetcode.com/problems/count-pairs-of-similar-strings/description/

You are given a 0-indexed string array words.

Two strings are similar if they consist of the same characters.

For example, "abca" and "cba" are similar since both consist of characters 'a', 'b', and 'c'.
However, "abacba" and "bcfd" are not similar since they do not consist of the same characters.
Return the number of pairs (i, j) such that 0 <= i < j <= word.length - 1 and the two strings words[i] and 
words[j] are similar.

 

Example 1:

Input: words = ["aba","aabb","abcd","bac","aabc"]
Output: 2
Explanation: There are 2 pairs that satisfy the conditions:
- i = 0 and j = 1 : both words[0] and words[1] only consist of characters 'a' and 'b'. 
- i = 3 and j = 4 : both words[3] and words[4] only consist of characters 'a', 'b', and 'c'. 
Example 2:

Input: words = ["aabb","ab","ba"]
Output: 3
Explanation: There are 3 pairs that satisfy the conditions:
- i = 0 and j = 1 : both words[0] and words[1] only consist of characters 'a' and 'b'. 
- i = 0 and j = 2 : both words[0] and words[2] only consist of characters 'a' and 'b'.
- i = 1 and j = 2 : both words[1] and words[2] only consist of characters 'a' and 'b'.
Example 3:

Input: words = ["nba","cba","dba"]
Output: 0
Explanation: Since there does not exist any pair that satisfies the conditions, we return 0.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consist of only lowercase English letters.

*/

/*
Algorithm

1. If we have k similar strings for an element - then no of pairs that can be 
formed will be (k(k-1))/2 for that similar string
2. Convert string to consise string which is sorted and contains no duplicates
3. Make that as the key of our map and count the frequency

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getString(string s){
        sort(s.begin(),s.end());
        auto it= s.begin();
        for(int i=1; i<s.length();i++){
            if (s[i]==s[i-1]){
                // delete
                s.erase(it+i);
                i--;
            }
        }
        return s;
    }
    int similarPairs(vector<string>& words) {
        map<string,int> f;
        for(int i=0; i<words.size();i++){
            string k= getString(words[i]);
            f[k]++;
        }
        int p=0;
        for (auto it =f.begin();it!=f.end();it++){
            if(it->second>=2){
                int t=it->second;
                p+= (t*(t-1))/2;
            }
        }
        return p;
    }
};