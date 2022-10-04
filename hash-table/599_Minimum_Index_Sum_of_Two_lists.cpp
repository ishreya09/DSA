/*
599. Minimum Index Sum of Two Lists
Easy

https://leetcode.com/problems/minimum-index-sum-of-two-lists/

Given two arrays of strings list1 and list2, find the common strings with the least index sum.

A common string is a string that appeared in both list1 and list2.

A common string with the least index sum is a common string such that if it appeared at list1[i] and list2[j] 
then i + j should be the minimum value among all the other common strings.

Return all the common strings with the least index sum. Return the answer in any order.

 

Example 1:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines",
"Hungry Hunter Steakhouse","Shogun"]
Output: ["Shogun"]
Explanation: The only common string is "Shogun".
Example 2:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
Output: ["Shogun"]
Explanation: The common string with the least index sum is "Shogun" with index sum = (0 + 1) = 1.
Example 3:

Input: list1 = ["happy","sad","good"], list2 = ["sad","happy","good"]
Output: ["sad","happy"]
Explanation: There are three common strings:
"happy" with index sum = (0 + 1) = 1.
"sad" with index sum = (1 + 0) = 1.
"good" with index sum = (2 + 2) = 4.
The strings with the least index sum are "sad" and "happy".
 

Constraints:

1 <= list1.length, list2.length <= 1000
1 <= list1[i].length, list2[i].length <= 30
list1[i] and list2[i] consist of spaces ' ' and English letters.
All the strings of list1 are unique.
All the strings of list2 are unique.
*/

/*
Algorithm

1. Make a struct to intialize index as -1 and use it in the map - l1 and l2.
2. Use it to find min difference.
3.

*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int index=-1;
};

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int diff = list1.size()+list2.size()-2;
        map<string,Node> l1;
        map<string,Node> l2;
        vector<string> ans;
        for (int i=0; i<max<int>(list1.size(),list2.size());i++){
            if (i<list1.size()){
                l1[list1[i]].index=i;
                int k = l2[list1[i]].index;
                if(k!=-1 && k+i<diff){
                    diff=k+i; 
                }
            }
            if (i<list2.size()){
                l2[list2[i]].index=i;
                int k = l1[list2[i]].index;
                if(k!=-1 && k+i<diff){
                    diff=k+i;
                }
            }
        }
        for (int i=0; i<list1.size();i++){
            if (diff-i<list2.size() && list1[i] == list2[diff-i]){
                ans.push_back(list1[i]);
            }
        }
        return ans;
    }
};