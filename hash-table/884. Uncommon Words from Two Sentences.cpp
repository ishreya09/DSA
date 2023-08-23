/*
884. Uncommon Words from Two Sentences
Easy

https://leetcode.com/problems/uncommon-words-from-two-sentences/description/

A sentence is a string of single-space separated words where each word consists only of lowercase letters.

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

 

Example 1:

Input: s1 = "this apple is sweet", s2 = "this apple is sour"
Output: ["sweet","sour"]
Example 2:

Input: s1 = "apple apple", s2 = "banana"
Output: ["banana"]
 

Constraints:

1 <= s1.length, s2.length <= 200
s1 and s2 consist of lowercase English letters and spaces.
s1 and s2 do not have leading or trailing spaces.
All the words in s1 and s2 are separated by a single space.
*/

/*
Algorithm

1. Get the array of all the words using space as the terminator
2. create a map and add the frequencies of the words 
3. If the frequency of any word is only 1- then add it to the answer's vector.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // similar to s.split(" ") in python
    vector<string> getWords(string s){
        s=s+" ";
        vector<string> ans;
        string k;
        for(int i=0;i<s.length();i++){
            if (s[i]==32){
                ans.push_back(k);
                k.erase();
                continue;
            }
            k.push_back(s[i]);
        }
        return ans;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> k1= getWords(s1);
        vector<string> k2= getWords(s2);
        map<string,int> a;
        for (int i=0; i<k1.size();i++){
            a[k1[i]]++;
        }
        for (int i=0; i<k2.size();i++){
            a[k2[i]]++;
        }
        vector<string> ans;
        for (auto & i: a){
            if(i.second==1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};