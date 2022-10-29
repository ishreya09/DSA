// https://codeforces.com/contest/1754/problem/A

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s="";
    cin>>s;
    unordered_map<char,int>mp;
    for(auto i:s)
    {
        mp[i]++;
    }
    if(mp['Q']>mp['A'])
    {
        cout<<"NO"<<endl;
    }
    else{
        int i=0,j=0;
        while(i<s.size())
        {
            if(s[i]=='Q')
            {
                j=i+1;
                while(j<s.size())
                {
                    if(s[j]=='A')
                    {
                        s.erase(j,1);
                        break;
                    }
                    j++;
                }
                if (j==n)
                {
                    cout<<"NO"<<endl;
                }
            }
            i++;
        }
        cout<<"YES"<<endl;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}