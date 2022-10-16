#include<bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1746/problem/B
// Two Pointer

int Rebelion(vector<int> &num){
    int c=0;
    int i=0; // i will point to first 1
    int j= num.size()-1; // j will point to last 0
    int count=0;
    while(i<j){
        if (num[i]!=1){
            i++;
            continue;
        }
        if (num[j]!=0){
            j--;
            continue;
        }
        if (num[i]==1 && num[j]==0){
            //swap
            int temp=num[i];
            num[i]=num[j];
            num[j]=temp;
            count++;
        }

    }
    return count;
}

int main(){
    int t;
    cin>>t;
    int n;
    while(t--){
        cin >> n;
        vector<int> num(n);
        for (auto&i:num){
            cin>>i;
        }
        int s= Rebelion(num);
        cout<< s <<endl;
    }
    return 0;
}