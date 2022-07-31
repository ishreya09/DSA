/*
409. Longest Palindrome
Easy

https://leetcode.com/problems/longest-palindrome/

Given a string s which consists of lowercase or uppercase letters, return the length 
of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.

*/

// Runtime: 7 ms, faster than 37.08% of C++ online submissions for Longest Palindrome.
// Memory Usage: 6.7 MB, less than 15.08% of C++ online submissions for Longest Palindrome.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        /*
        Algorithm

        1. The longest palindrome that can be made is equal to the string itself
        2. Make a map and count the frequency of a letter - sort it then according to the frequency of occurance (decending order)
        3. Even number frequencies can directly be added and split up - even if its odd , number- 1 can appear in the palindrome directly 
        4. Change the frequencies to either 0 or 1
        5. Add 1 if there exists an element with frequency as 1- as even if there are multiple elements of frequency 1, there can only
        be one single letter which can make it palindrome 
        
        */
       map <char,int> f; // frequency of letters
       for (int i=0;s[i]!=0;i++)
       {
            f[s[i]]++;
       }

        int len=0;
        int flag=0; // flag is used to check if there is any odd number of letters and checks if frequency would be one at last
       for (auto i = f.begin(); i!= f.end();i++){
            if (i->second % 2==0){
                len+= i->second;
            }
            else {
                len+= i->second-1;
                i->second = 1;
                flag =1;
                
            }
       }
       if (flag ==1){
        len++;
       }

       return len;
    }
};