/*
125. Valid Palindrome
Easy

https://leetcode.com/problems/valid-palindrome/

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and 
removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric 
characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.


*/

/*
Algorithm

1. We make use of isalnum() function which takes a character and checks if it is alphanumeric or not
2. Tranform is a function which could be used like map in python - here used to convert to lowercase.
3. Remove all the other elements from string and then reverse it and check if its same.

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        for (int i=0;i<s.length();i++){
            if(!isalnum(s[i])  || s[i]==' '){
                s.erase(s.begin()+i);
                i--;
            }
        }
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string b=s;
        reverse(b.begin(),b.end());
        cout<< s<<endl;
        cout<< b<<endl;
        return b==s;
    }
};