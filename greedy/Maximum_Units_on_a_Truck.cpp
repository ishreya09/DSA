#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Because static method belong to class and it's not an object specific. 
    // Where as for non static instance method we need to create an object.
    // if you use static in front of any function, you kind of restrict the function to be used only where it is declared and not outside that
    bool static cmp(vector<int>&a,vector<int>&b) 
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        /*
        Algorithm

        1. Sort the array using the Number of units occupied
        2. Check the number of boxes to be taken inside and substract that from the truckSize
        3. Calculate the units by - no. of units * no of boxes taken
        4. Stop when truckSize becomes less than 0


        */
        int res=0; // no of units
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int w=0; // no of box to pick of a specific unit
        int i=0; 
        
        while(truckSize>0 && i<boxTypes.size())
        {
            w=min(truckSize,boxTypes[i][0]); // easier way 
            res+=w*boxTypes[i][1]; 
            i++;
            truckSize-=w;

        }
        return res;
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