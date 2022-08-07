/*

621. Task Scheduler
Medium

https://leetcode.com/problems/task-scheduler/

Given a characters array tasks, representing the tasks a CPU needs to do, where
each letter represents a different task. Tasks could be done in any order. Each task 
is done in one unit of time. For each unit of time, the CPU could complete either 
one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between 
two same tasks (the same letter in the array), that is that there must be at least n units 
of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
Example 3:

Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
 

Constraints:

1 <= task.length <= 104
tasks[i] is upper-case English letter.
The integer n is in the range [0, 100].
*/

/*
Algorithm

1. if n =0, there would be no idle time, so length of array gives the time
also if size of array is only one - then irrespective of n, it will take only one time unit
2. If n >0 && tasks.size()>1, then create a map which keeps track of frequency of a character.
3. We find the maximum frequency of the character 
4. We also get the number of characters having maximum frequency
5. Now the time taken will be (max frequency-1)* (n+1) - Here we leave the last row as we don't know how many elements might 
come there
6. Now the time taken will be added with the characters of same frquency
7. If this count is less than tasks.size(), then this count is wrong and we return tasks.size() - 
This is working for test case like 
tasks= ["A","A","A","B","C","D","E","F"]
n=2


|-interval-|  len = n + 1
          |---n---|
        A _ _ _ _ _
        A _ _ _ _ _ 
        A _ _ _ _ _
        ...
        A _ _ _ _ _
        A B (k - number of character having maximum frequency) 

        with max frequency - 1 rows (except the last row)
        
        1. arrange for characters with maximum frequency. (greedy)
        2. arrange remaining characters from top to bottom and right to left.
        
        what if k > n?
        
        if k > n, extend intervals (meaning increase n)
        
        So, res = max((max frequency - 1) * (n + 1) + k, )



*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        sort (tasks.begin(),tasks.end());

        if (n==0 || tasks.size()==1){
            return tasks.size();
        }

        map<char,int> hash;
        for (auto ch : tasks) 
            hash[ch]++;
        
        int maxv = 0, cnt = 0;
        for (auto const &pair: hash) // way to access both key and pair
            maxv = max(maxv, pair.second); // contains maximum frequency of a task

        for (auto const &pair : hash) {
            if (maxv == pair.second) {
                cnt++;  // how many tasks have same number of  frequency
            }
            
        }
        return max(int(tasks.size()), (maxv - 1) * (n + 1) + cnt);

    }
};

int main(int argc, char const *argv[])
{
    vector <char> a={'A','A','A','B','B','B','C','C'};
    int n=2;
    cout<<endl<<Solution().leastInterval(a,n);
    return 0;
}

