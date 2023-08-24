/*
1189. Maximum Number of Balloons
Easy

https://leetcode.com/problems/maximum-number-of-balloons/description/

Given a string text, you want to use the characters of text to form as many 
instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:



Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0
 

Constraints:

1 <= text.length <= 104
text consists of lower case English letters only.
*/

/*
Algorithm

1. 
2. 
3.

*/

#include<bits/stdc++.h>
using namespace std;




class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> f;
        for(char i:text){
            f[i]++;
        }
        map<char,int> b={
            {'b',1},{'a',1},{'l',2},{'o',2},{'n',1}
        };
        int m=f['b'];
        for (auto [c,freq]:b){
            m=min<int>(m,f[c]/freq);
        }
        return m;
    }
};