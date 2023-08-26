/*
205. Isomorphic Strings
Easy

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving 
the order of characters. No two characters may map to the same character, 
but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.


*/

/*
Algorithm

1. 
2. 
3.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>fs;
        map<char,char>ft; // two maps to check both ways if they are isomorphic
        for(int i=0;i<s.length();i++){
            if (fs[s[i]]!=0 && fs[s[i]]!=t[i]){
                return false;
            }
            if(ft[t[i]]!=0 && ft[t[i]]!=s[i]){
                return false;
            }
            fs[s[i]]=t[i];
            ft[t[i]]=s[i];
        }
        return true;
    }
};