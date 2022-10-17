/*
541. Reverse String II
Easy

https://leetcode.com/problems/reverse-string-ii/

Given a string s and an integer k, reverse the first k characters for every 2k characters 
counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but 
greater than or equal to k characters, then reverse the first k characters and leave the other as original.

 

Example 1:

Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Example 2:

Input: s = "abcd", k = 2
Output: "bacd"
 

Constraints:

1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 104

*/

/*
Algorithm

1. initialise i as 0 and j at i+k-1 pos and store it in last
2. swap all elements and then reinitialise i as last+k+1 and j as i+k-1 and store the new j in last
3. Repeat step 2 until we traverse the string.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int i=0; 
        int j=min<int>(i+k-1,s.length()-1);
        
        while(i<s.length()){
            int last =j;
            while(i<j){
                char c = s[i];
                s[i]=s[j];
                s[j]=c;
                i++;
                j--;
            }
            i=last+k+1;
            j=min<int>(i+k-1,s.length()-1);
        }
        return s;
    }
};