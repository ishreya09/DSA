/*
2000. Reverse Prefix of Word
Easy

https://leetcode.com/problems/reverse-prefix-of-word/

Given a 0-indexed string word and a character ch, reverse the segment of word that starts 
at index 0 and ends at the index of the first occurrence of ch (inclusive). 
If the character ch does not exist in word, do nothing.

For example, if word = "abcdefd" and ch = "d", then you should reverse the 
segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".

Return the resulting string.
 

Example 1:

Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"
Explanation: The first occurrence of "d" is at index 3. 
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "dcbaefd".
Example 2:

Input: word = "xyxzxe", ch = "z"
Output: "zxyxxe"
Explanation: The first and only occurrence of "z" is at index 3.
Reverse the part of word from 0 to 3 (inclusive), the resulting string is "zxyxxe".
Example 3:

Input: word = "abcd", ch = "z"
Output: "abcd"
Explanation: "z" does not exist in word.
You should not do any reverse operation, the resulting string is "abcd".
 

Constraints:

1 <= word.length <= 250
word consists of lowercase English letters.
ch is a lowercase English letter.

*/

/*
Algorithm

1. Traverse through the word and check the index of first occurance of ch
2. If ch is fount, use two pointer method to reverse it from ch's index in word.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int flag=0;
        int idx=0;
        for (int i=0;i<word.length();i++){
            if (ch==word[i]){
                idx=i;
                flag=1;
                break;
            }
        }
        if (flag==0){
            return word;
        }
        
        int i=0; // using as iterator
        while (i<idx){
            char c=word[i];
            word[i] = word[idx];
            word[idx]=c;
            
            i++;
            idx--;
        }
        return word;
    }
};