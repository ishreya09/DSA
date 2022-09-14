/*
1054. Distant Barcodes
Medium

https://leetcode.com/problems/distant-barcodes/

In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].

Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, 
and it is guaranteed an answer exists.

 

Example 1:

Input: barcodes = [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]
Example 2:

Input: barcodes = [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,1,2,1,2]
 

Constraints:

1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000
*/

/*
Algorithm 

1. Make a map for frequency of all the elements of array barcodes
2. Make a priority queue and make the first element as the frequency
so that elements get sorted by frequency
3. To make the vector alternatively, store the prev item that's poped in block and add one character of it into
the new vector and decrease its frequency. Store this in block and initialize another iterator to p.top()
and add one element from there and pop it from there.
4. if (block.first>0 )- means frequency of previous character which was popped earlier 
is still there and so we push it back
in the priority queue and store the current iterator in the block.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int,int> a;
        for (int i=0;i<barcodes.size();i++){
            a[barcodes[i]]++;
        }
        priority_queue<pair<int,int>> p;
        for (auto i=a.begin();i!=a.end();i++){
            p.push(make_pair(i->second,i->first));
        }
        vector<int> ans;
        auto it=p.top();
        p.pop();
        ans.push_back(it.second);
        it.first--;
        auto block= it;
        while(!p.empty()){
            it=p.top();
            p.pop();
            ans.push_back(it.second);
            it.first--;
            if (block.first>0){
                p.push(block);
            }
            block=it;
        }
        return ans;
    }
};