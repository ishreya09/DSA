/*
881. Boats to Save People
Medium

https://leetcode.com/problems/boats-to-save-people/

You are given an array people where people[i] is the weight of the ith person, and an 
infinite number of boats where each boat can carry a maximum weight of limit. Each boat 
carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

 

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
 

Constraints:

1 <= people.length <= 5 * 104
1 <= people[i] <= limit <= 3 * 104

*/

/*
Algorithm

1. sort the people array
2. take two pointer method by initialising j at end of array and i at start and if their sums is less than equal to 
the limit, we add one boat and increment i and decrement j. or else we decrement j.
3. At the end if (i==j)- only j got added at last and i is still left and people[i]<limit - we add 
one more boat.


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort (people.begin(),people.end());
        int i=0;
        int j=people.size()-1;
        int boats=0;
        while(i<j){
            if(people[i]+people[j]<=limit){
                boats++;
                i++;
                j--;
            }
            else if(people[i]+people[j]>limit){
                boats++;
                j--;
            }
        }
        if(people[i]<limit && i==j){
            boats++;
        }
        
        return boats;
    }
};