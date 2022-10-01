/*
2182. Construct String With Repeat Limit
Medium

https://leetcode.com/problems/construct-string-with-repeat-limit/

You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s 
such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.

Return the lexicographically largest repeatLimitedString possible.

A string a is lexicographically larger than a string b if in the first position where a and b differ, string a 
has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) 
characters do not differ, then the longer string is the lexicographically larger one.

 

Example 1:

Input: s = "cczazcc", repeatLimit = 3
Output: "zzcccac"
Explanation: We use all of the characters from s to construct the repeatLimitedString "zzcccac".
The letter 'a' appears at most 1 time in a row.
The letter 'c' appears at most 3 times in a row.
The letter 'z' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, 
so it is not a valid repeatLimitedString.
Example 2:

Input: s = "aababab", repeatLimit = 2
Output: "bbabaa"
Explanation: We use only some of the characters from s to construct the repeatLimitedString "bbabaa". 
The letter 'a' appears at most 2 times in a row.
The letter 'b' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "bbabaa".
Note that the string "bbabaaa" is lexicographically larger but the letter 'a' appears more than 2 times in a row, 
so it is not a valid repeatLimitedString.
 

Constraints:

1 <= repeatLimit <= s.length <= 105
s consists of lowercase English letters.
*/

/*
Algorithm 
1. We want to form a lexicographically largest string using the characters in a given string.
But we have to make sure that a letter is not repeated more than the given limit in a row (i.e consecutively).
2. So we use a priority_queue to pop the element which has the highest priority. 
If it's count is less than the repeatLimit, we directly add to the ans.
3. But if it's count is greater than the repeatLimit, we just add the repeatLimit 
amount of the present character and we pop out the next priority character and add a single letter to the ans.
4. This makes that a letter is not repeated more than limit in a row and lexicographically largest is maintained. 
After adding to the ans, if we have extra characters left out, we just push back into priority_queue for the next use.
5. Here if we are not able to pop, the next priority character, we just return the ans so as we cannot add more 
than repeatedLimit charecters in a row.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int k) { // k is the repeatLimit
        int n = s.length();
        unordered_map<char,int> m;
        for(int i=0;i<n;i++) m[s[i]]++;
        priority_queue<pair<char,int>> pq;
        for(auto i: m){
            pq.push({i.first,i.second}); // pushing the characters with their frequencies.
        }
        
        string ans = "";
        while(!pq.empty()){
            char c1 = pq.top().first;
            int n1 = pq.top().second;
            pq.pop();
                
            int len = min(k,n1); // Adding characters upto minimum of repeatLimit and present character count.
            for(int i=0;i<len;i++){ // adding the highest priority element to the ans.
                ans += c1;
            }
            
            char c2;
            int n2=0;
            if(n1-len>0){ // If the cnt of present character is more than the limit.
                if(!pq.empty()){ //Getting the next priority character.
                    c2 = pq.top().first;
                    n2 = pq.top().second;
                    pq.pop();
                }
                else{
                    return ans; // if there is no another letter to add, we just return ans.
                }
                ans += c2; // Adding next priority character to ans.
                
                // If the elements are left out, pushing them back into priority queue for next use.
                pq.push({c1,n1-len});
                if(n2-1>0) pq.push({c2,n2-1}); 
            }
        }
        return ans;
    }
};