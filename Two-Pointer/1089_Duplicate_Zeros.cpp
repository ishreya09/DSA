/*
1089. Duplicate Zeros
Easy

https://leetcode.com/problems/duplicate-zeros/

Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written. Do the above 
modifications to the input array in place and do not return anything.

 

Example 1:

Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 9

*/

/*
Algorithm

1. traverse through the array and insert in the vector using vector.insert() function.
2. Resize the array to the previous size of the array

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        while(i<arr.size()){
            if (arr[i]==0){
                arr.insert(arr.begin()+i+1,1,0);
                i+=2;
            }
            else{
                i++;
            }
        }
        arr.resize(n);
    }
};