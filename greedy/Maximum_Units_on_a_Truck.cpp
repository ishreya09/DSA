/*
1710. Maximum Units on a Truck
EASY

https://leetcode.com/problems/maximum-units-on-a-truck/


You are assigned to put some amount of boxes onto one truck.
You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck.
You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.

Example 1:

Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
Example 2:

Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91


Constraints:

1 <= boxTypes.length <= 1000
1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
1 <= truckSize <= 106
*/
/*
        Algorithm
        1. sort the 2D array with respect to units per box
        2. Start taking the boxes and multiply it by its units until we reach the maximum
        number of boxes
*/


        /*
        Algorithm

        1. Sort the array using the Number of units occupied
        2. Check the number of boxes to be taken inside and substract that from the truckSize
        3. Calculate the units by - no. of units * no of boxes taken
        4. Stop when truckSize becomes less than 0


        */


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