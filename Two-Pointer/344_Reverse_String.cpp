/*
344. Reverse String
Easy

https://leetcode.com/problems/reverse-string/

Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.

*/

/*
Algorithm

1. Use s.begin functions to traverse through the array and make changes using it's pointer
2. Use Two pointer method to reverse.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        auto i=s.begin();
        auto j= s.rbegin();
        int mid= (s.size()-1)/2;
        while (i!=s.begin()+mid+1){
            char c=*i;
            *i=*j;
            *j=c;
            j++;
            i++;
            
        }
    }
};
