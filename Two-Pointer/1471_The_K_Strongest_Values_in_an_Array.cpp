/*
1471. The k Strongest Values in an Array
Medium

https://leetcode.com/problems/the-k-strongest-values-in-an-array/

Given an array of integers arr and an integer k.

A value arr[i] is said to be stronger than a value arr[j] if |arr[i] - m| > |arr[j] - m| where m is the median of the array.
If |arr[i] - m| == |arr[j] - m|, then arr[i] is said to be stronger than arr[j] if arr[i] > arr[j].

Return a list of the strongest k values in the array. return the answer in any arbitrary order.

Median is the middle value in an ordered integer list. More formally, if the length of the list is n, 
the median is the element in position ((n - 1) / 2) in the sorted list (0-indexed).

For arr = [6, -3, 7, 2, 11], n = 5 and the median is obtained by sorting the array arr = [-3, 2, 6, 7, 11] and 
the median is arr[m] where m = ((5 - 1) / 2) = 2. The median is 6.
For arr = [-7, 22, 17, 3], n = 4 and the median is obtained by sorting the array arr = [-7, 3, 17, 22] and the 
median is arr[m] where m = ((4 - 1) / 2) = 1. The median is 3.
 

Example 1:

Input: arr = [1,2,3,4,5], k = 2
Output: [5,1]
Explanation: Median is 3, the elements of the array sorted by the strongest are [5,1,4,2,3]. The strongest 2 
elements are [5, 1]. [1, 5] is also accepted answer.
Please note that although |5 - 3| == |1 - 3| but 5 is stronger than 1 because 5 > 1.
Example 2:

Input: arr = [1,1,3,5,5], k = 2
Output: [5,5]
Explanation: Median is 3, the elements of the array sorted by the strongest are [5,5,1,1,3]. The strongest 2 
elements are [5, 5].
Example 3:

Input: arr = [6,7,11,7,6,8], k = 5
Output: [11,8,6,6,7]
Explanation: Median is 7, the elements of the array sorted by the strongest are [11,8,6,6,7,7].
Any permutation of [11,8,6,6,7] is accepted.
 

Constraints:

1 <= arr.length <= 105
-105 <= arr[i] <= 105
1 <= k <= arr.length

*/

/*
Algorithm

1. Sort the array and find the median first
2. Take two pointers at start and end of array and check for the strongest number conditions.
3. At last check if i==j and k!=0 condition- append the ith element and return the array.

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        if(arr.size()<=1){
            return arr;
        }
        sort(arr.begin(),arr.end());
        int m= arr[(arr.size()-1)/2];
        int i=0;
        int j=arr.size()-1;
        vector<int> ans;
        while(i<j && k--){
            if(abs(arr[i]-m) > abs(arr[j]-m)){
                ans.push_back(arr[i]);
                i++;
            }
            else if(abs(arr[i]-m) < abs(arr[j]-m)){
                ans.push_back(arr[j]);
                j--;
            }
            else{
                if(arr[i]>=arr[j]){
                    ans.push_back(arr[i]);
                    i++;
                }
                else if (arr[i]<arr[j]){
                    ans.push_back(arr[j]);
                    j--;
                }
            }
        }
        if (i==j && k!=0){
            ans.push_back(arr[i]);
        }
        
        return ans;
    }
};