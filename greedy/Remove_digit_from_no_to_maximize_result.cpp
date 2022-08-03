/*
2259. Remove Digit From Number to Maximize Result
Easy

https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/submissions/

You are given a string number representing a positive integer and a character digit.

Return the resulting string after removing exactly one occurrence of digit from number such
that the value of the resulting string in decimal form is maximized. The test cases are
generated such that digit occurs at least once in number.



Example 1:

Input: number = "123", digit = "3"
Output: "12"
Explanation: There is only one '3' in "123". After removing '3', the result is "12".
Example 2:

Input: number = "1231", digit = "1"
Output: "231"
Explanation: We can remove the first '1' to get "231" or remove the second '1' to get "123".
Since 231 > 123, we return "231".
Example 3:

Input: number = "551", digit = "5"
Output: "51"
Explanation: We can remove either the first or second '5' from "551".
Both result in the string "51".


Constraints:

2 <= number.length <= 100
number consists of digits from '1' to '9'.
digit is a digit from '1' to '9'.
digit occurs at least once in number.
*/

#include <bits/stdc++.h>
using namespace std;

// Runtime: 15 ms, faster than 5.53% of C++ online submissions for Remove Digit From Number to Maximize Result.
// Memory Usage: 7.8 MB, less than 5.62% of C++ online submissions for Remove Digit From Number to Maximize Result.

class Solution
{
public:
    string static compare(string a, string b)
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] > b[i])
            {
                return a;
            }
            if (a[i] < b[i])
            {
                return b;
            }
        }
        return b;
    }

    string removeDigit(string number, char digit)
    {
        /*
        Algorithm

        1. Go on removing each occurance of the required digit from the number
        2. Check and compare and store in max
        3. Compare will be a function which compares ascii of 2 strings
        4. To avoid error, iniialize num1 and max to "0"
        */
        string num1 = "0", max = "0";

        for (int i = 0; i < number.length(); i++)
        {

            if (number[i] == digit)
            {
                // cout << number.substr(0, i) << "\t" << number.substr(i + 1, number.length()) << endl;
                num1 = number.substr(0, i) + number.substr(i + 1, number.length());
                cout << num1 << "\t" << max << endl;
                max = compare(num1, max);
                cout << num1 << "\t" << max << endl;
            }
        }

        cout << num1 << "\t" << max << endl;

        return max;
    }
};

int main(int argc, char const *argv[])
{
    string s = "73197";
    char d = '7';
    cout << Solution().removeDigit(s, d);
    return 0;
}
