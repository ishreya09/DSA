/*
1903. Largest Odd Number in String
Easy

https://leetcode.com/problems/largest-odd-number-in-string/

You are given a string num, representing a large integer. Return the largest-valued odd integer
(as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.



Example 1:

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
Example 2:

Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
Example 3:

Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.


Constraints:

1 <= num.length <= 105
num only consists of digits and does not contain any leading zeros.

*/

// Runtime: 30 ms, faster than 80.66% of C++ online submissions for Largest Odd Number in String.
// Memory Usage: 15.4 MB, less than 13.58% of C++ online submissions for Largest Odd Number in String.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestOddNumber(string num)
    {

        // num only consists of digits and does not contain any leading zeros.
        // to insert a string from the back
        // s.insert(s.end(),1,'3');
        // to insert a string from the start
        // s.insert(s.begin(),1,'3');
        /*
        Algorithm

        1. Check the last digit first - if its odd - then return the whole      string directly without any further checking
        2. To check if a digit is odd or even - use this condition-
        {
        character- '0' %2 ==0
        3. If all the digits are even , there is no subsequence
        4.
        */

        int n = num.length();
        if ((num[n - 1] - '0') % 2 != 0)
            return num;

        string s = "";
        int i;
        for (i = n - 1; i >= 0; i--)
        {
            if ((num[i] - '0') % 2 != 0)
            {
                break;
            }
        }
        int idx = i;
        for (i = 0; i <= idx; i++)
            s.insert(s.end(), 1, num[i]);

        return s;
    }
};