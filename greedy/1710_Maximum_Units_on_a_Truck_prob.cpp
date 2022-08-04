// https://leetcode.com/problems/maximum-units-on-a-truck/

        /*
        Algorithm 
        1. sort the 2D array with respect to units per box
        2. Start taking the boxes and multiply it by its units until we reach the maximum 
        number of boxes
        */

       
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool static cmp (vector <int> &a, vector<int> &b){
        return a[1]>b[1];
    }
    
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // way to accept 2D vector (dynamic Array)
        
        
 
        // uses Quick Sorting Technique
        sort(boxTypes.begin(),boxTypes.end(),cmp);


        
        int nUnit=0; // to store the number of units here
        int nBox=0;
        int max=0;
        
        for (int i = 0; i<boxTypes.size();i++)
        {   
            if (nBox<=truckSize)
            {
                // some logical error in max
                cout<< nBox+boxTypes[i][0] << "\t" << boxTypes[i][0]<< "\t" << truckSize-nBox<< "\n";
                // max= boxTypes[i][0] ? (nBox+boxTypes[i][0]) <= truckSize  : (truckSize-nBox); 
                if (nBox+boxTypes[i][0] <= truckSize){
                    max= boxTypes[i][0];
                }
                else {
                    max= truckSize - nBox;
                }
                cout<< "max = "<< max<< endl;
                // number of box required of a specific unit
                nBox=nBox+max;
                nUnit+=  max *  boxTypes[i][1];
                cout<<i<<"\t"<<max<<"\t"<<nBox<< "\t"<< max * boxTypes[i][1]<<"\t"<<nUnit<<"\n";
            }
        }
        
        return nUnit;
        
    }
};


int main()
{
    vector<vector<int>> boxTypes = {
        {5, 10},
        {2, 5},
        {4, 7},
        {3,9}
    }; // 2D vector
    int truckSize = 10;
    Solution a;
    int unit = a.maximumUnits(boxTypes, truckSize);
    cout << unit << endl;
    return 0;
}