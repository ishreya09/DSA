// https://codeforces.com/problemset/problem/1611/B

#include <bits/stdc++.h>
using namespace std;

int TeamComposition(int mn,int mx){
    // mx is max
    // mn is min

    if (mn==0){
        return 0;
    }
    else if(mn==1){ 
        return (mx>=3) ? 1 :0;
    }
    else if(mn==mx){
        return mn/2;
    }
    else if(3*mn<=mx){
        return mn;
    }
    else{
        if (mn*2< mx){
            int q= mx/3;
            mx = mx%3;
            mn-= q;
            if(mn>0 && mx>0 && mn+mx >=4 ){
                return q + TeamComposition(mn,mx);
            }
            else{
                return q;
            }

        }
        else{
            int c=mn/2;
            mx=mx/2;
            mn =mn%2;
            if(mn>0 && mx>=3){
                return c+1;
            }
            else{
                return c;
            }
        }
    }


}

int main(){
    int t;
    cin>> t;
    while(t--){
        int m,p;
        cin>>m>>p;
        cout<< TeamComposition(min<int>(m,p),max<int>(m,p))<<endl;
    }
}