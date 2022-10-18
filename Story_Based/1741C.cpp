// https://codeforces.com/problemset/problem/1741/C

#include<bits/stdc++.h>
using namespace std;

int MinimizeThickness(vector<int> &nums){
    set<int> sub;
    int f=0; // f is cummulative frequency
    int sum= accumulate(nums.begin(),nums.end(),0);// start value as 0
    for (int i=0; i<nums.size();i++){
        f+=nums[i];
        if(sum%f==0){
            int c=0;
            int s=0;
            int cnt=0;
            for(int j=0;j<nums.size();j++){
                s+=nums[j];
                c++;
                if (s==f){
                    cnt= max<int>(cnt,c);
                    s=0;
                    c=0;
                }
                else if (s>f){
                    cnt=0;
                    break;
                }
            }
            if(cnt != 0)
                sub.insert(cnt);
            
        }
    }
    return *(sub.begin());
}


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<int> num(N);
        for(auto &i:num){
            cin>>i;
        }
        cout<<MinimizeThickness(num)<<endl;
    }
    return 0;
}