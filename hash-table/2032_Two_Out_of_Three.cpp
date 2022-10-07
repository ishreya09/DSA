/*
2032. Two Out of Three
Easy

https://leetcode.com/problems/two-out-of-three/

Given three integer arrays nums1, nums2, and nums3, return a distinct array containing all the values that 
are present in at least two out of the three arrays. You may return the values in any order.
 

Example 1:

Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
Output: [3,2]
Explanation: The values that are present in at least two arrays are:
- 3, in all three arrays.
- 2, in nums1 and nums2.
Example 2:

Input: nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
Output: [2,3,1]
Explanation: The values that are present in at least two arrays are:
- 2, in nums2 and nums3.
- 3, in nums1 and nums2.
- 1, in nums1 and nums3.
Example 3:

Input: nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
Output: []
Explanation: No value is present in at least two arrays.
 

Constraints:

1 <= nums1.length, nums2.length, nums3.length <= 100
1 <= nums1[i], nums2[j], nums3[k] <= 100

*/

/*
Algorithm

1. Make a map for frequency and push back the intersection values into ans.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<int> intersect (map<int,int> f1, map<int,int> f2, set<int> &ans){
        auto it1= f1.begin();
        auto it2=f2.begin();
        while(it1!=f1.end() && it2!=f2.end()){
            if(it1->first==it2->first){
                ans.insert(it1->first);
                it1++;
                it2++;
            }
            else if(it1->first>it2->first){
                it2++;
            }
            else{
                it1++;
            }
        }
        return ans;
    }
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        map<int,int> f1;
        map<int,int> f2;
        map<int,int> f3;
        for(int i=0; i<nums1.size();i++){
            f1[nums1[i]]++;
        }
        for(int i=0; i<nums2.size();i++){
            f2[nums2[i]]++;
        }
        for(int i=0; i<nums3.size();i++){
            f3[nums3[i]]++;
        }
        set<int> a;
        a=intersect (f1,f2,a);
        a= intersect (f2,f3,a);
        a= intersect (f3,f1,a);
        
        vector<int> ans(a.begin(),a.end());
        
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
//         map<int,int> f1;
//         map<int,int> f2;
//         map<int,int> f3;
//         for(int i=0; i<nums1.size();i++){
//             f1[nums1[i]]++;
//         }
//         for(int i=0; i<nums2.size();i++){
//             f2[nums2[i]]++;
//         }
//         for(int i=0; i<nums3.size();i++){
//             f3[nums3[i]]++;
//         }
//         set<int> ans;
       
//         auto it1= f1.begin();
//         auto it2=f2.begin();
//         while(it1!=f1.end() && it2!=f2.end()){
//             if(it1->first==it2->first){
//                 ans.insert(it1->first);
//                 it1++;
//                 it2++;
//             }
//             else if(it1->first>it2->first){
//                 it2++;
//             }
//             else{
//                 it1++;
//             }
//         }
//         it1= f1.begin();
//         it2=f3.begin();
//         while(it1!=f1.end() && it2!=f3.end()){
//             if(it1->first==it2->first){
//                 ans.insert(it1->first);
//                 it1++;
//                 it2++;
//             }
//             else if(it1->first>it2->first){
//                 it2++;
//             }
//             else{
//                 it1++;
//             }
//         }
//         it1= f2.begin();
//         it2=f3.begin();
//         while(it1!=f2.end() && it2!=f3.end()){
//             if(it1->first==it2->first){
//                 ans.insert(it1->first);
//                 it1++;
//                 it2++;
//             }
//             else if(it1->first>it2->first){
//                 it2++;
//             }
//             else{
//                 it1++;
//             }
//         }
//         vector<int> a(ans.begin(),ans.end());
        
//         return a;
//     }
// };