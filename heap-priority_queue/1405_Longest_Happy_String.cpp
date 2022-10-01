/*
1405. Longest Happy String
Medium

https://leetcode.com/problems/longest-happy-string/     

A string s is called happy if it satisfies the following conditions:

s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. 
If there are multiple longest happy strings, return any of them. 
If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.
 

Constraints:

0 <= a, b, c <= 100
a + b + c > 0
*/

/*
Algorithm 
1. Create a max heap of the form pair<int,char> to store the count of each character.
2. while (pq.size()>1)Pop out the first 2 pair who have the max frequency.
3. Add greedily the occurances of the first pair to the ans and update it's count.
4. For the second pair, compare it's occurances with the first pair and add accordingly.
5. Finally add the pairs to the Max Heap if their count>0.
6. If pq.empty() return ans, else add the leftover character to the ans according to the remaining counts and return the ans
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        //using max heap
        priority_queue<pair<int,char>>pq;
        if(a)
        pq.push({a,'a'});
        if(b)
        pq.push({b,'b'});
        if(c)
        pq.push({c,'c'});
        string ans="";
        while(pq.size()>1){
            pair<int,char>one = pq.top();pq.pop();
            pair<int,char>two = pq.top();pq.pop();
            if(one.first>=2){
                ans+=one.second;
                ans+=one.second;
                one.first-=2;
            }
            else{
                ans+=one.second;
                one.first-=1;
            }
            if(two.first>=2 && two.first>=one.first){
                ans+=two.second;
                ans+=two.second;
                two.first-=2;
            }
            else{
                ans+=two.second;
                two.first-=1;
            }
            if(one.first>0)
                pq.push(one);
            if(two.first>0)
                pq.push(two);
        }
        if(pq.empty())
            return ans;
        if(pq.top().first>=2){
            ans+=pq.top().second;
            ans+=pq.top().second;
        }
        else{
            ans+=pq.top().second;
        }
        return ans;
        
    }
};