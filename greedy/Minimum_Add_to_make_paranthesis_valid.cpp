/*
921. Minimum Add to Make Parentheses Valid 
Medium

https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

 

Example 1:

Input: s = "())"
Output: 1
Example 2:

Input: s = "((("
Output: 3
 

Constraints:

1 <= s.length <= 1000
s[i] is either '(' or ')'.

*/

            /*
            Algorithm 

            1st Approach: 
            1. Keep the track of number of appearance ( and start adding 1 to a var (here op).
            2. For op>0 and character as ) - start decrementing the var op
            3. If op<0 and character is ) - then increment cp. 


            2nd approach :
            1. Search for () and change it to null immediately
            2. Repeat the same until there is no () left in the string and then return the length of the string
            */



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        // first approach
        if (s.length() == 0){
            return 2;
        }
        else {
            int op=0; // open paranthesis
            int cp=0; // closed paranthesis

            for (int i=0; i<s.length();i++){
                if (s[i]=='('){
                    op++; // open paranthesis
                }
                else if ( op >0){
                    op --; // closed paranthesis
                }
                else {
                    cp++; // there's no open bracket for this closed bracket, so we increment
                }               

            }
            
            return op+cp; 
        }
    }
};


int main(int argc, char const *argv[])
{
    string s= "((())((";
    s="(()())((";
    Solution a;
    cout<<a.minAddToMakeValid(s)<< endl;
    return 0;
}
