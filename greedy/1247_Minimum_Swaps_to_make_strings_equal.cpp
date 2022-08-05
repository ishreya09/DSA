/*
1247. Minimum Swaps to Make Strings Equal
Medium

https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/

You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only. Your task is to make these two strings equal to each other. You can swap any two characters that belong to different strings, which means: swap s1[i] and s2[j].

Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.



Example 1:

Input: s1 = "xx", s2 = "yy"
Output: 1
Explanation: Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".
Example 2:

Input: s1 = "xy", s2 = "yx"
Output: 2
Explanation: Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
Note that you cannot swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.
Example 3:

Input: s1 = "xx", s2 = "xy"
Output: -1


Constraints:

1 <= s1.length, s2.length <= 1000
s1, s2 only contain 'x' or 'y'.

*/
/*
Algorithm -

(something related to Two pointers as well)

1. The strings can change every iteration and needs to be checked after every swapping -
also check for length of s1 and s2- if its not same - return -1
2. First, ignore all the already matched positions, they don't affect the answer at all.
2. If the two strings are not reverse or in general - take i as start and j from the end and then swap
3. If the two strings are exactly reversed, swap those positions taking i and j from start
4. If x and y is the character to swap and rest are in positions, then its not possible to make it same,
sO we return -1.

*/

// keep of hold 

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        if (s1.length() != s2.length())
        {
            return -1;
        }
        int swap = 0;
        string rev;

        while (s1 != s2)
        {
            rev = string(s1.rbegin(), s1.rend());
            if (s2 != rev)
            {
                for (int i = 0, j = s2.length() - 1; i < s1.length(); i++, j--)
                {
                    if (s1[i] != s2[j])
                    {
                        // swap
                        swap++;
                        char temp = s1[i];
                        s1[i] = s2[j];
                        s2[j] = temp;
                    }
                }
            }
            else if (s2 == rev)
            {
                for (int i = 0, j = 0; i < s1.length(); i++, j++)
                {
                    if (s1[i] != s2[j])
                    {
                        // swap
                        swap++;
                        char temp = s1[i];
                        s1[i] = s2[j];
                        s2[j] = temp;
                    }
                }
            }

            
        }

        return swap;
    }
};
