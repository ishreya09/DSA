// https://codeforces.com/problemset/problem/1366/A#:~:text=In%20this%20game%2C%20he%20can,sold%20for%20exactly%20one%20emerald

#include<bits/stdc++.h>
using namespace std;

long int ShovelsAndSwords(long int a,long int b){
    if (2*a<b){ // if a or b is twice than that of the other value
        return a;
    }
    else if(2*b<a){
        return b;
    }
    else{ // if a or b (each ) is greater than max/2
        return (a+b)/3;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long int a,b;
        cin>>a>>b;
        cout<< ShovelsAndSwords(a,b)<<endl;
    }
}