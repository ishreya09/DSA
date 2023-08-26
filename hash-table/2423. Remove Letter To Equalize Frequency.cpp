/*
2423. Remove Letter To Equalize Frequency
Easy

https://leetcode.com/problems/remove-letter-to-equalize-frequency/description/

You are given a 0-indexed string word, consisting of lowercase English letters. 
You need to select one index and remove the letter at that index from word so that 
the frequency of every letter present in word is equal.

Return true if it is possible to remove one letter so that the frequency of all letters 
in word are equal, and false otherwise.

Note:

The frequency of a letter x is the number of times it occurs in the string.
You must remove exactly one letter and cannot chose to do nothing.
 

Example 1:

Input: word = "abcc"
Output: true
Explanation: Select index 3 and delete it: word becomes "abc" and each character has a frequency of 1.
Example 2:

Input: word = "aazz"
Output: false
Explanation: We must delete a character, so either the frequency of "a" is 1 and the frequency 
of "z" is 2, or vice versa. It is impossible to make all present letters have equal frequency.
 

Constraints:

2 <= word.length <= 100
word consists of lowercase English letters only.

*/

/*
Algorith

Approach
With a map of frequencies you can figure out what is the most frequent frequency, 
if you multiply it with the number of letters with that frequency you know how many 
letters are "good" and then with the numbers of remaining letters you know if you 
can equalize the word or not (if its 1 you can remove the letter, if its 1+max_frequency 
you can remove the extra letter. In every other cases you can not equalize the word).

Example :
abccadd -> size=7
'a' -> 2
'b' -> 1
'c' -> 2
'd' -> 2

     a  c  d
2*(1+1+1)=6
7-6=1 we can just get rid of the remaining letter

if we had 9 letters  (3*2 + 1*3)
9-6 = 3 != 1 but lets try addind one to the most common frequency (which is 2)
(3+1)*2=8
9-8=1 we can just get rid of the remaining letter

Complexity
Time complexity:
O(n)

Space complexity:
O(n)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        if (word.empty()) return false;
        unordered_map<char,int> mp; // frequencies of letters
        for (auto x:word) mp[x]++;

        int number_of_letters=0;
        unordered_map<int,int> mp2; // frequencies of frequencies
        for (auto x:mp) {
            number_of_letters++;
            mp2[x.second]++;
        }
        int max=0, max_element=0;
        // max_element = most common frequency
        // max = frequency of max_element
        for (auto x:mp2) {
            if (x.second>max) {max=x.second; max_element=x.first;}
            else if (x.second==max&&x.first>max_element) max_element=x.first;
        }
        if (number_of_letters==2&&(max_element*2-1==word.size())) return true; // edge case
        if (number_of_letters==word.size()||number_of_letters==1) return true; // edge case
        return (max_element*(max+1)==word.size()-1)||(max_element*max==word.size()-1);
    }
};