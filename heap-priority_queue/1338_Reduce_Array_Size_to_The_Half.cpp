/*
1338. Reduce Array Size to The Half
Medium

https://leetcode.com/problems/reduce-array-size-to-the-half/

You are given an integer array arr. You can choose a set of integers and remove all the occurrences 
of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

 

Example 1:

Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.
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
Algorithm 

1. Create a map for frequency
2. Create a pq for it to be sorted by frequency
3. go on removing elements from the top and keep the track if 
the number of deleted elements have exceeded arr.size()/2 and also count for each element 
that we delete.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int len= arr.size()/2;
        map<int,int> f;
        for (int i=0;i<arr.size();i++){
            f[arr[i]]++;
        }
        priority_queue <pair<int,int>> p;
        for(auto i:f){
            p.push(make_pair(i.second,i.first));
        }

        int c=0;
        int del=0;
        while(!p.empty()){
            c=c+1;
            del+= p.top().first;
            p.pop();
            if(del>=len){
                break;
            }
        }
        return c;
    }
};
