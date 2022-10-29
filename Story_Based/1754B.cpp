// https://codeforces.com/contest/1754/problem/B
// didn't get solved

#include<bits/stdc++.h>
using namespace std;

vector<int> KevinPermutation(int n){
    int start =1;
    int end=n;
    int k=0;
    vector<int> ans;
    while (start <= end){
        if (start==end){
            if (abs(ans[0]-start)>= abs(ans[ans.size()-1]-start)){
                ans.insert(ans.begin(),start);
                break;
            } 
            else{
                ans.push_back(start);
                break;
            }
        }
        if (k%2==0){
            ans.insert(ans.begin(),end--);
            ans.push_back(start++);
            k++;
        }
        else {
            ans.insert(ans.begin(),start++);
            ans.push_back(end--);
            k++;
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> ans = KevinPermutation(n);
        for (int i=0; i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}