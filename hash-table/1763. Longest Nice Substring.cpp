/*
1763. Longest Nice Substring
Easy

https://leetcode.com/problems/longest-nice-substring/description/

A string s is nice if, for every letter of the alphabet that s contains, 
it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, 
and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.

Given a string s, return the longest substring of s that is nice. If there are multiple, return the 
substring of the earliest occurrence. If there are none, return an empty string.

 

Example 1:

Input: s = "YazaAay"
Output: "aAa"
Explanation: "aAa" is a nice string because 'A/a' is the only letter of the 
alphabet in s, and both 'A' and 'a' appear.
"aAa" is the longest nice substring.
Example 2:

Input: s = "Bb"
Output: "Bb"
Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
Example 3:

Input: s = "c"
Output: ""
Explanation: There are no nice substrings.
 

Constraints:

1 <= s.length <= 100
s consists of uppercase and lowercase English letters.
*/

/*
Algorithm

1. Use an unordered set and insert all the characters
2. Iterate through the string and check if its upper case and lower case exists or not
3. If yes- continue to iterate
4. Else- create two substrings and call the recursive function as 
the nice string can now either be in left or in right part of the given string
compare their lengths and return the max length substring of left and right part.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        if(n==1) return "";
        unordered_set<char>uset;
        for(int i =0 ; i<n ; i++){
           uset.insert(s[i]);
        }
        for(int i = 0 ; i<n ; i++){
        if(uset.count(tolower(s[i]))== true && uset.count(toupper(s[i]))== true) continue;
        string prev = longestNiceSubstring(s.substr(0,i)); // create two substring to compare length 
        string next = longestNiceSubstring(s.substr(i+1));
        return prev.size()>=next.size()? prev:next; // return substring of max. length
        }
        return s; // if whole string is nice string
    }
};