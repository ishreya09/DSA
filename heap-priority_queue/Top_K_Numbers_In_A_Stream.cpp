/*
Top k numbers in a stream
Medium

https://practice.geeksforgeeks.org/problems/top-k-numbers3425/1?page=1&category[]=priority-queue&sortBy=submissions

Given N numbers in an array. Your task is to keep at-most K numbers at the top (According to their frequency).  
We basically need to print top k numbers when input stream has included k distinct elements, else need 
to print all distinct elements sorted by frequency.

Example 1:

Input:
N=5, K=4
arr[] = {5, 2, 1, 3, 2} 
Output: 5 2 5 1 2 5 1 2 3 5 2 1 3 5 
Explanation:
Firstly their was 5 whose frequency
is max till now. so print 5.
Then 2 , which is smaller than 5 but
their frequency is same so print 2 5.
Then 1, which is smallet among all the
number arrived, so print 1 2 5.
Then 3 , so print 1 2 3 5
Then again 2, which has the highest
frequency among all number so 2 1 3 5.
Example 2:

Input:
N=5, K=4
arr[] = {5, 2, 1, 3, 4} 
Output: 5 2 5 1 2 5 1 2 3 5 1 2 3 4 
Explanation:
Firstly their was 5 whose frequency is
max till now. so print 5.
Then 2 , which is smaller than 5 but
their frequency is same so print 2 5.
Then 1, Which is smallest among all the
number arrived, so print 1 2 5.
Then 3 , so print 1 2 3 5.
Then 4, so 1 2 3 4 as K is 4 so print
at-most k elements.
 

Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function kTop() that takes array a, integer n and integer k as parameters and returns the array that contains our desired output.

 

Expected Time Complexity: O(N*K).
Expected Auxiliary Space: O(N).

 

Constraints:
1 ≤ N,K ≤ 103
*/

/*
Algorithm 

1. Make a compare struct to store in the priority queue
2. Make an unordered map and store the frequency of input stream and simentanously,
3. read char by char and go on printing using printpq function
4. printpq is a func which takes unordered map and k value. We store printpq into a priority_queue and 
print first k values in the input stream. 


*/

#include<bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};

class Solution
{
  public:
    void printpq(unordered_map<int,int> &pq,int k){
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> p;
        for(auto i=pq.begin();i!=pq.end();i++){
            p.push(make_pair(i->second,i->first));
        }
        while(!p.empty() && k--){
            cout<<p.top().second <<" ";
            p.pop();
        }
    }
    vector<int> kTop(int a[], int n, int k) 
    { 
        //code here.
        unordered_map<int,int> f;
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> p;
        for (int i=0;i<n;i++){
            f[a[i]]++;
            // if(i<=k){
                printpq(f,k);
            // }
            
        }
        
        for (int i=0;i<n;i++){
            p.push(make_pair(f[a[i]],a[i]));
        }
        
        vector<int> ans;
        // while(k-- ){
        //     ans.push_back(p.top().second);
        //     p.pop();
        // }
        return ans;
    }
};