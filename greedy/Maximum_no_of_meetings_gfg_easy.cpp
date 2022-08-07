/*
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) 
where start[i] is start time of meeting i and end[i] is finish time of meeting i.

What is the maximum number of meetings that can be accommodated in the meeting room when only one
 meeting can be held in the meeting room at a particular time?
 
Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =   {2,4,6,7,9,9}
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
Algorithm

1. Create a vector of pair and make sure to keep end time as first element as we 
can apply sort directly.
If we apply sort function in pair or 2D vector - then by default it gets sorted with first value
2. sort the vector wrt to end time
3. now if start time is greater than previous meeting's end time- then add to no of meetings. 
*/

#include <bits/stdc++.h>
using namespace std;

int main (){
    vector<int> start={1,3,0,5,8,5};
    start={10,12,20};
    vector<int> end={2,4,6,7,9,9};
    end={20,25,30};
    int N= end.size();

    vector <pair<int,int>> arr(start.size());

    for (int i= 0; i<N; i++){
        arr[i].first = end[i];
        arr[i].second = start[i]; 
    }

    // sorting according to end time
    sort (arr.begin(),arr.end()); // this sorts according to the first value 

    int n=0; // no. of meetings
    int e=0;
    for (int i=0; i<N;i++){
        if (arr[i].second>e ){
            n++;
            e=arr[i].first;
        }
    }

    cout<<n<<endl;

    return 0;

}


