/*
860. Lemonade Change
Easy

At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you
and order one at a time (in the order specified by bills). Each customer will only buy one lemonade
and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer
so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you
can provide every customer with the correct change, or false otherwise.



Example 1:

Input: bills = [5,5,5,10,20]
Output: true
Explanation:
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.
Example 2:

Input: bills = [5,5,10,10,20]
Output: false
Explanation:
From the first two customers in order, we collect two $5 bills.
For the next two customers in order, we collect a $10 bill and give back a $5 bill.
For the last customer, we can not give the change of $15 back because we only have two $10 bills.
Since not every customer received the correct change, the answer is false.


Constraints:

1 <= bills.length <= 105
bills[i] is either 5, 10, or 20.
*/

// Runtime: 271 ms, faster than 5.12% of C++ online submissions for Lemonade Change.
// Memory Usage: 83.5 MB, less than 6.76% of C++ online submissions for Lemonade Change.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        /*
        Algorithm
        1. get the frequency of 20,10 and 5 dollar bills using map and check simentaneously using if else ladder
        2. For each 20 dollar bill, we need either 3 five dollars or 1 five and 1 ten
        3. For each 10 dollar bill, we need 1 five dollar bill
        4. Adjust the frequencies to check if the change is ample or not
        */

        //    int cost=0;
        bool change = true;
        map<int, int> f;
        for (int i = 0; i < bills.size(); i++)
        {
            // cost +=5;
            f[bills[i]]++;

            if (bills[i]==20){
                // for 20 $
                if (f[10]>=1 && f[5]>=1){
                    f[10] --; // one 5 and one 10
                    f[5]--;
                }
                else if (f[5]>= 3) {
                    f[5] -= 3;
                }
                else{
                    change= false;
                }

            }
            else if (bills[i]==10){

                // for 10 dollar
                if (f[5] >=1){
                    f[5] --;
                }
                else
                    change=false;
            }

            

        }

        return change;
        
    }
};
