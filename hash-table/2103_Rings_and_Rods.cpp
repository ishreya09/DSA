/*
2103. Rings and Rods
Easy

https://leetcode.com/problems/rings-and-rods/

There are n rings and each ring is either red, green, or blue. The rings are distributed across ten rods labeled from 0 to 9.

You are given a string rings of length 2n that describes the n rings that are placed onto the rods. 
Every two characters in rings forms a color-position pair that is used to describe each ring where:

The first character of the ith pair denotes the ith ring's color ('R', 'G', 'B').
The second character of the ith pair denotes the rod that the ith ring is placed on ('0' to '9').
For example, "R3G2B1" describes n == 3 rings: a red ring placed onto the rod labeled 3, a green ring 
placed onto the rod labeled 2, and a blue ring placed onto the rod labeled 1.

Return the number of rods that have all three colors of rings on them.

 

Example 1:


Input: rings = "B0B6G0R6R0R6G9"
Output: 1
Explanation: 
- The rod labeled 0 holds 3 rings with all colors: red, green, and blue.
- The rod labeled 6 holds 3 rings, but it only has red and blue.
- The rod labeled 9 holds only a green ring.
Thus, the number of rods with all three colors is 1.
Example 2:


Input: rings = "B0R0G0R9R0B0G0"
Output: 1
Explanation: 
- The rod labeled 0 holds 6 rings with all colors: red, green, and blue.
- The rod labeled 9 holds only a red ring.
Thus, the number of rods with all three colors is 1.
Example 3:

Input: rings = "G4"
Output: 0
Explanation: 
Only one ring is given. Thus, no rods have all three colors.
 

Constraints:

rings.length == 2 * n
1 <= n <= 100
rings[i] where i is even is either 'R', 'G', or 'B' (0-indexed).
rings[i] where i is odd is a digit from '0' to '9' (0-indexed).


*/

/*
Algorithm

1. Make a struct of red, blue and green and default the values to 0
2. Make the values of respective color as one if u get the color in the a particular rod no. 
Implement the above using map
3. Traverse through the map and check if all the colors are present or not and add 1 to it.

*/

#include<bits/stdc++.h>
using namespace std;

struct Rods{
    int red=0;
    int blue=0;
    int green=0;
};

class Solution {
public:
    int countPoints(string rings) {
        map<char,Rods> f;
        for (int i=1; i<rings.size();i++){
            if (rings[i-1]=='R')
                f[rings[i]].red=1;
            if (rings[i-1]=='G')
                f[rings[i]].green=1;
            if (rings[i-1]=='B')
                f[rings[i]].blue=1;

            i++;
        }
        
        int count=0;
        for (auto i=f.begin();i!=f.end();i++){
            if (i->second.red ==1 && i->second.blue==1 && i->second.green==1){
                count++;
            }
        }
        
        return count;
    }
};
