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
    int t1,t2;
    vector<int>t(2);
    while(q--)
    {
        cin>>t1>>t2;
        if(t1==0)
        {
            for(int i=0;i<res.size();i++)
            {
            if(res[i]%2==0)
                {
                    res[i]+=t2;
                }
            }
        }
        else if(t1==1)
        {
            for(int i=0;i<res.size();i++)
            {
            if(res[i]%2!=0)
                {
                    res[i]+=t2;
                }
            }
        }
    long long int ans=0;
    for(long long int i:res)
    {
        ans+=i;
    }
    cout<<ans<<endl;
    }
    }
    return 0;
}
