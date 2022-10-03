/*
1942. The Number of the Smallest Unoccupied Chair
Medium 

https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/

There is a party where n friends numbered from 0 to n - 1 are attending. There is an infinite number of 
chairs in this party that are numbered from 0 to infinity. When a friend arrives at the party, they sit 
on the unoccupied chair with the smallest number.

For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend 
arrives at that same moment, they can sit in that chair.

You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], indicating the arrival 
and leaving times of the ith friend respectively, and an integer targetFriend. All arrival times are distinct.

Return the chair number that the friend numbered targetFriend will sit on.

 

Example 1:

Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
Output: 1
Explanation: 
- Friend 0 arrives at time 1 and sits on chair 0.
- Friend 1 arrives at time 2 and sits on chair 1.
- Friend 1 leaves at time 3 and chair 1 becomes empty.
- Friend 0 leaves at time 4 and chair 0 becomes empty.
- Friend 2 arrives at time 4 and sits on chair 0.
Since friend 1 sat on chair 1, we return 1.
Example 2:

Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
Output: 2
Explanation: 
- Friend 1 arrives at time 1 and sits on chair 0.
- Friend 2 arrives at time 2 and sits on chair 1.
- Friend 0 arrives at time 3 and sits on chair 2.
- Friend 1 leaves at time 5 and chair 0 becomes empty.
- Friend 2 leaves at time 6 and chair 1 becomes empty.
- Friend 0 leaves at time 10 and chair 2 becomes empty.
Since friend 0 sat on chair 2, we return 2.
 

Constraints:

n == times.length
2 <= n <= 104
times[i].length == 2
1 <= arrivali < leavingi <= 105
0 <= targetFriend <= n - 1
Each arrivali time is distinct.
*/

/*
Algorithm 

1.  Ordered set is the best way to store the chair number of empty chairs.
Store all the values in the set from 0 to tasks.size()-1 (chair numbers)
We get the first element of set as minimum value of empty chair directly 
2. We append the real index of the original list and sort wrt to start time.
3. We traverse through the times vector and append the chair number and push the end time and current index of the 
element in a priority queue p.
4. We also keep a check if p is not empty and the top time is less than or equal to current friend's arrival time
we make that friend go, push the chair no value back into the set and then pop the element from the pq. 

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // ordered set is the best method for the chair no.
        // priority queue for the the leaving time and current index of the element
        // we push current ind and chair no to the times vector
        
        set<int> k;
        for (int i=0; i<times.size();i++){
            times[i].push_back(i); // pushing the index
            k.insert(i);
        }
        sort (times.begin(),times.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > p;
        for (int i =0; i<times.size();i++){
            int tme=times[i][0]; //current time
            if(!p.empty()){
                while (!p.empty() && p.top().first <= tme ){
                    k.insert(times[p.top().second][3]); // k is pushed as 4th ele in the vector  
                    p.pop();
                }
            }
            int min = *k.begin();
            k.erase (min);
            times[i].push_back(min);
            p.push(make_pair(times[i][1],i));
            if (targetFriend== times[i][2]){
                return min;
            }
        }
        return 0;
    }
};