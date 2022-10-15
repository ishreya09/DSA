/*
2108. Find First Palindromic String in the Array
Easy

https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

Given an array of strings words, return the first palindromic string in the array. 
If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.

 

Example 1:

Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.
Example 2:

Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".
Example 3:

Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists only of lowercase English letters.

*/

/*
Algorithm

1. Traverse through the array words and use two pointers for each word.
2. Have a flag=1 to denote if a string is palindrome or not. 
Make it 0 if the strings don't match and break from the two pointer's loop
3. When we find flag as 1, we return that word.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (int i=0;i<words.size();i++){
            int it=0;
            int j=words[i].length()-1;
            int flag=1;
            while (it<j){
                if (words[i][it]!= words[i][j]){
                    flag=0;
                    break;
                }
                it++;
                j--;
            }
            if(flag==1){
                return words[i];
            }
            
        }
        return "";
    }
};