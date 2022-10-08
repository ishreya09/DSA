/*
2309. Greatest English Letter in Upper and Lower Case
Easy

https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/

Given a string of English letters s, return the greatest English letter which occurs as both a 
lowercase and uppercase letter in s. The returned letter should be in uppercase. 
If no such letter exists, return an empty string.

An English letter b is greater than another letter a if b appears after a in the English alphabet.

 

Example 1:

Input: s = "lEeTcOdE"
Output: "E"
Explanation:
The letter 'E' is the only letter to appear in both lower and upper case.
Example 2:

Input: s = "arRAzFif"
Output: "R"
Explanation:
The letter 'R' is the greatest letter to appear in both lower and upper case.
Note that 'A' and 'F' also appear in both lower and upper case, but 'R' is greater than 'F' or 'A'.
Example 3:

Input: s = "AbCdEfGhIjK"
Output: ""
Explanation:
There is no letter that appears in both lower and upper case.
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase and uppercase English letters.

*/

/*
Algorithm

1. Store all the characters in a map and go on checking simentaneously if we have the corresponding lowercase or uppercase letter in map
or not. If we find, we add to the set or pq also works (max-heap)
2. For set, return the last element and for pq - pop the last element

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        map<char, int> f;
        set <char> a;
        for (int i=0;i<s.length();i++){
            f[s[i]]++;
            if (islower(s[i])){
                if (f[s[i]-32]>0){
                    a.insert(s[i]-32);
                }
            }
            else if (isupper(s[i])){
                if (f[s[i]+32]>0){
                    a.insert(s[i]);
                }
            }
        }
        string s1;
        if (!a.empty())
            s1+= *(a.rbegin());
        return s1;
    }
};