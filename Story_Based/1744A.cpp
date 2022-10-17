// https://codeforces.com/contest/1744/problem/A

#include<bits/stdc++.h>
using namespace std;

string NumberReplacement(vector<int> &nums,string s){
    map<int,char> f; // hash table to check if the number is same as earlier or not 
    for(int i=0;i<nums.size();i++){
        if (f[nums[i]]==0){
            f[nums[i]]=s[i];
        }
        else if(f[nums[i]]!=s[i]){
            return "NO";
        }
    }
    return "YES";
}

int main(){
    int T;
    cin>>T;
    while (T--){
        int N;
        cin>>N;
        vector<int> num(N);
        for(auto &i: num){
            cin>> i;
        }
        string s;
        cin>>s;
        string ans= NumberReplacement(num,s);
        cout<<ans<<endl;
    }   
    return 0;
}

// 7
// 5
// 2 3 2 4 1
// cacta
// 1
// 50
// a
// 2
// 11 22
// ab
// 4
// 1 2 2 1
// aaab
// 5
// 1 2 3 2 1
// aaaaa
// 6
// 1 10 2 9 3 8
// azzfdb
// 7
// 1 2 3 4 1 1 2
// abababb