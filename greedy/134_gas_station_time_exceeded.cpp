
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*
        
        gas = [1,2,3,4,5]
        
        cost = [3,4,5,1,2]
        
        temp=gas[0];
        if(temp>cost[0])
        {
            
        }
        else
        {
            i++;
        }
        
        3 
        1-3+2=0
        1 2 3
        
        
        2
        2-4+5=3-5+1=-1
        
        3
        3-5+1
        
        4
        4-1+5=8
        8-2+1=7
        7-3+2=6
        6-4+3=5
        5-5+4=4
        
        2 3 4
        3 4 3
        
        2-3+3=2
        2-4+
        
        4-3+2=3
        3-3+3=3
        
        1 2 3 4 5
        3 4 5 1 2 
        
        */
        
        int n=gas.size();
        int i;
        for(i=0;i<n;i++)
        {
            int total=0,count=0,j=i;
            
            while(count<n)
            {
                total+=gas[j%n]-cost[j%n];
                //cout<<total<<endl;
                if(total<0)
                    break;
                j++;
                count++;
                
                //cout<<count<<endl;
            }
            //cout<<i<<endl;
            if(count==n)
                return i;
        }
        
        return -1;
    }
};