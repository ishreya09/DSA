// Time Exceeded
// Algorithm TC : O(n^2)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n= gas.size();
        int j=0,i=0,fuel=0,count=0;
        while(i<n){
            fuel+=gas[j%n]-cost[j%n];
            j++;
            count++;
            
            if (fuel<0){
                fuel =0;
                i++;
                j=i;
                count=0;
                continue;
            }            
            if (count == n){
                return i;
            }
        }
        return -1;
    }
};