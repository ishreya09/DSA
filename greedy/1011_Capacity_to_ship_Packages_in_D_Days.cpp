/*
1011. Capacity To Ship Packages Within D Days
Medium

https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/


A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages 
on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight 
capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being 
shipped within days days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting 
the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
 

Constraints:

1 <= days <= weights.length <= 5 * 104
1 <= weights[i] <= 500

*/

/*
Algorithm

(similar to array partition in three equal parts with a lil modification)
1. The capacity will be greater than or equal to the maximum number present in the array. 
Another thing is we can calculate sum and check for capacity accordingly by starting with maximum element or the avg.
2. 
3.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int capacity = *max_element (weights.begin(),weights.end());
        int sum = accumulate(weights.begin(),weights.end(),0);
        capacity  = max(capacity, (sum/days));
        int cur=0;
        int d=0;
        int k=1;
        // for (int i=0; i<weights.size(); i++){
        //     cur += weights[i];
        //     if (cur>k*capacity){
        //         cur-=weights[i] ;
        //         i--;
        //         d++;
        //         k++;
        //     }
        //     if (cur != sum && d==days){
        //         d=0;
        //         i=-1;
        //         capacity++;
        //     } 
        //     if (cur == sum && d==days){
        //         return capacity;
        //     }
        // }

        int i =0;
        while(!(cur == sum && d==days) == 0){
            cur+= weights[i];
            if (cur > k*capacity){
                d++;
                cur-= weights[i--];
                k++;
            }
            if (i== weights.size()-1){

                if (cur == sum && d!=days){
                    d=0;
                    i=-1;
                    int s=0;
                    for (int p= 0;p<weights.size();p++){
                        s+=weights[p]; 
                        if (s>capacity){
                            capacity=s;
                            break;
                        }
                    }
                }
            }

            i++;
        }
        return capacity;

    }
};