/*
1832. Check if the Sentence Is Pangram
Easy

https://leetcode.com/problems/check-if-the-sentence-is-pangram/

A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

 

Example 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
Example 2:

Input: sentence = "leetcode"
Output: false
 

Constraints:

1 <= sentence.length <= 1000
sentence consists of lowercase English letters.
*/

/*
Algorithm

1. calculate frequency of all the character using a map and check if size of map is equal to 26 or not


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char,int>f;
        for(int i=0; i<sentence.length();i++){
            f[sentence[i]]++;
        }
        return f.size()==26;
    }
};