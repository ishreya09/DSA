/*
481. Magical String
Easy

https://leetcode.com/problems/magical-string/

A magical string s consists of only '1' and '2' and obeys the following rules:

The string s is magical because concatenating the number of contiguous occurrences of characters '1' and '2' generates 
the string s itself.
The first few elements of s is s = "1221121221221121122……". If we group the consecutive 1's and 2's in s, it will be 
"1 22 11 2 1 22 1 22 11 2 11 22 ......" and the occurrences of 1's or 2's in each group are "1 2 2 1 1 2 1 2 2 1 2 2 ......".
You can see that the occurrence sequence is s itself.

Given an integer n, return the number of 1's in the first n number in the magical string s.

 

Example 1:

Input: n = 6
Output: 3
Explanation: The first 6 elements of magical string s is "122112" and it contains three 1's, so return 3.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 105

*/

/*
Algorithm

1. start with 1,2,2 in your series. Keep the start pointer at 2 and end pointer at 2 as well.
for a 2, add 2 values alternating the value which is present at the end pointer. 
(End pointer is always at the end and used to check which number should be inserted)
2. (Start pointer traverses the growing array and if it is 1, we append 1 element at the end, otherwise 2)
3. The condition repeats process 1 and 2 until we reach the desired length of the array.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        if (n==1 || n==2 || n==3){
            return 1;
        }
        vector<char> num={1,2,2};
        int start = 2;
        int end=2;
        int s=3; // size
        int count=1;
        while(s<n){
            if (num[start]==1){
                if (num[end]==1){
                    num.push_back(2);
                }                
                else{
                    num.push_back(1);
                    count++;
                }
                end++;
            }
            else if (num[start]==2){
                if (num[end]==1){
                    num.push_back(2);
                    num.push_back(2);
                }                
                else{
                    num.push_back(1);
                    num.push_back(1);
                    count +=2;
                }
                end+=2;   
            }
            start++;
            s= num.size();
        }
        if(s-n>0){
            int diff= s-n;
            while(diff--){
                if (num[end]==1){
                    count--;
                }
                end--;
            }
        }
        return count;
    }
};

