/*
2566. Maximum Difference by Remapping a Digit
Easy

https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/

You are given an integer num. You know that Danny Mittal will sneakily remap one of the 10 possible digits (0 to 9) 
to another digit.

Return the difference between the maximum and minimum values Danny can make by remapping exactly one digit in num.

Notes:

When Danny remaps a digit d1 to another digit d2, Danny replaces all occurrences of d1 in num with d2.
Danny can remap a digit to itself, in which case num does not change.
Danny can remap different digits for obtaining minimum and maximum values respectively.
The resulting number after remapping can contain leading zeroes.
We mentioned "Danny Mittal" to congratulate him on being in the top 10 in Weekly Contest 326.
 

Example 1:

Input: num = 11891
Output: 99009
Explanation: 
To achieve the maximum value, Danny can remap the digit 1 to the digit 9 to yield 99899.
To achieve the minimum value, Danny can remap the digit 1 to the digit 0, yielding 890.
The difference between these two numbers is 99009.
Example 2:

Input: num = 90
Output: 99
Explanation:
The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the 
minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
Thus, we return 99.
 

Constraints:

1 <= num <= 108


*/

/*
Algorithm

1. Select the first non zero element and make it nine for maximum element
2. Select the first non nine element and make it zero for minimum element. If 9 comes in start - make 9 to 0
3. Return the difference

*/

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int convertMax(int n){
        string s= to_string(n);
        int i=0;
        while(s[i]=='9'){
            i++;
        }
        char p=s[i];
        for(i=0;i<s.length();i++){
            if(s[i]==p){
                s[i]='9';
            }
        }
        return stoi(s);
    }
    int convertMin(int n){
        string s= to_string(n);
        int i=0;
        while(s[i]=='9'){
            i++;
        }
        if(s[0]=='9'){
            i=0;
        }
        char p=s[i];
        for(i=0;i<s.length();i++){
            if(s[i]==p){
                s[i]='0';
            }
        }
        return stoi(s);
    }
    int minMaxDifference(int num) {
        int maximum= convertMax(num);
        int minimum=convertMin(num);
        return maximum-minimum;
    }
};