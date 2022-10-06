/*
1370. Increasing Decreasing String
Easy

https://leetcode.com/problems/increasing-decreasing-string/

You are given a string s. Reorder the string using the following algorithm:

Pick the smallest character from s and append it to the result.
Pick the smallest character from s which is greater than the last appended character to the result and append it.
Repeat step 2 until you cannot pick more characters.
Pick the largest character from s and append it to the result.
Pick the largest character from s which is smaller than the last appended character to the result and append it.
Repeat step 5 until you cannot pick more characters.
Repeat the steps from 1 to 6 until you pick all characters from s.
In each step, If the smallest or the largest character appears more than once you 
can choose any occurrence and append it to the result.

Return the result string after sorting s with this algorithm.

 

Example 1:

Input: s = "aaaabbbbcccc"
Output: "abccbaabccba"
Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
Example 2:

Input: s = "rat"
Output: "art"
Explanation: The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.

*/

/*
Algorithm

1. Count the frequency of each character.
2. Loop over all character from 'a' to 'z' and append the character if it exists and decrease frequency by 1. Do the same from 'z' to 'a'.
3. Keep repeating until ans's length is equal to string's length. 

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortString(string s) {
        map<char,int> f;
        string ans;
        for(int i=0; i<s.length();i++){
            f[s[i]]++;
        }
        char c='a';
        int t=0; // traversal in acending order
        for (int i= 0; ans.length()!=s.length();i++){
            if(f[c]>0){
                // cout<< c<<endl;
                ans+=c;
                f[c]--;
            }
            if(t==0){
                c++;
            }
            if(t==1){
                c--;
            }
            if(t==0 && c==123){
                c='z';
                t=1;
            }
            if(t==1 && c==96){
                c='a';
                t=0;
            }
        }
        return ans;
    }
};
