/*
1768. Merge Strings Alternately
Easy

https://leetcode.com/problems/merge-strings-alternately/

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, 
starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 

Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.

*/

/*
Algorithm

1. Traverse with one pointer to the start of the array and another pointer to the start of another array 
2. And  add both of them and keep on traversing
3. Check whose length is not exausted by the end and push back the rest of the elements in the array ans

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i;
        while(i<min(word1.length(),word2.length()) ){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
            i++;
        }
        while(i<word1.length()){
            ans.push_back(word1[i]);
            i++;
        }
        while(i<word2.length()){
            ans.push_back(word2[i]);
            i++;
        }
        return ans;
    }
};