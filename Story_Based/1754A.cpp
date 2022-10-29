// https://codeforces.com/contest/1754/problem/A

#include <bits/stdc++.h>
using namespace std;

string TechnicalSupport(string s,int n){
    int q=0,a=0;
    int i=0;
    while(i<n){
        if(s[i]=='Q'){
            q++;
        }
        else{
            a++;
        }

        if (q<=a){
            q=0;
            a=0;
        }
        i++;
    }
    return (q==a && a==0 && q==0) ? "YES" : "NO" ;
}

int main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        string s="";
        cin>>n;
        cin>>s;
        cout<<TechnicalSupport(s,n)<<endl;
    }
}