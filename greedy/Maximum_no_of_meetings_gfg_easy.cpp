/*
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) 
where start[i] is start time of meeting i and end[i] is finish time of meeting i.

What is the maximum number of meetings that can be accommodated in the meeting room when only one
 meeting can be held in the meeting room at a particular time?
 
Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Input:
N = 3
start[] = {10, 12, 20}
end[] = {20, 25, 30}
Output: 
1

*/

/*
1. use a map 
2. take end time as a key and start time as value
3. now lets take this map in a loop and compare
*/

#include <bits/stdc++.h>
using namespace std;

int main (){
    vector<int> start={1,3,0,5,8,5};
    vector<int> end={2,4,6,7,9,9};
    int N= end.size();

    map<int,int> time;

    for (int i=0; i<N; i++){
        // map is already sorted wrt to key
        time[end[i]] = start[i];
    }

    for (int i= 0; i<N; i++){
        
    }

}


