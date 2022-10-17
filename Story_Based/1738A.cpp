/*

https://codeforces.com/problemset/problem/1738/A
Two Pointer

*/

/*
Algorithm

1. 
2. 
3.

*/

#include<bits/stdc++.h>
using namespace std;


long long int MaximumDestroy(vector<int>&A, vector<int> &B){
    int count0=0,count1=0;
    unordered_map<int, priority_queue<int>> f;
    long long int sum=0;
    for (int i=0; i<A.size();i++){
        sum+= B[i]; // adding all the values once which will give minimum damage
        if (A[i]){
            count1++;
            f[1].push(B[i]);
        }
        else{
            count0++;
            f[0].push(B[i]);
        }
    }

    int cnt;
    if (count1!=count0)
        cnt= min<int>(count0,count1);
    else
        cnt = count0-1;
    // cout<<"cnt = "<<cnt<<endl;
    while(cnt--){
        if (!f[1].empty()){
            sum+= f[1].top();
            // cout<< "f1: "<<f[1].top()<<endl;
            f[1].pop();
        }
        if (!f[0].empty()){
            sum+= f[0].top();
            // cout<< "f0: "<<f[0].top()<<endl;
            f[0].pop();
        }
    }

    if (count0==count1){
        sum=max<long long int>(sum+f[1].top(), sum+f[0].top());
    }

    return sum;



}

int main(){
    int t;
    cin>>t;
    int N;
    while(t--){
        cin>>N;
        vector<int>A(N);
        vector<int>B(N);
        for(auto&i :A){
            cin>>i;
        }
        for(auto &i : B){
            cin>>i;
        }
        long long int ans= MaximumDestroy(A,B);
        cout<<ans<<endl;
    }
    return 0;
}