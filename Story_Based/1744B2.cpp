#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int>res(n);
    res=arr;
    int p=q;
    vector<int>t(2);
    while(p--)
    {
        for(int i=0;i<2;i++)
        {
            cin>>t[i];
        }
        if(t[0]==0)
        {
            for(int i=0;i<res.size();i++)
            {
            if(res[i]%2==0)
                {
                    res[i]+=t[1];
                }
            }
        }
        else if(t[0]==1)
        {
            for(int i=0;i<res.size();i++)
            {
            if(res[i]%2!=0)
                {
                    res[i]+=t[1];
                }
            }
        }
    cout<<accumulate(res.begin(),res.end(),0)<<endl;
    }
    }
    return 0;
}
