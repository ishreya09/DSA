#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    string s;
    cin>>s;
    map<char,int>mp1;
    map<int,int>mp2;
    for(auto i:s)
    {
        mp1[i]++;
    }
    for(auto i:arr)
    {
        mp2[i]++;
    }
    vector<int>a;
    for(auto i:mp1)
    {
        a.push_back(i.second);
    }
    int flag=0;
    for(auto i:mp2)
    {
        if(std::find(a.begin(), a.end(), i.second) == a.end())
        {
            flag=1;
            break;
        }
    }
    if(mp1.size()==1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
    if(flag==0)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    }
    }
    return 0;
}
