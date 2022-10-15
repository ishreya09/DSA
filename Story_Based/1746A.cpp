// https://codeforces.com/contest/1746/problem/A

#include<bits/stdc++.h>
using namespace std;

string Maxmina(vector<int> &num,int k){
    int flag=0;
    for (int i=0;i<num.size();i++){
        if(num[i]==1){
            flag=1;
            break;
        }
    }
    string s;
    if(flag){
        s="YES";
    }
    else{
        s="NO";
    }
    return s;
}


int main(){
    int t;
    cin>>t;
    int n,k;
    while(t--){
        cin >> n>>k;
        vector<int> num(n);
        for (auto&i:num){
            cin>>i;
        }
        string s= Maxmina(num,k);
        cout<< s <<endl;
    }
    return 0;
}