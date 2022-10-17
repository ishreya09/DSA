// https://codeforces.com/contest/1744/problem/C

#include<bits/stdc++.h>
using namespace std;

int TrafficLight(string s,char c,int n){
    int time=0,j=0;
    if (c=='g'){
        return 0;
    }
    int i=0;
    
    for (i=0; i<s.length();i++){
        if(s[i]==c){
            j=i+1;
            while(s[j%n]!='g'){
                j++;
            }
            time=max<int>(j-i,time);
        }
    }
    return time;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        cout<< TrafficLight(s,c,n)<<endl;
    }

}
