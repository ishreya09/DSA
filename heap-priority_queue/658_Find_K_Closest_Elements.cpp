/*
658. Find K Closest Elements
Medium

https://leetcode.com/problems/find-k-closest-elements/

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array.
The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b


Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]


Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104
*/

/*
Algorithm

1. 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> ans;

        priority_queue<int, vector<int>, greater<int>> p; // positive numbers
        priority_queue<int> n;                            // Negative numbers
        int diff;
        for (int i = 0; i < arr.size(); i++)
        {
            diff = arr[i] - x;
            if (diff <= 0)
            {
                n.push(diff);
            }
            else
            {
                p.push(diff);
            }
        }
        // preference will be given to negative in case of clash
        int c = 0;
        while (c < k)
        {
            if (!n.empty() && !p.empty() && -1 * n.top() <= p.top())
            {
                ans.push_back(n.top() + x);
                n.pop();
                c++;
            }
            else if (!n.empty() && !p.empty() && p.top() < -1 * n.top())
            {
                ans.push_back(p.top() + x);
                p.pop();
                c++;
            }
            else if (n.empty() && !p.empty())
            {
                ans.push_back(p.top() + x);
                p.pop();
                c++;
            }
            else if (!n.empty() && p.empty())
            {
                ans.push_back(n.top() + x);
                n.pop();
                c++;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};