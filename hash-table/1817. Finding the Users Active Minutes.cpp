/*
1817. Finding the Users Active Minutes
Medium

https://leetcode.com/problems/finding-the-users-active-minutes/description/

You are given the logs for users' actions on LeetCode, and an integer k. 
The logs are represented by a 2D integer array logs where each logs[i] = [IDi, timei] indicates 
that the user with IDi performed an action at the minute timei.

Multiple users can perform actions simultaneously, and a single user can perform multiple 
actions in the same minute.

The user active minutes (UAM) for a given user is defined as the number of unique minutes in 
which the user performed an action on LeetCode. A minute can only be counted once, even if multiple 
actions occur during it.

You are to calculate a 1-indexed array answer of size k such that, for each j (1 <= j <= k), answer[j] 
is the number of users whose UAM equals j.

Return the array answer as described above.

 

Example 1:

Input: logs = [[0,5],[1,2],[0,2],[0,5],[1,3]], k = 5
Output: [0,2,0,0,0]
Explanation:
The user with ID=0 performed actions at minutes 5, 2, and 5 again. Hence, they have a UAM of 2 
(minute 5 is only counted once).
The user with ID=1 performed actions at minutes 2 and 3. Hence, they have a UAM of 2.
Since both users have a UAM of 2, answer[2] is 2, and the remaining answer[j] values are 0.
Example 2:

Input: logs = [[1,1],[2,2],[2,3]], k = 4
Output: [1,1,0,0]
Explanation:
The user with ID=1 performed a single action at minute 1. Hence, they have a UAM of 1.
The user with ID=2 performed actions at minutes 2 and 3. Hence, they have a UAM of 2.
There is one user with a UAM of 1 and one with a UAM of 2.
Hence, answer[1] = 1, answer[2] = 1, and the remaining values are 0.
 

Constraints:

1 <= logs.length <= 104
0 <= IDi <= 109
1 <= timei <= 105
k is in the range [The maximum UAM for a user, 105].


*/

/*
Algorithm

1. Take a map with key as userid and a set which stores all the time logs of that user
2. Take another map and store the freq of the set's size (UAM)
3. Make a list ans and push back p[j] from j=1 to k(inclusive)
4. Return ans

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int,set<int>> f; // id, timelogs
        // auto it = find(numbers.begin(), numbers.end(), target);
        for (auto t:logs){
            f[t[0]].insert(t[1]);
        }
        map<int,int> p;
        for (auto it=f.begin();it!=f.end();it++){
            // cout<< it->first<< " "<< it->second.size()<<endl;
            p[(it->second).size()]++; 
        }
        vector<int> ans;
        for(int j=1;j<=k;j++){
            ans.push_back(p[j]);
        }
        return ans;
    }
};

