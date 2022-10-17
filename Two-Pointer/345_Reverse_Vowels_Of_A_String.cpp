/*
345. Reverse Vowels of a String
Easy

https://leetcode.com/problems/reverse-vowels-of-a-string/

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.

*/

/*
Algorithm

1. Take 2 pointers from start and end and point on vowels only (Two Pointer method)
2. Once they both point on vowels, we swap them and traverse again

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c){
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || 
           c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
            return true;
        }
        else{
            return false;
        }
    }
    string reverseVowels(string s) {
        int i=0;
        int j= s.length()-1;
        while(i<j){
            if(!isVowel(s[i])){
                i++;
                continue;
            }
            if(!isVowel(s[j])){
                j--;
                continue;
            }
            char c= s[i];
            s[i]=s[j];
            s[j]=c;
            i++;
            j--;
        }
        return s;
    }
    
};