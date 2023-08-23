/*
242. Valid Anagram
Easy

https://leetcode.com/problems/valid-anagram/description/

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?


*/

/*
Algorithm

1. Sort both strings
2. Check if both are equal at the same time
3. If not - return false - else return true.

*/

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i= 0;i<s.length();i++){
            if(s[i]!=t[i]){
                return false;
            }
        }
        return true;
    }
};