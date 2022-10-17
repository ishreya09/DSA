/*
925. Long Pressed Name
Easy

https://leetcode.com/problems/long-pressed-name/

Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, 
and the character will be typed 1 or more times.

You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, 
with some characters (possibly none) being long pressed.

 

Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it was not in the typed output.
 

Constraints:

1 <= name.length, typed.length <= 1000
name and typed consist of only lowercase English letters.

*/

/*
Algorithm

1. Take 2 pointers and count the frequency for each character in name and typed until we encounter next character
2. If c>c1 - it means that count of that letter is more in name than in typed- so we return false
3. if letters don't match - we again return false
4. If the above 2 conditions are not true, we return true.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0;
        int j=0;
        while(i<name.length() && j<typed.length()){
            char k= name[i];
            // cout<<k<<endl;
            int c=0;
            while (i<name.length() && name[i]==k){
                i++;
                c++;
            }
            int c1=0;
            // cout<<typed[j]<<" "<<k<<endl;
            if (typed[j]!= k){ // characters only don't match
                return false;
            }
            while (j<typed.length() && typed[j]==k){
                j++;
                c1++;
            }
            // cout<<c<<" "<<c1 <<endl;
            if(c>c1){ // count of that letter in name is more than that of in typed
                return false;
            }
        }
        if (i<name.length() || j<typed.length()){ // strings got exausted before checking
            return false;
        }
        return true;
    }
};