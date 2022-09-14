/*
1094. Car Pooling
Medium

https://leetcode.com/problems/car-pooling/

There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] 
indicates that the ith trip has numPassengersi passengers and the locations to pick them up and 
drop them off are fromi and toi respectively. The locations are given as the number of kilometers 
due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

 

Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
 

Constraints:

1 <= trips.length <= 1000
trips[i].length == 3
1 <= numPassengersi <= 100
0 <= fromi < toi <= 1000
1 <= capacity <= 105

*/

/*
Algorithm 

1. 
2. 
3. 

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool static cmp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort (trips.begin(),trips.end(),cmp);
        int sum=0;
        int start=trips[0][1];
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > p;
        p.push(make_pair(trips[0][2],trips[0][0]));
        capacity -= trips[0][0];
        // pq is sorted by end time in ascending order
        if(capacity<0){
            return false;
        }
        for (int i=1; i<trips.size();i++){
            while (!p.empty() && trips[i][1]>=p.top().first ){ 
                cout<< capacity<<endl;
                capacity+=p.top().second;
                p.pop();
            }
            cout<< capacity<<endl;
            if (capacity >= trips[i][0] && start<=trips[i][1]){
                p.push(make_pair(trips[i][2],trips[i][0]));
                start=trips[i][1];
                capacity -= trips[i][0];
            }
            else if (capacity < trips[i][0] || start>trips[i][1] ) {
                return false;
            }
            cout<<capacity<<endl;

        }
        return true;
    }
};