/*
821. Shortest Distance to a Character
Easy

https://leetcode.com/problems/shortest-distance-to-a-character/

Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.length 
and answer[i] is the distance from index i to the closest occurrence of character c in s.

The distance between two indices i and j is abs(i - j), where abs is the absolute value function.

 

Example 1:

Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
Explanation: The character 'e' appears at indices 3, 5, 6, and 11 (0-indexed).
The closest occurrence of 'e' for index 0 is at index 3, so the distance is abs(0 - 3) = 3.
The closest occurrence of 'e' for index 1 is at index 3, so the distance is abs(1 - 3) = 2.
For index 4, there is a tie between the 'e' at index 3 and the 'e' at index 5, but the distance is still the same: 
abs(4 - 3) == abs(4 - 5) = 1.
The closest occurrence of 'e' for index 8 is at index 6, so the distance is abs(8 - 6) = 2.
Example 2:

Input: s = "aaab", c = "b"
Output: [3,2,1,0]
 

Constraints:

1 <= s.length <= 104
s[i] and c are lowercase English letters.
It is guaranteed that c occurs at least once in s.

*/

/*
Algorithm

1. Take two pointers i and j and one extra pointer last which is initialised to -1.
j pointer is the index to the place where the char c is present in s
2. If i<j and last =-1, then we take the diff - i.e j-i as the ans
3. if i>j, we initialise last as j's previous value and check which of them gives the minimum distance
4. Suppose we don't find j later on, so we use abs(last -i) to find distance

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int last=-1;
        vector<int> ans;
        int j=0;
        int i=0;
        while(i<s.length()){
            while(j<s.length() && s[j]!=c){
                j++;
                continue;
            }
            if(s[i]!=c){
                if (last==-1){
                    ans.push_back(abs(j-i));
                    i++;
                }
                else if(j>=s.length()){
                    ans.push_back(abs(last-i));
                    i++;
                }
                else{
                    ans.push_back(min<int>(abs(j-i),abs(last-i)));
                    i++;
                }
            }
            else{
                ans.push_back(0);
                last=j;
                j++;
                i++;
            }
        }
        return ans;
    }
};