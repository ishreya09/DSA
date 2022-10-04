/*
771. Jewels and Stones
Easy

https://leetcode.com/problems/jewels-and-stones/

You're given strings jewels representing the types of stones that are jewels, and 
stones representing the stones you have. Each character in stones is a type of stone you have. 
You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

 

Example 1:

Input: jewels = "aA", stones = "aAAbbbb"
Output: 3
Example 2:

Input: jewels = "z", stones = "ZZ"
Output: 0
 

Constraints:

1 <= jewels.length, stones.length <= 50
jewels and stones consist of only English letters.
All the characters of jewels are unique.


*/

/*
Algorithm

1. Count the frequency of char in stones - using map
2. traverse through jewels and add the freq of those stones using map

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int> f;
        for (int i=0; i<stones.length();i++){
            f[stones[i]]++;
        }
        int ans=0;
        for (int i=0; i<jewels.length();i++){
            ans+= f[jewels[i]];
        }
        return ans;
    }
};