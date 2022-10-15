#include<bits/stdc++.h>
using namespace std;



int Rebelion(vector<int> &num){
    int c=0;
    int i=0;
    int j= num.size()-1;
    while(i<j){

    }
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