/*
1736. Latest Time by Replacing Hidden Digits
Easy

https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/

You are given a string time in the form of hh:mm, where some of the digits in the string are hidden
(represented by ?).

The valid times are those inclusively between 00:00 and 23:59.

Return the latest valid time you can get from time by replacing the hidden digits.



Example 1:

Input: time = "2?:?0"
Output: "23:50"
Explanation: The latest hour beginning with the digit '2' is 23 and the latest minute
ending with the digit '0' is 50.

Example 2:

Input: time = "0?:3?"
Output: "09:39"
Example 3:

Input: time = "1?:22"
Output: "19:22"


Constraints:

time is in the format hh:mm.
It is guaranteed that you can produce a valid time from the given string.

*/

/*
Algorithm

1. The 0 th index can only have values- 0,1,2 - if 0th index has max 2
2. The 1st index can have values 0-9 - so 9 is the max value if 0 or 1 is there in 0th index - otherwise - 3.
3. The 3rd index can have value 0-5, so 5 is the max value
4. The 4th index can have value 0-9 , so 9 is the max value
*/

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    string maximumTime(string time)
    {

        if (time[0] == '?' && (time[1] <='3' || time[1]=='?'))
        {
            time[0] = '2'; // can have max of value 2
        }
        else  if (time[0]=='?' && time[1]>='4'){
            time[0]='1';
        }
        if ((time[0] == '0' || time[0] == '1') && time[1] == '?')
        {
            time[1]= '9';
        }
        if (time[0]=='2' && time[1]=='?'){
            time[1]= '3';
        }
        if (time[3] =='?'){
            time[3]= '5';
        }
        if (time[4]=='?'){

            time[4]='9';
        }
        return time;
    }
};
int main(int argc, char const *argv[])
{
    string s="0?:3?";
    s="?4:03";
    cout<<Solution().maximumTime(s);
    return 0;
}


// smaller solution


class Solution
{
public:
    string maximumTime(string time)
    {
        if (time[0] == '?') {
            time[0] = (time[1] == '?' || time[1] <= '3') ? '2' : '1';
        }
        if (time[1] == '?') {
            time[1] = (time[0] == '2') ? '3' : '9';
        }
        if (time[3] == '?') {
            time[3] = '5';
        }
        if (time[4] == '?') {
            time[4] = '9';
        }
        return time;
    }
};