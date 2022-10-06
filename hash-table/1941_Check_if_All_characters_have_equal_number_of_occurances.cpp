/*
1941. Check if All Characters Have Equal Number of Occurrences
Easy

https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/

Given a string s, return true if s is a good string, or false otherwise.

A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

 

Example 1:

Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
Example 2:

Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.


*/

/*
Algorithm

1. Count frequency of characters and check if frequency is same or not

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char,int> f;
        for (int i=0;i<s.length();i++){
            f[s[i]]++;
        }
        int k = f.begin()->second;
        bool flag = true;
        for (auto i= f.begin();i!=f.end();i++){
            if(k!=i->second){
                flag=false;
                break;
            }
        }
        
        return flag;
    }
};
