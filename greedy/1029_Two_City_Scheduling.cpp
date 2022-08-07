/*
1029. Two City Scheduling
Medium

https://leetcode.com/problems/two-city-scheduling/

A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti],
the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.



Example 1:

Input: costs = [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation:
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
Example 2:

Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
Output: 1859

Example 3:

Input: costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
Output: 3086


Constraints:

2 * n == costs.length
2 <= costs.length <= 100
costs.length is even.
1 <= aCosti, bCosti <= 1000

*/

/*
Algorithm

1. Calculate the difference and push back the difference in the 2d vector
2. Sort the array accoring to this difference - **
3. For half of the array - add for A city and rest half now as B city or vice versa - depending on how we calculated 
the difference.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool static cmp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int i;
        for (i = 0; i < costs.size(); i++)
        {
            // a- b 
            costs[i].push_back(costs[i][0] - costs[i][1]); // diff will be positive if a>b or else negative
        }

        // sorting on basis of difference
        sort(costs.begin(), costs.end(), cmp);
        

        int sum=0;
        int k=0;
        for (i = 0; i < costs.size(); i++)
        {
            if (k<costs.size()/2 ){
                sum+= costs[i][0];
                k++;
            }            
            else {
                sum+= costs[i][1];
                k++;
            }
        }
        return sum;
    }
};
