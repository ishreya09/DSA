/*
1122. Relative Sort Array
Easy

https://leetcode.com/problems/relative-sort-array/

Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. 
Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

 

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
Example 2:

Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]
 

Constraints:

1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
All the elements of arr2 are distinct.
Each arr2[i] is in arr1.

*/

/*
Algorithm

1. Count the frequency of all elements in a map
2. Traverse through arr2 and get all the numbers which are in order of num2 and erase them from map as well
3. For the rest of the elements in map, traverse through the map and push back the values 

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> f; // freq for arr1
        for(int i=0; i<arr1.size();i++){
            f[arr1[i]]++;
        }
        vector<int >ans;
        for(int i=0; i<arr2.size();i++){
            cout<<arr2[i]<<"\t"<< f[arr2[i]]<<endl;
            while(f[arr2[i]]--){
                ans.push_back(arr2[i]);
            }
            f.erase(arr2[i]);
        }
        
        for(auto i=f.begin();i!=f.end();i++ ){
            while (i->second--){
                ans.push_back(i->first);
            }
        }
        
        return ans;
    }
};