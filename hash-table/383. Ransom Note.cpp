/*
383. Ransom Note
Easy

https://leetcode.com/problems/ransom-note/description/

Given two strings ransomNote and magazine, return true if ransomNote can be 
constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
*/

/*
Algorithm

1. Make a freq of magazine
2. Decrement and check if ransomNote can be satisfied by the magazine's freq.

*/

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> f;
        for (auto i:magazine){
            f[i]++;
        }
        for (auto i:ransomNote){
            if(f[i]--<=0){
                return false;
            }
        }
        return true;
    }
};