/*
1963. Minimum Number of Swaps to Make the String Balanced
Medium

You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 
opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:

It is the empty string, or
It can be written as AB, where both A and B are balanced strings, or
It can be written as [C], where C is a balanced string.
You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make s balanced.

 

Example 1:

Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".
Example 2:

Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".
Example 3:

Input: s = "[]"
Output: 0
Explanation: The string is already balanced.
 

Constraints:

n == s.length
2 <= n <= 106
n is even.
s[i] is either '[' or ']'.
The number of opening brackets '[' equals n / 2, and the number of closing brackets ']' equals n / 2.

*/

/*
Algorithm

1. Iterate over the string and keep track of the number of opening and closing brackets on each step.
2. If the number of closing brackets is ever larger, you need to make a swap.
3. Swap it with the opening bracket closest to the end of s.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int n= s.size();
        int balance=0,swaps=0,j=n-1;
        for (int i=0; i<n;i++){
            if(s[i]=='['){
                balance++;
            }else{
                balance--;
            }
            if (balance<0){
                while(i<j && s[j]!='['){
                    j--;
                }
                swap(s[i],s[j]);
                swaps++;
                balance=1;
            }
        }
        return swaps;
    }
};