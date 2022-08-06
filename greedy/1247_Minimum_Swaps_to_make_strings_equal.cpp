/*
1247. Minimum Swaps to Make Strings Equal
Medium

https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/

You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only. Your task is to make these two strings equal to each other. You can swap any two characters that belong to different strings, which means: swap s1[i] and s2[j].

Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.



Example 1:

Input: s1 = "xx", s2 = "yy"
Output: 1
Explanation: Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".
Example 2:

Input: s1 = "xy", s2 = "yx"
Output: 2
Explanation: Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
Note that you cannot swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.
Example 3:

Input: s1 = "xx", s2 = "xy"
Output: -1


Constraints:

1 <= s1.length, s2.length <= 1000
s1, s2 only contain 'x' or 'y'.

*/
/*
Algorithm -



    1.  Intuition -> xx _ It will give value 1 for making same 
                     yy
        
        xy _ it will require 2 value
        yx
		
		So make pairs of xx & yy it will require 1 swaps 
		
	2.	Now it may happen there is unpaired x & y -> if there is 1 unpaired x & y it will require 2 swaps
    
	3.	But if there is one unpaired x or 1 unpaired y , then return -1 , as there is no pairing 

*/


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    
int minimumSwap(string s1, string s2) {
        
        int n1=s1.size();
        int n2=s2.size();
        
        if(n1!=n2)
        {
            return -1;
        }
		
        int countx=0;
        int county=0;
        
        for(int i=0;i<n1;i++)
        {
            if(s1[i]!=s2[i])
            {
                if(s1[i]=='x')
                {
                    countx++;
                }
                else
                {
                    county++;
                }
            }
        }
        
        int ans=0;
        
        int remx=countx%2;
        int remy=county%2;
        
        ans=countx/2 + county/2;
        
        if((remx+remy)==2)
        {
            ans+=2;
        }
        
        if((remx+remy)==1)
        {
            return -1;
        }
        
        return ans;

    }
};
