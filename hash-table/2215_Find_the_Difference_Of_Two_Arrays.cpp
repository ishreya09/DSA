/*


*/

/*
Algorithm

1. Keep the frequency counts of both the array
2. Now iterate over the maps and check if both are equal- if equal increment both, otherwise check which is smaller 
and if the value exists in another list. Check the same for larger value as well and increment if true
3. At the end, check if any one of the map which has not reached its end- go on pushing values into the repective array.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> n1;
        map<int,int> n2;
        for (int i=0; i<nums1.size();i++){
            n1[nums1[i]]++;
        }
        for (int i=0; i<nums2.size();i++){
            n2[nums2[i]]++;
        }
        
        vector<vector<int>> ans(2);
        
        auto i1= n1.begin();
        auto i2= n2.begin();
        while(i1!=n1.end() && i2!= n2.end()){
            if (i1->first == i2->first){
                cout<<"Equal : "<< i1->first<<"\t"<< i2->first<<"\t"<<n2[i1->first]<<"\t"<<n1[i2->first]<<endl;
                i1++;
                i2++; // skip
            }
            else if(i1->first != i2->first){
                cout<<"NotEq : "<< i1->first<<"\t"<< i2->first<<"\t"<<i1->second<<"\t"<<i2->second<<"\t"<<n2[i1->first]<<"\t"<<n1[i2->first]<<endl;
                if (i1->first<i2->first){
                    if (i1->second>0 && n2[i1->first]==0){
                        ans[0].push_back(i1->first);
                    }
                    if (i2->second>0 && n1[i2->first]==0){
                        ans[1].push_back(i2->first);
                        i2++;
                    }
                    i1++;
                }
                else if(i1->first>i2->first){
                    if (i1->second>0 && n2[i1->first]==0){
                        ans[0].push_back(i1->first);
                        i1++;
                    }
                    if (i2->second>0 && n1[i2->first]==0){
                        ans[1].push_back(i2->first);
                    }
                    i2++;
                }
            }
        }
        while (i1!= n1.end()){
            if(i1->second>0){
                ans[0].push_back(i1->first);
            }
            i1++;
        }
        while (i2!= n2.end()){
            if(i2->second>0){
                ans[1].push_back(i2->first);
            }
            i2++;
        }
        return ans;
    }
};