/*
392. Is Subsequence
Easy

https://leetcode.com/problems/is-subsequence/

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of 
the characters 
without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" 
while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
 

Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by 
one to see if t has its subsequence. In this scenario, how would you change your code? 

*/

/*
Algorithm

1. Take two pointers one at start of s and another at start of t 
2. if the subsequence is empty- return true, otherwise check if the character is equal to t[j] and increment the value until
both characters are equal.
3. if i reaches its last index and last character is also matched in the main string - then return true,any other case- false.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0; // for s
        int j=0; // for t
        if (s[0]==0){
            return true;
        }
        while(i<s.length() && j<t.length()){
            if(s[i]!=t[j]){
                j++;
            }
            else{
                if(i==s.length()-1){
                    return true;
                }
                i++;
                j++;
            }
        }
        return false;
    }
};