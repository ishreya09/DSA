/*
1935. Maximum Number of Words You Can Type
Easy

https://leetcode.com/problems/maximum-number-of-words-you-can-type/

There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

Given a string text of words separated by a single space (no leading or trailing spaces) and 
a string brokenLetters of all distinct letter keys that are broken, return the number of 
words in text you can fully type using this keyboard.

 

Example 1:

Input: text = "hello world", brokenLetters = "ad"
Output: 1
Explanation: We cannot type "world" because the 'd' key is broken.
Example 2:

Input: text = "leet code", brokenLetters = "lt"
Output: 1
Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.
Example 3:

Input: text = "leet code", brokenLetters = "e"
Output: 0
Explanation: We cannot type either word because the 'e' key is broken.
 

Constraints:

1 <= text.length <= 104
0 <= brokenLetters.length <= 26
text consists of words separated by a single space without any leading or trailing spaces.
Each word only consists of lowercase English letters.
brokenLetters consists of distinct lowercase English letters.

*/

/*
Algorithm

1. Make a map of brokenLetters frequency and characters
2. a word gets completed when we encounter a space.
so when we encounter a space - we can check there after 
if the string has brokenLetters or not
*3. to terminate the last word, add a space character at the end of the string.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        text=text+" "; // to terminate the last word
        map<char,int> f;
        for(int i=0; i<brokenLetters.size(); i++){
            f[brokenLetters[i]]++;
        }
        int count=0;
        // a word gets completed when we encounter a space.
        // so when we encounter a space - we can check there after 
        // if the string has brokenLetters or not
        
        int i=0,flag=1;
        while(i<text.length()){
            if (text[i]==' '){
                cout<<flag<<endl;
                count+= flag;
                flag=1;
                i++;
                continue;
            }
            if(f[text[i]]){
                flag=0;
            }
            i++;
        }
        return count;
    }
};