/*
389. Find the Difference
Easy

https://leetcode.com/problems/find-the-difference/description/

You are given two strings s and t.

String t is generated by random shuffling string s and then add one more letter at a random position.

Return the letter that was added to t.

 

Example 1:

Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.
Example 2:

Input: s = "", t = "y"
Output: "y"
 

Constraints:

0 <= s.length <= 1000
t.length == s.length + 1
s and t consist of lowercase English letters.
*/

/*
Algorithm

1. Make map freq for s
2.  Check for t simentaneously

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> f;
        for (auto i:s){
            f[i]++;
        }
        for (auto i:t){
            if(f[i]--==0){
                return i;
            }
        }
        return t[0];
    }
};