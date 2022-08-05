/*
1433. Check If a String Can Break Another String
Medium

https://leetcode.com/problems/check-if-a-string-can-break-another-string/

Given two strings: s1 and s2 with the same size, check if some permutation of string s1 can 
break some permutation of string s2 or vice-versa. In other words s2 can break s1 or vice-versa.

A string x can break string y (both of size n) if x[i] >= y[i] (in alphabetical order) 
for all i between 0 and n-1.

 

Example 1:

Input: s1 = "abc", s2 = "xya"
Output: true
Explanation: "ayx" is a permutation of s2="xya" which can break to string "abc" which is a permutation of s1="abc".
Example 2:

Input: s1 = "abe", s2 = "acd"
Output: false 
Explanation: All permutations for s1="abe" are: "abe", "aeb", "bae", "bea", 
"eab" and "eba" and all permutation for s2="acd" are: "acd", "adc", "cad", "cda", 
"dac" and "dca". However, there is not any permutation from s1 which can break some 
permutation from s2 and vice-versa.
Example 3:

Input: s1 = "leetcodee", s2 = "interview"
Output: true
 

Constraints:

s1.length == n
s2.length == n
1 <= n <= 10^5
All strings consist of lowercase English letters.

*/

/*
Algorithm
1. Sort both the strings 
2. now to check if one string can break another string i.e. s1[i]>= s2[i] for all i
- make a function as the logic will be rewritten for 
the opposite thing as well
3. return if one string can break another.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool break_string (string s1,string s2){
        for (int i=0; i<s1.length(); i++){
            if (!(s1[i]>= s2[i])){
                return false;
            }
        }
        return true;
    }
    bool checkIfCanBreak(string s1, string s2) {
        sort (s1.begin(),s1.end());
        sort (s2.begin(),s2.end());

        return (break_string(s1,s2) || break_string(s2,s1));    
    }
};