/*
2215. Find the Difference of Two arrays
Easy

https://leetcode.com/problems/find-the-difference-of-two-arrays/

Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.

 

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
Example 2:

Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000

*/

/*
Algorithm

1. Keep the frequency counts of both the array
2. Now iterate over the maps and check if both are equal- if equal increment both, otherwise check which is smaller 
and if the value exists in another list. Check the same for larger value as well and increment if true
3. At the end, check if any one of the map which has not reached its end- go on pushing values into the repective array.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> n1;
        map<int,int> n2;
        for (int i=0; i<nums1.size();i++){
            n1[nums1[i]]++;
        }
        for (int i=0; i<nums2.size();i++){
            n2[nums2[i]]++;
        }
        
        vector<vector<int>> ans(2);
        
        auto i1= n1.begin();
        auto i2= n2.begin();
        while(i1!=n1.end() && i2!= n2.end()){
            if (i1->first == i2->first){
                cout<<"Equal : "<< i1->first<<"\t"<< i2->first<<"\t"<<n2[i1->first]<<"\t"<<n1[i2->first]<<endl;
                i1++;
                i2++; // skip
            }
            else if(i1->first != i2->first){
                cout<<"NotEq : "<< i1->first<<"\t"<< i2->first<<"\t"<<i1->second<<"\t"<<i2->second<<"\t"<<n2[i1->first]<<"\t"<<n1[i2->first]<<endl;
                if (i1->first<i2->first){
                    if (i1->second>0 && n2[i1->first]==0){
                        ans[0].push_back(i1->first);
                    }
                    if (i2->second>0 && n1[i2->first]==0){
                        ans[1].push_back(i2->first);
                        i2++;
                    }
                    i1++;
                }
                else if(i1->first>i2->first){
                    if (i1->second>0 && n2[i1->first]==0){
                        ans[0].push_back(i1->first);
                        i1++;
                    }
                    if (i2->second>0 && n1[i2->first]==0){
                        ans[1].push_back(i2->first);
                    }
                    i2++;
                }
            }
        }
        while (i1!= n1.end()){
            if(i1->second>0){
                ans[0].push_back(i1->first);
            }
            i1++;
        }
        while (i2!= n2.end()){
            if(i2->second>0){
                ans[1].push_back(i2->first);
            }
            i2++;
        }
        return ans;
    }
};