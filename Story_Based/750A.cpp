// https://codeforces.com/problemset/problem/750/A

// Brute Force

#include<bits/stdc++.h>
using namespace std;

// Brute Force - TC - O(n)
int NewYearAndHurry(int n,int k){
    int mins= 240-k;
    int left=0;
    int i=1;
    if(mins<5 && n>0){
        return 0;
    }

    while (mins>=i*5 && n--){
        mins-= i*5;
        i++;
    }
    return i-1;
}


int main(){
    int n,k;
    cin>> n>>k;
    cout<< NewYearAndHurry(n,k)<<endl;
    return 0;
}