/*
844. Backspace String Compare
Easy

https://leetcode.com/problems/backspace-string-compare/

Given two strings s and t, return true if they are equal when both are typed into empty text editors. 
'#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 

Follow up: Can you solve it in O(n) time and O(1) space?

*/

/*
Algorithm

1. take s and t seperately and delete two character i and i-1 when a # is encountered
2. when # is in the begining - only delete the #character as nothing is typed in text editor
3. at last check if t and s is same or not.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=0; // for s
        while(i<s.length()){
            if(s[i]=='#'){
                i--;
                if(i<0){
                    i++;
                    s.erase(s.begin()+i);
                }
                else{
                    s.erase(s.begin()+i);
                    s.erase(s.begin()+i);
                }
            }
            else{
                i++;
            }
        }
        i=0;
        while(i<t.length()){
            if(t[i]=='#'){
                i--;
                if(i<0){
                    i++;
                    t.erase(t.begin()+i);
                }
                else{
                    t.erase(t.begin()+i);
                    t.erase(t.begin()+i);
                }
            }
            else{
                i++;
            }
        }
        
        return t==s;
    }
};