/*

https://codeforces.com/problemset/problem/1646/B
Two Pointer

*/

/*
Algorithm

1. Sort the Array
2. Use 2 pointer method and count blue balls from i=0 and red balls from num.size()-1
3. Keep a track of counts of blue and red ball and once both condition is true, return Yes else No
4. Also if the whole array has the same number - then answer is always no.

*/

#include<bits/stdc++.h>
using namespace std;

string QualityvsQuantity(vector<long long int> &num){
    sort(num.begin(),num.end());
    int i= 0;
    int j=num.size()-1;
    long long int B=num[i++],R=num[j--]; // sum count
    long long int cntB=1,cntR=1; // number of balls
    if(num[0] != num[j+1]){
        while(i<=j){
            if (cntB <= cntR && B<R){
                B+= num[i++]; 
                cntB++;
            }
            else if(cntB<=cntR && B>=R){
                R+= num[j--];
                cntR++;
            }
            else if(cntB >cntR && B>=R){
                R+= num[j--];
                cntR++;
            }
            
            // cout<<"Blue :"<< B<< " "<<cntB<<endl;
            // cout<<"Red :"<< R<< " "<<cntB<<endl;
            if (cntB > cntR && B<R){
                return "YES";
            }
        }
    }
    return "NO";
}

int main(){
    int T;
    cin>>T;
    int N;
    while(T--){
        cin>>N;
        vector<long long int> A(N);
        for (auto&i : A){
            cin>> i;
        }
        string ans = QualityvsQuantity(A);
        cout<<ans<<endl;

    }
    return 0;
}