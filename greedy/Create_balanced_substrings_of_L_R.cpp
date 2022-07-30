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

        /*
        Algorithm

        Using Greedy Algorithm
        Greedy means that u have to grab it at that instant without thinking of other outcomes

        1. Keep a count of R and L appearing in the string
        2. Whenever the count of R and L is going to be same, we can count that as one substring in this ques
        3. After counting the substring, we make the count for R and L character to 0 for another substring 
        4. And repeat the above process until we traverse through the string.

        */

        int r = 0, l = 0; // to count the number of R and L in the substring
        int count = 0;    // for number of substrings
        int i = 0;        // for index

   

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