/*
1323. Maximum 69 Number
Easy

You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

 

Example 1:

Input: num = 9669
Output: 9969
Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.
Example 2:

Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.
Example 3:

Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.
 

Constraints:

1 <= num <= 104
num consists of only 6 and 9 digits.

*/

// Runtime: 7 ms, faster than 8.10% of C++ online submissions for Maximum 69 Number.
// Memory Usage: 5.9 MB, less than 50.40% of C++ online submissions for Maximum 69 Number.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        /*
        Algorithm
        
        The constraint only requires till 4 digits 
        
        1. Create a vector of digits of the number
        2. By using greedy, we can just change 6 to and compare
        3. Also changing the first 6 to encounter will give the maximum result.
        4. If all the numbers are 9, then no change

        
        More efficient way - 

        1. find the index of the first 6 appearing - i.e. the last 6 that will appear in the loop 
        2. add the number with 3 * pow(10,index) 
        (return num + 3 * pow(10, index) )
        */
        vector <int> a(4);
        int i=3;
        int n=num; // num
        while (n>0){
            a[i] = n%10;
            n = n/10;
            i--;
        }
        
        n=4; // len of array
        for (i=0;i<n;i++){
            if (a[i]==6){
                a[i]=9;
                break;
            }
        }
        n=0;
        // now recombine the array
        for (int i =0; i<4; i++){
            n= n*10 + a[i];
        }
        
        return n;
    }
};

/*


*/