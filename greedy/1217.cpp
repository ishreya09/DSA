/*
1217. Minimum Cost to Move Chips to The Same Position

We have n chips, where the position of the ith chip is position[i].

We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:

position[i] + 2 or position[i] - 2 with cost = 0.
position[i] + 1 or position[i] - 1 with cost = 1.
Return the minimum cost needed to move all the chips to the same position.

 

Example 1:


Input: position = [1,2,3]
Output: 1
Explanation: First step: Move the chip at position 3 to position 1 with cost = 0.
Second step: Move the chip at position 2 to position 1 with cost = 1.
Total cost is 1.
Example 2:


Input: position = [2,2,2,3,3]
Output: 2
Explanation: We can move the two chips at position  3 to position 2. Each move has cost = 1. The total cost = 2.
Example 3:

Input: position = [1,1000000000]
Output: 1

Constraints:

1 <= position.length <= 100
1 <= position[i] <= 10^9
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        // find the maximum number of frequency of a pos 
        // use a map 
        // then transfer all the rest chips to one position-meaning 
        // in case of same frequency of all 
        // check for the pos with minimum cost and swaps
        
        int cost =0; // cost to move the chips
        // creating a map to store the frequency
        map<int,int> frequency;

        // stl library functions uses quick sort 

        for (int i=0; i<position.size(); i++){
            frequency[position[i]]++;
        }
        
        // for finding the maximum
        int num= frequency.begin()->first;
        int max= frequency.begin()->second;
        // We write ++frequency.begin() as the first map member is already defined by max and num
        // since an iterator is returned pointing to the first pointer, we increment the pointer before hand itself in initialization
        for (auto i = ++frequency.begin(); i!= frequency.end(); i++){
            
        }
        
        
    }
};
