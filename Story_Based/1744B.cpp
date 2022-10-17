// https://codeforces.com/contest/1744/problem/B

#include<bits/stdc++.h>
using namespace std;

long long int sumArray(vector<long long int> &a){
    long long int s=000000000;
    for(auto i:a){
        s+=i;
    }
    return s;
}

void EvenOddIncrements(vector<long long int> &num,int q){
    while(q--){
        int type,xj;
        cin>>type>>xj;
        if(type==0){
            for (int i=0;i<num.size();i++){
                if (num[i]%2==0){
                    num[i]+=xj;
                }
            }
        }
        else if(type==1){
            for (int i=0;i<num.size();i++){
                if(num[i]%2==1){
                    num[i]+=xj;
                }
            }
        }
        cout<<sumArray(num)<<endl;
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int N,Q;
        cin>>N>>Q;
        vector<long long int> num(N);
        for(auto &i:num){
            cin>>i;
        }
        EvenOddIncrements(num,Q);
    }
    
    return 0;
}

// 4
// 1 1
// 1
// 1 1
// 3 3
// 1 2 4
// 0 2
// 1 3
// 0 5
// 6 7
// 1 3 2 4 10 48
// 1 6
// 0 5
// 0 4
// 0 5
// 1 3
// 0 12
// 0 1
// 6 7
// 1000000000 1000000000 1000000000 11 15 17
// 0 17
// 1 10000
// 1 51
// 0 92
// 0 53
// 1 16
// 0 1
