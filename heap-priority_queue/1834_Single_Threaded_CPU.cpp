/*
1834. Single-Threaded CPU
Medium

https://leetcode.com/problems/single-threaded-cpu/

You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] 
means that the i​​​​​​th​​​​ task will be available to process at enqueueTimei and will take processingTimei to finish processing.

You have a single-threaded CPU that can process at most one task at a time and will act in the following way:

If the CPU is idle and there are no available tasks to process, the CPU remains idle.
If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. If multiple 
tasks have the same shortest processing time, it will choose the task with the smallest index.
Once a task is started, the CPU will process the entire task without stopping.
The CPU can finish a task then start a new one instantly.
Return the order in which the CPU will process the tasks.

 

Example 1:

Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
Output: [0,2,3,1]
Explanation: The events go as follows: 
- At time = 1, task 0 is available to process. Available tasks = {0}.
- Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.
- At time = 2, task 1 is available to process. Available tasks = {1}.
- At time = 3, task 2 is available to process. Available tasks = {1, 2}.
- Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the shortest. Available tasks = {1}.
- At time = 4, task 3 is available to process. Available tasks = {1, 3}.
- At time = 5, the CPU finishes task 2 and starts processing task 3 as it is the shortest. Available tasks = {1}.
- At time = 6, the CPU finishes task 3 and starts processing task 1. Available tasks = {}.
- At time = 10, the CPU finishes task 1 and becomes idle.
Example 2:

Input: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
Output: [4,3,2,0,1]
Explanation: The events go as follows:
- At time = 7, all the tasks become available. Available tasks = {0,1,2,3,4}.
- Also at time = 7, the idle CPU starts processing task 4. Available tasks = {0,1,2,3}.
- At time = 9, the CPU finishes task 4 and starts processing task 3. Available tasks = {0,1,2}.
- At time = 13, the CPU finishes task 3 and starts processing task 2. Available tasks = {0,1}.
- At time = 18, the CPU finishes task 2 and starts processing task 0. Available tasks = {1}.
- At time = 28, the CPU finishes task 0 and starts processing task 1. Available tasks = {}.
- At time = 40, the CPU finishes task 1 and becomes idle.
 

Constraints:

tasks.length == n
1 <= n <= 105
1 <= enqueueTimei, processingTimei <= 109

*/

/*
Algorithm 

1. push index at the end of the vector and then sort the vector wrt to the enque time
2. Make a priority queue pq of pair having burst time and index and define startTime as tasks[0][0]
3. Go on adding the tasks having time <= startTime and process the shortest task and add the burst time to the startTime
4. It can happen that after a time - startTime would be less than whats there in the vector for tasks - so if pq is empty 
It is important that we initialize start time again to the new start time and resume the above steps.
5. Push back the index(2nd element of the pair) and return it back in the end.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int inx=0; inx<tasks.size(); inx++){
            tasks[inx].push_back(inx);
        }
        
        sort(tasks.begin(), tasks.end());
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        
        vector<int>ans;
        
        int i = 0;
        for(; i<tasks.size(); i++){
            if(tasks[i][0]!=tasks[0][0])
                break;
            
            pq.push({tasks[i][1], tasks[i][2]}); 
        }
        
        long long startTime = tasks[0][0];
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            ans.push_back(cur.second);
            
            startTime += cur.first;
            
             for(; i<tasks.size(); i++){
                 if(tasks[i][0]> startTime)
                    break;
                 
                 pq.push({tasks[i][1],tasks[i][2]}); 
            }
            
            if(pq.empty() && i<tasks.size()){
                pq.push({tasks[i][1],tasks[i][2]});
                startTime = tasks[i][0];
                i++;
            }
        }
        
        
        return ans;  
    }
};