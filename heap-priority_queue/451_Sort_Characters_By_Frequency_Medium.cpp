/*
451. Sort Characters By Frequency
Medium

https://leetcode.com/problems/sort-characters-by-frequency/

Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.
*/

/*
Algorithm 

1. make a map for the frequency of characters
2. place the frequency and character in a priority queue so that they are sorted
3. then until the priority queue exausts, go on appending the character to a new string and 
return the new string

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        map<char,int> a;
        for (int i=0;i<s.length();i++){
            a[s[i]]++;
        }
        for(auto i= a.begin(); i!=a.end();i++){
            pq.push(make_pair(i->second,i->first));
        }
        string st;
        while(!pq.empty()){
            for (int i=0;i<pq.top().first;i++){
                st=st.append(1,pq.top().second);
            }
            pq.pop();
        }
        return st;
    }
};