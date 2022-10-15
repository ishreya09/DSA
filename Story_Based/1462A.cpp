/*

https://codeforces.com/problemset/problem/1462/A
Two Pointer

*/

/*
Algorithm

1. Use two pointer method to traverse through the array and push the starting element first and then 
the last element
2. In case if i==j, just push once

*/

#include<bits/stdc++.h>
using namespace std;


vector<int> FavSequence(vector<int> &num){
    vector<int> ans;

    int i=0;
    int j= num.size()-1;

    while(i<=j){
        if (i==j){
            ans.push_back(num[i]);
        }
        else{
            ans.push_back(num[i]);
            ans.push_back(num[j]);
        }
        i++;
        j--;
    }
    return ans;

}

int main(){
    int T;
    cin>>T;
    int N;
    while(T--){
        cin>>N;
        vector<int> A(N);
        for (auto&i : A){
            cin>> i;
        }
        vector<int> ans = FavSequence(A);
        for (auto i:ans){
            cout<< i<<" ";
        }
        cout<<endl;

    }

    return 0;
}