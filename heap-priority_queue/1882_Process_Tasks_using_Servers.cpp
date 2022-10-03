/*
1882. Process Tasks Using Servers
Medium

https://leetcode.com/problems/process-tasks-using-servers/

You are given two 0-indexed integer arrays servers and tasks of lengths n​​​​​​ and m​​​​​​ respectively. 
servers[i] is the weight of the i​​​​​​th​​​​ server, and tasks[j] is the time needed to process the j​​​​​​th​​​​ task in seconds.

Tasks are assigned to the servers using a task queue. Initially, all servers are free, and the queue is empty.

At second j, the jth task is inserted into the queue (starting with the 0th task being inserted at second 0). 
As long as there are free servers and the queue is not empty, the task in the front of the queue will be 
assigned to a free server with the smallest weight, and in case of a tie, it is assigned to a free server with the smallest index.

If there are no free servers and the queue is not empty, we wait until a server becomes free and immediately 
assign the next task. If multiple servers become free at the same time, then multiple tasks from the queue will be 
assigned in order of insertion following the weight and index priorities above.

A server that is assigned task j at second t will be free again at second t + tasks[j].

Build an array ans​​​​ of length m, where ans[j] is the index of the server the j​​​​​​th task will be assigned to.

Return the array ans​​​​.

 

Example 1:

Input: servers = [3,3,2], tasks = [1,2,3,2,1,2]
Output: [2,2,0,2,1,2]
Explanation: Events in chronological order go as follows:
- At second 0, task 0 is added and processed using server 2 until second 1.
- At second 1, server 2 becomes free. Task 1 is added and processed using server 2 until second 3.
- At second 2, task 2 is added and processed using server 0 until second 5.
- At second 3, server 2 becomes free. Task 3 is added and processed using server 2 until second 5.
- At second 4, task 4 is added and processed using server 1 until second 5.
- At second 5, all servers become free. Task 5 is added and processed using server 2 until second 7.
Example 2:

Input: servers = [5,1,4,3,2], tasks = [2,1,2,4,5,2,1]
Output: [1,4,1,4,1,3,2]
Explanation: Events in chronological order go as follows: 
- At second 0, task 0 is added and processed using server 1 until second 2.
- At second 1, task 1 is added and processed using server 4 until second 2.
- At second 2, servers 1 and 4 become free. Task 2 is added and processed using server 1 until second 4. 
- At second 3, task 3 is added and processed using server 4 until second 7.
- At second 4, server 1 becomes free. Task 4 is added and processed using server 1 until second 9. 
- At second 5, task 5 is added and processed using server 3 until second 7.
- At second 6, task 6 is added and processed using server 2 until second 7.
 

Constraints:

servers.length == n
tasks.length == m
1 <= n, m <= 2 * 105
1 <= servers[i], tasks[j] <= 2 * 105
*/

/*
Algorithm 
Inefficient method

1. we assign a set to the available no. of servers in a set - available ones
2. initialize time as 0 and traverse through tasks array.
3. Make 2 pq - one to store the tasks getting processed and the other in the wait queue
4. We store all the servers in a set and we remove the elements from set when a server is assigned
5. We do this process simentaneously and push the element in getting processed pq 
6. If the servers are unavailable, we add the elements in another priority queue of indexes and assign then
as soon as any server becomes free

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        set<pair<int,int>> s; // available server (value,index)
        for(int i=0; i<servers.size();i++){
            s.insert(make_pair(servers[i],i));
        }
        int time=0; // current time
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>> > pq; 
        // (end time of task = i+tasks[i], index of tasks array element, index of server assigned)
        priority_queue<int,vector<int>,greater<int>> wait; // index of wait queue
        vector<int> ans;
        for(int i=0;i<tasks.size() || !wait.empty();i++){
            while(!pq.empty() && pq.top()[0]<= time){
                int p= pq.top()[2];
                s.insert(make_pair(servers[p],p));
                pq.pop();
            }
            if (s.empty() && i<tasks.size() ){
                wait.push(i);
                // i--; // stay on same index 
            }
            else {
                while(!s.empty() && !wait.empty()){
                    int idx= wait.top();
                    wait.pop();
                    int k= time+tasks[idx];
                    auto it = *s.begin();
                    pq.push({k,idx,it.second});
                    s.erase(it);
                    ans.push_back(it.second);
                }
                
                if (!s.empty() && i<tasks.size()){             
                    int k= time+tasks[i];
                    auto it = *s.begin();
                    pq.push({k,i,it.second});
                    s.erase(it);
                    ans.push_back(it.second);
                }
                else if(i<tasks.size()){
                    wait.push(i);
                }

            }
            if(i<tasks.size())
                time ++;
            else{
                time= pq.top()[0]; 
            }
        }
        return ans;        
    }
};