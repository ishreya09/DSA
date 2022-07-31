/*
605. Can Place Flowers

https://leetcode.com/problems/can-place-flowers/

Easy

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers
can be planted in the flowerbed without violating the no-adjacent-flowers rule.



Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false


Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length

*/

// Runtime: 39 ms, faster than 16.68% of C++ online submissions for Can Place Flowers.
// Memory Usage: 20.2 MB, less than 88.18% of C++ online submissions for Can Place Flowers.


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        /*
        Algorithm

        n is the number of new flowers
        and no two flowers cannot be planted in adjacent plots

        1. Since the flowerbed array is in 0 and 1, check the boundary conditions seprately
        2. If it has to be present in the starting of the vector, - check if flowerbed[0] ==0 and flowerbed [1] == 0 as well
        3. If it has to be planted in the middle, check the current to be zero and similarly , for the previous and the next.
        4. If it has to be planted in the end of the vector, check if the last element is zero (flowerbed [flowerbed.size()-1]==0) 
        and second last element is also zero
        5. Go in the same order as above
        6. Keep a check of n always so that it doesn't go below 0
        */

        // checking for the first position

        // cout << "initially \n"; 
        // for (int i=0;i<flowerbed.size();i++){
        //     for (int j=0;j<60; j++)
        //         cout << flowerbed[i++]<< " ";
        //     cout<< endl;
            
        // }

        if (n==0){
            return true;
        }
        if (flowerbed.size()==0 || (flowerbed.size()==1 && flowerbed[0]==1 && n>0) ){
            return false;
        }
        if ((flowerbed.size()==1 && flowerbed[0]==0)){
            flowerbed[0]=1;
            n--;
            cout << n <<endl;

        }
        
        // flowerbed array of size 2 can be taken care with this test case itself
        if (flowerbed[0]==0 && flowerbed[1]==0 && n>0){
            n--;
            cout << n <<endl;
            flowerbed[0]=1;
        }

        if (flowerbed.size() >= 3 && n!=0){
            // checking for middle element
            int i;
            for (i=1;i<flowerbed.size()-1; i++){
                if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0 && n>0){

                    n--;
                    cout << n <<endl;

                    flowerbed[i]= 1;
                }
            }
            // i already stores the last index 
            if (flowerbed[i]==0 && flowerbed[i-1]==0 && n>0){
                n--;
                cout << n <<endl;

                flowerbed[i]=1;
            }
        }

        cout << "n="<< n <<endl;
        // cout << "\nafter planting \n"; 

        // for (int i=0;i<flowerbed.size();i++){
        //     for (int j=0;j<60; j++)
        //         cout << flowerbed[i++]<< " ";
        //     cout<< endl;
        // }


        return n == 0; // n will be zero if all the flowers get ploted
    }
};


int main(int argc, char const *argv[])
{
    
    vector <int> fb={0,0,0,0,0};
    int n=2;

    fb = {0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1,
    0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,
    0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,
    1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,
    1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,
    0,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,
    1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,1,0,0,1,0,0,1,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,
    1,0,1,0,1,0,1,0,0,0,1,0,0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,1,0,
    0,1,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,1,0,1,0,
    1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,1,0,1,0,
    0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,0,
    0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0};
    n=25;
    Solution a;
    cout<<a.canPlaceFlowers(fb,n);
    return 0;
}

