/*
2224. Minimum Number of Operations to Convert Time
Easy

https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/

You are given two strings current and correct representing two 24-hour times.

24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59.
The earliest 24-hour time is 00:00, and the latest is 23:59.

In one operation you can increase the time current by 1, 5, 15, or 60 minutes.
You can perform this operation any number of times.

Return the minimum number of operations needed to convert current to correct.



Example 1:

Input: current = "02:30", correct = "04:35"
Output: 3
Explanation:
We can convert current to correct in 3 operations as follows:
- Add 60 minutes to current. current becomes "03:30".
- Add 60 minutes to current. current becomes "04:30".
- Add 5 minutes to current. current becomes "04:35".
It can be proven that it is not possible to convert current to correct in fewer than 3 operations.
Example 2:

Input: current = "11:00", correct = "11:01"
Output: 1
Explanation: We only have to add one minute to current, so the minimum number of operations needed is 1.


Constraints:

current and correct are in the format "HH:MM"
current <= correct
*/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Number of Operations to Convert Time.
// Memory Usage: 6 MB, less than 12.62% of C++ online submissions for Minimum Number of Operations to Convert Time.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int convertTime(string current, string correct)
    {
        /*
        Algorithm
        1. In one operation you can increase the time current by 1, 5, 15, or 60 minutes.
        2. The first 2 digits can be written as - current[0]*10 + current[1]
        3. the minutes can be written as -current[3]*10 +current[4]
        4. Repeat same for correct var and take difference
        5. If current min is more than correct min - then take difference as (60 - m_cur)+ m_cor else  m_cor - m_cur
        6. Put the if statements in loop with relevant conditions

        */
        int h_cur =( current[0]-'0') * 10 + (current[1]-'0');
        int m_cur =( current[3]-'0') * 10 + (current[4]-'0');
        int h_cor =( correct[0]-'0') * 10 +( correct[1]-'0');
        int m_cor =( correct[3]-'0')* 10 + (correct[4]-'0');
        cout << h_cur<<m_cur<< "\t"<< h_cor<< m_cor<<endl;
        int diff;
        int c = 0;

        if (h_cor>=h_cur){
            c+= h_cor-h_cur;
            h_cur = h_cor-h_cur;
        }

        if (m_cur> m_cor){
            c--;
            // h_cur --; 
            diff= (60 - m_cur)+ m_cor;
        }
        else {
            diff = m_cor - m_cur;
        }

        while (diff !=0){
            if(diff>=15 &&  diff <60){
                c+= (diff/15);
                diff -= (diff/15)*15;
            }
            else if (diff >= 5){
                c+= diff/5;
                diff -= (diff/5)*5; 
            }
            else if(diff >=1){
                c+= diff;
                diff -= diff;                 
            }

        }
        return c;
    }
};


int main(){
    string s,s1;
    s="02:30";
    s1="04:35";
    cout<< Solution().convertTime(s,s1);
}