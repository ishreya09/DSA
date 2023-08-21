/*
500. Keyboard Row
Easy

https://leetcode.com/problems/keyboard-row/

Given an array of strings words, return the words that can be typed using letters 
of the alphabet 
on only one row of American keyboard like the image below.

In the American keyboard:

the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".

 

Example 1:

Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]
Example 2:

Input: words = ["omk"]
Output: []
Example 3:

Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"]
 

Constraints:

1 <= words.length <= 20
1 <= words[i].length <= 100
words[i] consists of English letters (both lowercase and uppercase). 

*/

/*
Algorithm

1. make a map adding all the characters (upper and lower case) into the map with keyboard's row number 
2. Check if for each number- if row number remains same- we add it to the ans vector.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s1="qwertyuiop";
        string s2="asdfghjkl";
        string s3="zxcvbnm";
        // char , row no
        map<char,int> keyboard;
        for (int i=0; i<s1.length();i++){
            keyboard[s1[i]]=1;
            keyboard[s1[i]-32]=1;
        }
        for (int i=0; i<s2.length();i++){
            keyboard[s2[i]]=2;
            keyboard[s2[i]-32]=2;
        }
        for (int i=0; i<s3.length();i++){
            keyboard[s3[i]]=3;
            keyboard[s3[i]-32]=3;
        }
        
        vector<string> ans;
        for (auto &i : words){
            int flag=keyboard[i[0]];
            cout<< i <<"\t"<<flag<<endl;
            for (int j=1; j<i.length();j++){
                if(flag != keyboard[i[j]]){
                    flag=-1;
                    break;
                }
            }
            if (flag!=-1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};