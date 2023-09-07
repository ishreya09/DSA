/*
1665. Minimum Initial Energy to Finish Tasks
Hard

https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/description/

You are given an array tasks where tasks[i] = [actuali, minimumi]:

actuali is the actual amount of energy you spend to finish the ith task.
minimumi is the minimum amount of energy you require to begin the ith task.
For example, if the task is [10, 12] and your current energy is 11, you cannot start this task. However, 
if your current energy is 13, you can complete this task, and your energy will be 3 after finishing it.

You can finish the tasks in any order you like.

Return the minimum initial amount of energy you will need to finish all the tasks.

 

Example 1:

Input: tasks = [[1,2],[2,4],[4,8]]
Output: 8
Explanation:
Starting with 8 energy, we finish the tasks in the following order:
    - 3rd task. Now energy = 8 - 4 = 4.
    - 2nd task. Now energy = 4 - 2 = 2.
    - 1st task. Now energy = 2 - 1 = 1.
Notice that even though we have leftover energy, starting with 7 energy does not work because 
we cannot do the 3rd task.
Example 2:

Input: tasks = [[1,3],[2,4],[10,11],[10,12],[8,9]]
Output: 32
Explanation:
Starting with 32 energy, we finish the tasks in the following order:
    - 1st task. Now energy = 32 - 1 = 31.
    - 2nd task. Now energy = 31 - 2 = 29.
    - 3rd task. Now energy = 29 - 10 = 19.
    - 4th task. Now energy = 19 - 10 = 9.
    - 5th task. Now energy = 9 - 8 = 1.
Example 3:

Input: tasks = [[1,7],[2,8],[3,9],[4,10],[5,11],[6,12]]
Output: 27
Explanation:
Starting with 27 energy, we finish the tasks in the following order:
    - 5th task. Now energy = 27 - 5 = 22.
    - 2nd task. Now energy = 22 - 2 = 20.
    - 3rd task. Now energy = 20 - 3 = 17.
    - 1st task. Now energy = 17 - 1 = 16.
    - 4th task. Now energy = 16 - 4 = 12.
    - 6th task. Now energy = 12 - 6 = 6.
 

Constraints:

1 <= tasks.length <= 105
1 <= actual​i <= minimumi <= 104

*/

/*
Algorithm

1. Sort the tasks array according to the difference of mininum enrgy and actual energy required to
complete the task
2. Iterate through the sorted list, if minimum energy > current energy - then add minimum energy-cur to res
and cur to minimum energy
3. We keep on substracting actual energy from the current energy.

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool static cmp(vector<int> &a,vector<int> &b){
        return a[1]-a[0]> b[1]-b[0];
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),cmp);

        int res = 0, curr = 0; // curr min energy

        for (int i=0;i<tasks.size();i++){
            if(tasks[i][1] > curr){
                res+= tasks[i][1]-curr;
                curr=tasks[i][1];
            }
            curr-=tasks[i][0]; 
        }
        return res;
    }
};


// TLE at 1 testcase
struct Compare {
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        return a.first-a.second < b.first-b.second;
    }
};

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        // max heap according to compare
        // sorted for max abs difference of [minimum, actual]
        for(auto v:tasks) 
            pq.push({v[1], v[0]});
        

        int res = 0, curr = 0; // curr min energy

        while(!pq.empty()){
            if(pq.top().first > curr) // minimum energy reqd > curr energy
                res += (pq.top().first-curr), // res += difference to add
                curr = pq.top().first; // curr energy set
                
            // cout<<res<<" "<<curr<<" "<<pq.top().first<<" "<<pq.top().second<<endl;
            // cur stores the left energy
            curr -= pq.top().second; // using the actual from curr energy 

            // cout<<res<<" "<<curr<<" "<<pq.top().first<<" "<<pq.top().second<<endl;

            pq.pop();
        }
        return res;
    }
};


