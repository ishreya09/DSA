/*
2396. Strictly Palindromic Number
Medium

https://leetcode.com/problems/strictly-palindromic-number/

An integer n is strictly palindromic if, for every base b between 2 and n - 2 (inclusive), 
the string representation of the integer n in base b is palindromic.

Given an integer n, return true if n is strictly palindromic and false otherwise.

A string is palindromic if it reads the same forward and backward.

 

Example 1:

Input: n = 9
Output: false
Explanation: In base 2: 9 = 1001 (base 2), which is palindromic.
In base 3: 9 = 100 (base 3), which is not palindromic.
Therefore, 9 is not strictly palindromic so we return false.
Note that in bases 4, 5, 6, and 7, n = 9 is also not palindromic.
Example 2:

Input: n = 4
Output: false
Explanation: We only consider base 2: 4 = 100 (base 2), which is not palindromic.
Therefore, we return false.

 

Constraints:

4 <= n <= 105

*/

/*
Algorithm

If the number is palindromic in all bases from 2 to n-2, it will be strictly palindromic. 
Conversely, if it is not palindromic in even in one of the bases we have to return false. 
Let us consider n-2 base for all the numbers.

Evidently, any number when converted to their n-2 base will return 12 which is non palindromic 
and hence establishes the number as not strictly palindromic. The exeption is the number 4, 
which when converted to it's n-2 base, i.e. base 2 does not return 12 instead returns 100 which 
again is non palindromic and therefore concludes that not a single number eligible for input is 
strictly palindromic. Thus return false.


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        return false;
    }
};