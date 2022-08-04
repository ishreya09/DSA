/*
2160. Minimum Sum of Four Digit Number After Splitting Digits
Easy

https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/

You are given a positive integer num consisting of exactly four digits.
Split num into two new integers new1 and new2 by using the digits found in num.
Leading zeros are allowed in new1 and new2, and all the digits found in num must be used.

For example, given num = 2932, you have the following digits: two 2's, one 9 and one 3.
Some of the possible pairs [new1, new2] are [22, 93], [23, 92], [223, 9] and [2, 329].
Return the minimum possible sum of new1 and new2.



Example 1:

Input: num = 2932
Output: 52
Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.
Example 2:

Input: num = 4009
Output: 13
Explanation: Some possible pairs [new1, new2] are [0, 49], [490, 0], etc.
The minimum sum can be obtained by the pair [4, 9]: 4 + 9 = 13.


Constraints:

1000 <= num <= 9999
*/
       
        /*
        Algorithm

        1. Convert the digits into the array
        2. sort the array - accending order
        3. the first number will be given by - arr[0]*10+ arr[3]
        4. similarly the second number will be given by - arr[1]*10+ arr[2]
        5. return the sum
        */

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int minimumSum(int num)
    {

        vector<int> a(4);

        for (int i = 0; i < 4; i++)
        {
            a[i] = num % 10;
            num = num / 10;
        }

        sort(a.begin(), a.end());
        return (a[0] * 10 + a[3]) + (a[1] * 10 + a[2]);
    }
};