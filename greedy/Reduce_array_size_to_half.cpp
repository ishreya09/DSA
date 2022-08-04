/*
1338. Reduce Array Size to The Half
Medium

https://leetcode.com/problems/reduce-array-size-to-the-half/

You are given an integer array arr. You can choose a set of integers and remove all the 
occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

 

Example 1:

Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half 
of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater 
than half of the size of the old array.
Example 2:

Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.
 

Constraints:

2 <= arr.length <= 105
arr.length is even.
1 <= arr[i] <= 105
*/



/*
        for (auto& it : arr){
            f[it]++;
        }

        The syntax with : it's a range based for. It means that loop will parse
        each element inside threads vector. Inside the for, you need to specify
        the alias auto& in order to avoid creating a copy of the elements inside the 
        vector within the thread variable.
*/


/*
Algorithm 

1. Use map to count frequency and sort the map.
// to sort the map
2. Make a vector of pair<int,int> type and add map elements into the vector and then sort the vector in 
decending order in comparision with the pair's second value. This is one of the method to sort a map
3. Now go on removing the values in the sorted vector made above - and go on counting
4. Once the count reaches less than arr.size()/2 - stop removing.

// The other method of sorting map is using sets
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool static cmp(pair<int, int>& a,pair<int, int>& b){
        return a.second>b.second;
    }
    int minSetSize(vector<int>& arr) {
        vector<pair <int,int>> freq;
        map <int,int> f;

        for (auto& it : arr){
            f[it]++;
        }

        for (auto& it : f){ // how is it working?
            freq.push_back(it);
        }
        sort (freq.begin(),freq.end(),cmp);

        int c=0;
        int del=0; // no. of deleted elements
        for (auto&it : freq){
            c=c+1;
            del += it.second;
            cout<< it.first<<"\n";
            if (del >= arr.size()/2){
                break;
            }
        }

        return c;

    }
};