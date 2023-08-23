/*
1002. Find Common Characters
Easy

https://leetcode.com/problems/find-common-characters/

Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.


*/

/*
Algorithm

1. Write an intersection func among 2 strings
2. Check for each string and return the intersected string by iterating through the vector
3. Add the elements in that string to vector<string > ans. 
CONVERT CHAR TO STRING
string(1,s[i])- returns char as string
- its a string constructor
    
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string Intersection(string a, string b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i=0,j=0;
        string s;
        while(i<a.length() && j<b.length()){
            if (a[i]==b[j]){
                s.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i]>b[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return s;
    }
    vector<string> commonChars(vector<string>& words) {
        string s=words[0];
        for (int i=1; i<words.size();i++){
            s= Intersection(s,words[i]);
        }          
        vector<string> ans;  
        for(int i=0; i<s.length();i++){
            ans.push_back(string(1,s[i]));
        }
        return ans;
    }
};