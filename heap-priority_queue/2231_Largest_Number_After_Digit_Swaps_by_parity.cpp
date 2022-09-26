/*
2231. Largest Number After Digit Swaps by Parity
Easy

https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/

You are given a positive integer num. You may swap any two digits of num that have the same parity 
(i.e. both odd digits or both even digits).

Return the largest possible value of num after any number of swaps.

 

Example 1:

Input: num = 1234
Output: 3412
Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
Swap the digit 2 with the digit 4, this results in the number 3412.
Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.
Example 2:

Input: num = 65875
Output: 87655
Explanation: Swap the digit 8 with the digit 6, this results in the number 85675.
Swap the first digit 5 with the digit 7, this results in the number 87655.
Note that there may be other sequences of swaps but it can be shown that 87655 is the largest possible number.
 

Constraints:

1 <= num <= 109
*/

/*
Algorithm 

1. Store the number in an array and push them into two different pq of odd and even.
2. Reverese the array of numbers and then check if the position is having odd or even number
3. Pop the element from the odd pq if num is odd and even pq if num is even and append to the integer

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        
        
        vector<int> number;
        while(num!=0){
            number.push_back(num%10);
            num=num/10;
        }
        
        reverse(number.begin(),number.end());
        
        
        priority_queue<int> odd;
        priority_queue<int> even;
        
        for(int i=0;i<number.size();i++){
           if(number[i]%2==0) 
                even.push(number[i]);
            else 
                odd.push(number[i]);
        }
        
        
        int result=0;
        
        for(int i=0;i<number.size();i++){
            result=result*10;
            if(number[i]%2==0){
                result+=even.top();
                even.pop();
            }
            else{
                result+=odd.top();
                odd.pop();
            }
        }
        
        
        return result;
        
    }
};