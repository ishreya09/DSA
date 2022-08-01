/*
942. DI String Match
Easy

https://leetcode.com/problems/di-string-match/

A permutation perm of n + 1 integers of all the integers in the range [0, n]
can be represented as a string s of length n where:

s[i] == 'I' if perm[i] < perm[i + 1], and
s[i] == 'D' if perm[i] > perm[i + 1].
Given a string s, reconstruct the permutation perm and return it. If there are multiple
valid permutations perm, return any of them.



Example 1:

Input: s = "IDID"
Output: [0,4,1,3,2]
Example 2:

Input: s = "III"
Output: [0,1,2,3]
Example 3:

Input: s = "DDI"
Output: [3,2,0,1]


Constraints:

1 <= s.length <= 105
s[i] is either 'I' or 'D'.

*/

// Runtime: 11 ms, faster than 35.06% of C++ online submissions for DI String Match.
// Memory Usage: 8.6 MB, less than 84.87% of C++ online submissions for DI String Match. 

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> diStringMatch(string s){
        /*
        Algorithm

        1. If string starts with I , we start the array with 0 and if it starts with D , then array starts with n
        where n is the length of the string
        2. If further I is encountered, we start incrementing by 1 from 0 (here i)
        3. If further D is encounted, we decrementing by 1 from n. (here n)
        4. When the last letter is left, both the count reaches to the same number.

        */
        int i, n, ind = 0;
        i = 0;
        n = s.length();
        vector<int> ans;
        while (i != n)
        {
            if (s[ind] == 'I')
            {
                ans.push_back(i);
                i++;
            }
            else
            {
                ans.push_back(n);
                n--;
            }
            ind++;
        }
        ans.push_back(n);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution b;
    string s = "IDI";
    vector<int> a = b.diStringMatch(s);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "\t";
    }
    cout << "\n";
    return 0;
}
