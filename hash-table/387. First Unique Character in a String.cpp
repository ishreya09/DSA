/*
387. First Unique Character in a String
Easy

https://leetcode.com/problems/first-unique-character-in-a-string/description/

Given a string s, find the first non-repeating character in it and 
return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.

*/

/*
Algorithm

1. 
2. 
3.

*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int id=-1;
    int f=0;
};

class Solution {
public:
    int firstUniqChar(string s) {
       map<char,Node> f;
       for(auto i=0; i<s.length();i++){
           if(f[s[i]].id==-1)
                f[s[i]].id=i; // lower idx
            f[s[i]].f++;
       } 
       for(auto i:s){
           if(f[i].f==1){
               return f[i].id;
           }
       }

       return -1;
    }
};