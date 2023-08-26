/*
49. Group Anagrams
Medium

https://leetcode.com/problems/group-anagrams/description/

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.


*/

/*
Algorithm

1. Take a map with key as string and value as a vector of strings
2. Iterate through strs and sort the string. Keep the sorted value of string in key and unsorted value to be pushed 
in the vector of that key
3. Iterate through the map at last and append all the vectors in a 2D array.

*/

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> f;
        for(auto i:strs){
            string k=i;
            sort(k.begin(),k.end());
            f[k].push_back(i);
        }
        vector<vector<string>> ans;
        for (auto &i:f){
            ans.push_back(i.second);
        }
        return ans;
    }
};