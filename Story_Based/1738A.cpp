/*

https://codeforces.com/problemset/problem/1738/A
Two Pointer

*/

/*
Algorithm

1. 
2. 
3.

*/

#include<bits/stdc++.h>
using namespace std;


int MaximumDestroy(vector<int>&A, vector<int> &B){
    int m= *(max_element(B.begin(),B.end()));
    int min1=m,min0=m;
    int count0=0,count1=0;

    priority_queue<int> one,zero; 
    for (int i=0; i<B.size();i++){
        if (A[i]==0){
            min0=min<int>(min0,B[i]);
            count0++;
            zero.push(B[i]);
        }
        else{
            min1=min<int>(min1,B[i]);
            count1++;
            one.push(B[i]);
        }
    }
    
    priority_queue<int> one2=one,zero2=zero;
    int pos1= min0; // possibility 1 starts with 0
    int pos2= min1; // possibility 2 starts with 1
    int l1=0,l2=1;
    if(count0-1==0){
        pos1+=2*one.top();
        l1=1;
        one.pop();
    }
    if (count1-1==0){
        pos2+= 2*zero.top();
        l2=0;
        zero2.pop();
    }
    int i=0;

    while((!one.empty() && !zero.empty()) || (one2.empty() && !zero2.empty())){
        if (zero.top()==min0){
            zero.pop();
            continue;
        }
        else if( one2.top()==min1){
            one2.pop();
            continue;
        }

        if(i%2==0){
            if(one.empty() && !zero.empty()){
                pos1+= 2*one.top();
                l1=1;
                one.pop();
            }
            if(one2.empty() && !zero2.empty()){
                pos2+= 2*zero2.top();
                l2=0;
                zero2.pop();
            }
        }
        else{
            if(one.empty() && !zero.empty()){
                pos1+= 2*zero.top();
                l1=0;
                zero.pop();
            }
            if(one2.empty() && !zero2.empty()){
                pos2+= 2*one2.top();
                l2=1;
                one2.pop();
            }
        }
        i++;
    }

    while (!one.empty()){
        if (l1==0){
            pos1+= 2*one.top();
            l1=1;
            one.pop();
        }
        else{
            pos1+= one.top();
            one.pop();
        }
    }
    while (!zero.empty()){
        if (l1==1){
            pos1+= 2*zero.top();
            l1=0;
            zero.pop();
        }
        else{
            pos1+= zero.top();
            zero.pop();
        }
    }

    while (!one2.empty()){
        if (l2==0){
            pos2+= 2*one2.top();
            l2=1;
            one2.pop();
        }
        else{
            pos2+= one2.top();
            one2.pop();
        }
    }
    while (!zero2.empty()){
        if (l2==1){
            pos2+= 2*zero2.top();
            l2=0;
            zero2.pop();
        }
        else{
            pos2+= zero2.top();
            zero2.pop();
        }
    }

    
    return max<int>(pos1,pos2);
}

int main(){
    int N;
	cin>>N;
    vector<int>A(N);
    vector<int>B(N);
    for(auto&i :A){
        cin>>i;
    }
    for(auto &i : B){
        cin>>i;
    }
    int ans= MaximumDestroy(A,B);
    cout<<ans<<endl;

    return 0;
}