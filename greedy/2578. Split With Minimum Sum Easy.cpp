/*
2578. Split With Minimum Sum
Easy

https://leetcode.com/problems/split-with-minimum-sum/description/

Given a positive integer num, split it into two non-negative integers num1 and num2 such that:

The concatenation of num1 and num2 is a permutation of num.
In other words, the sum of the number of occurrences of each digit in num1 and num2 is equal to the 
number of occurrences of that digit in num.
num1 and num2 can contain leading zeros.
Return the minimum possible sum of num1 and num2.

Notes:

It is guaranteed that num does not contain any leading zeros.
The order of occurrence of the digits in num1 and num2 may differ from the order of occurrence of num.
 

Example 1:

Input: num = 4325
Output: 59
Explanation: We can split 4325 so that num1 is 24 and num2 is 35, giving a sum of 59. We can prove 
that 59 is indeed the minimal possible sum.
Example 2:

Input: num = 687
Output: 75
Explanation: We can split 687 so that num1 is 68 and num2 is 7, which would give an optimal sum of 75.
 

Constraints:

10 <= num <= 109


*/

/*
Algorithm

1. Convert to string and sort it in acending order
2. Select the numbers in alternatingly for num1 and num2
3. Return the sum of 2 numbers.

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int splitNum(int num) {
        string s=to_string(num); // sort the num
        sort(s.begin(),s.end());
        if(s.length()==2){
            return stoi(s.substr(0,1))+stoi(s.substr(1));
        }
        int n= s.length();
        int i=0;
        int j=1;
        string num1,num2;
        while(i<s.length() && j<s.length()){
            num1+=s[i];
            num2+= s[j];
            i+=2;
            j+=2;
        }
        if(i<s.length()){ // select num alternatingly
            num1+=s[i];
        }
        if(j<s.length()){
            num2+=s[j];
        }
        // cout<<num1<<" "<<num2<<endl;
        int sum= stoi(num1)+stoi(num2);
        return sum;
    }
};