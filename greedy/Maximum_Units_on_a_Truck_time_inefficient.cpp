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

#include <bits/stdc++.h>
using namespace std;






// Runtime: 723 ms, faster than 5.04% of C++ online submissions for Maximum Units on a Truck.
// Memory Usage: 16 MB, less than 50.71% of C++ online submissions for Maximum Units on a Truck.

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        // way to accept 2D vector (dynamic Array)

        /*
        Algorithm
        1. sort the 2D array with respect to units per box
        2. Start taking the boxes and multiply it by its units until we reach the maximum
        number of boxes
        */

        // Sorting using Selection Sort in decending order
        int max;
        int nBox, nUnit;

        for (int i = 0; i < boxTypes.size(); i++)
        {
            max = i;
            for (int j = i + 1; j < boxTypes.size(); j++)
            {
                if (boxTypes[j][1] > boxTypes[max][1])
                    max = j;
            }

            if (max != i)
            {
                // swap logic
                nBox = boxTypes[max][0];
                nUnit = boxTypes[max][1];
                boxTypes[max][0] = boxTypes[i][0];
                boxTypes[max][1] = boxTypes[i][1];
                boxTypes[i][0] = nBox;
                boxTypes[i][1] = nUnit;
            }
        }

        nUnit = 0; // to store the number of units here
        nBox = 0;
        max = 0;
        int i = 0;
        /*
        while (nBox <= truckSize)
        {

            // some logical error in max
            cout << nBox + boxTypes[i][0] << "\t" << boxTypes[i][0] << "\t" << truckSize - nBox << "\n";
            // max= boxTypes[i][0] ? (nBox+boxTypes[i][0]) <= truckSize  : (truckSize-nBox);

            if (truckSize == nBox)
            {
                max = 0;
            }
            else if (nBox + boxTypes[i][0] <= truckSize)
            {
                max= boxTypes[i][0];
            }
            else
            {
                max = truckSize - nBox;
                
            }

            cout << "max = " << max << endl;
            // number of box required of a specific unit
            nBox = nBox + max;
            nUnit += max * boxTypes[i][1];
            cout << i << "\t" << max << "\t" << nBox << "\t" << max * boxTypes[i][1] << "\t" << nUnit << "\n";
            i++;
        }
        */


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