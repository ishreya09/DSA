/*
20. Valid Parentheses
Easy

https://leetcode.com/problems/valid-parentheses/description/

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.


*/

/*
Algorithm

1. 
2. 
3.

*/

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int p=1;
        for (int i=0; i<s.length();i++){
          if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
          }
          else{
            if(st.empty()){
              return false;
            }
            cout<<st.top()<<"a"<<s[i]<<endl;
            if((s[i]==')' && st.top()=='(') || (s[i]==']' && st.top()=='[') || (s[i]=='}' && st.top()=='{'))
            {
              st.pop();
            }
            else{
              p=0;
            }
          }
        }
        return st.empty() && p;
    }
};