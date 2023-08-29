/*
290. Word Pattern
Easy

https://leetcode.com/problems/word-pattern/

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
*/

/*
Algorithm

1. Write a split function in cpp for strings
2. if no. of words and pattern don't have same length- return false.
2. iterate through pattern and list of words and store it in a map and create another map to store the opposite
3. Check if all pattern[i] have unique words and all words have a unique pattern[i].
4. If its true throughout the list - return true- else false

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getWord(string s){
        s+=" ";
        int k=0;
        string ans;
        vector<string> t;
        while(k<s.length()){
            if(s[k]==' '){
                t.push_back(ans);
                ans.clear();
                k++;
            }
            ans.push_back(s[k++]);
        }
        return t;
    }
    bool wordPattern(string pattern, string s) {
        map<char,string> f;
        map<string,char> r;

        vector<string> st= getWord(s);
        if(pattern.length()!= st.size()){
            return false;
        }
        for(int i=0; i<pattern.size();i++){
            cout<< pattern[i]<<" "<<st[i]<<"/"<<endl;
            if(f.count(pattern[i])){
                if(f[pattern[i]]!=st[i]){
                    return false;
                }
            }
            f[pattern[i]]=st[i];
            if(r.count(st[i])){
                if(r[st[i]]!=pattern[i]){
                    return false;
                }
            }
            r[st[i]]=pattern[i];

        }
        return true;
    }
};