/*
2027. Minimum Moves to Convert String
Easy

https://leetcode.com/problems/minimum-moves-to-convert-string/

You are given a string s consisting of n characters which are either 'X' or 'O'.

A move is defined as selecting three consecutive characters of s and converting them to 'O'. 
Note that if a move is applied to the character 'O', it will stay the same.

Return the minimum number of moves required so that all the characters of s are converted to 'O'.



Example 1:

Input: s = "XXX"
Output: 1
Explanation: XXX -> OOO
We select all the 3 characters and convert them in one move.
Example 2:

Input: s = "XXOX"
Output: 2
Explanation: XXOX -> OOOX -> OOOO
We select the first 3 characters in the first move, and convert them to 'O'.
Then we select the last 3 characters and convert them so that the final string contains all 'O's.
Example 3:

Input: s = "OOOO"
Output: 0
Explanation: There are no 'X's in s to convert.


Constraints:

3 <= s.length <= 1000
s[i] is either 'X' or 'O'.

*/

#include <bits/stdc++.h>
using namespace std;

        /*
        Algorithm

        1. If we encounter X we can count 1 move and start from current char + 2 postion
        2. Repeat 1 till we reach the end of the string
        3. Nothing happens if O is encountered.
        */



class Solution
{
public:
    int minimumMoves(string s)
    {
        int move = 0;

        for (int i= 0; i<s.length();i++){
            if(s[i]=='X'){
                move++;
                i+=2;
            }
        }

        return move;
    }
};
