/*
Smallest window containing 0, 1 and 2
Easy

https://practice.geeksforgeeks.org/problems/d6e88f06b273a60ae83992314ac514f71841a27d/1?page=1&difficulty[]=0&category[]=two-pointer-algorithm&sortBy=submissions

Given a string S consisting of the characters 0, 1 and 2. Your task is to find the length of the smallest 
substring of string S that contains all the three characters 0, 1 and 2. If no such substring exists, then return -1.

Example 1:

Input:
S = "01212"
Output:
3
Explanation:
The substring 012 is the smallest substring
that contains the characters 0, 1 and 2.
Example 2:

Input: 
S = "12121"
Output:
-1
Explanation: 
As the character 0 is not present in the
string S, therefor no substring containing
all the three characters 0, 1 and 2
exists. Hence, the answer is -1 in this case.
Your Task:
Complete the function smallestSubstring() which takes the string S as input, and returns the length of the 
smallest substring of string S that contains all the three characters 0, 1 and 2.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ |S| ≤ 105
All the characters of String S lies in the set {'0', '1', '2'}

*/

/*
Algorithm

1. Initialise the index val of 0,1,2 as -1. Update the index as we encounter one.
2. Once the minimum of the three is not -1 , we find the max value - min value among the three
3. This way we return the min value of length of substring in O(n) Time COmplexity.

*/

#include<bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int one=-1;
        int zero =-1;
        int two= -1;
        int len=S.length();
        bool flag=false;
        for (int i=0;i<S.length();i++){
            if (S[i]=='0'){
                zero= i;
            }
            else if(S[i]=='1'){
                one=i;
            }
            else if(S[i]=='2'){
                two=i;
            }
            int minimum=min<int>(zero,one);
            int maximum= max<int>(zero,one);
            if(min<int>(minimum,two)!=-1){
                len = min<int>(len,max<int>(maximum,two)- min<int>(minimum,two)+1);
                flag=true;
            }
            
        }
        
        
        if (flag){
            return len;
        }
        else 
            return -1;
    }
};