// https://codeforces.com/problemset/problem/1729/D


#include<bits/stdc++.h>
using namespace std;


int FriendsAndRestaurant(vector<int> &x,vector<int> &y,int n){
    vector<int> b;
    if (n==2){
        return (x[0]+x[1] <= y[0]+y[1] )? 1 : 0;
    }
    for (int i=0; i<n;i++){
        b.push_back(y[i]-x[i]);
    }

    sort (b.begin(),b.end());

    if (b[b.size()-1]<0){
        return 0;
    }
    int days=0;
    int i=0,j=n-1;
    while (i<j){
        // size of array is atleast 2
        if (b[i]+b[j]>=0){ // minimum 2 conditions
            days++;
            i++;
            j--;
        }
        else{
            int s=b[i]+b[j];
            int k=i+1;
            while(k<j && s<0){
                s+= b[k];
                k++;
            }
            if (s<0){
                i++;
                continue;
            }
            else{
                days++;
                i= k+1;
                j--;
            }
        }
    }
    return days;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> x(n);
        vector<int> y(n);
        for (auto &i:x){
            cin>>i;
        }
        for (auto &i:y){
            cin>>i;
        }

        cout<<FriendsAndRestaurant(x,y,n)<<endl;
    }

    return 0;
}