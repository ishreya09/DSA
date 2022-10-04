/*
1365. How Many Numbers Are Smaller Than the Current Number
Easy

https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. 
That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

 

Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
Example 2:

Input: nums = [6,5,4,8]
Output: [2,1,0,3]
Example 3:

Input: nums = [7,7,7,7]
Output: [0,0,0,0]
 

Constraints:

2 <= nums.length <= 500
0 <= nums[i] <= 100

*/

/*
Algorithm

1. Create a custom node structure so that values of the map is defaulted to -1 instead of zero
2. Sort and store in different array and start taking cumulative sums of the elements
3. Traverse through original array and use the map to get the numbers less than it.

*/

#include<bits/stdc++.h>
using namespace std;

// Structure Node
struct Node {
    int value = -1;
}; // to default the value of map to -1

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> n= nums;
        vector <int > ans;
        map<int,Node> f;
        int sum=0;
        sort(n.begin(),n.end());
        f[n[0]].value=0;
        for (int i=0; i<n.size();i++){
            if (f[n[i]].value==-1 && i!=0 )
                f[n[i]].value= sum;
            else if(f[n[i]].value!= -1 && f[n[i]].value==f[n[0]].value){
                f[n[i]].value=0;
            }
            sum++;
        }
        for (int i=0; i<nums.size();i++){
            ans.push_back(f[nums[i]].value);
        }
        return ans;
    }
};