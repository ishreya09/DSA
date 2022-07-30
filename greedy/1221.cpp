/*
Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

Given a balanced string s, split it into some number of substrings such that:

Each substring is balanced.
Return the maximum number of balanced strings you can obtain.

Example 1:

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
Example 2:

Input: s = "RLRRRLLRLL"
Output: 2
Explanation: s can be split into "RL", "RRRLLRLL", each substring contains same number of 'L' and 'R'.
Note that s cannot be split into "RL", "RR", "RL", "LR", "LL", because the 2nd and 5th substrings are not balanced.
Example 3:

Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".


Constraints:

2 <= s.length <= 1000
s[i] is either 'L' or 'R'.
s is a balanced string.

*/

// correct code

// Runtime  Memory
//	7 ms	6.2 MB

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int balancedStringSplit(string s)
    {

        int r = 0, l = 0; // to count the number of R and L in the substring
        int count = 0;    // for number of substrings
        int i = 0;        // for index

        // now we need to check the string using greedy algorithm
        // while we go from letter by letter - we need to check if there is equal number of
        // R and L in the substring and then count it

        // Greedy means that u have to grab it at that instant without thinking of other outcomes
        while (s[i] != 0) //  s[i] ! = Null Character
                          // Null character have ASCII 0
        {
            if (s[i] == 'R')
            {
                r++;
            }
            else if (s[i] == 'L')
            {
                l++;
            }
            if (r == l && r != 0 && l != 0)
            {
                count++; // incrementing the count as we found a substring
                l = 0;   // resetting the value of L and R to zero to check for further
                r = 0;
            }
            i++; // incrementing i for index
        }
        return count;
    }
};

int main()
{

    Solution a;
    int k = a.balancedStringSplit("RLRRLLRLRL"); // expected 4
    cout << k << endl;
    k = a.balancedStringSplit("RLRRRLLRLL"); // expected 2
    cout << k << endl;
    k = a.balancedStringSplit("LLLLRRRR"); // expected 1
    cout << k << endl;

    return 0;
}