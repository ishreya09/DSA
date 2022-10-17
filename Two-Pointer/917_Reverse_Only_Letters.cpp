/*
917. Reverse Only Letters
Easy

https://leetcode.com/problems/reverse-only-letters/

Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.

 

Example 1:

Input: s = "ab-cd"
Output: "dc-ba"
Example 2:

Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Constraints:

1 <= s.length <= 100
s consists of characters with ASCII values in the range [33, 122].
s does not contain '\"' or '\\'. 

*/

/*
Algorithm

1. isalpha(int ch) is a function which checks if the character is alphabet (a-z or A-Z ) or not.
2. We take two pointers, i starting from 0 - on the first alphabet found
We take j from the end - on the first alphabet found from the end
3. We swap them and increment i and decrement j and repeat step 2.
4. At last, when i<j, we return the string.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(!isalpha(s[i])){
                i++;
                continue;
            }
            if(!isalpha(s[j])){
                j--;
                continue;
            }
            char c=s[i];
            s[i]=s[j];
            s[j]=c;
            i++;
            j--;
        }
        return s;
    }
};