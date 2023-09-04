/*
1881. Maximum Value after Insertion
Medium

https://leetcode.com/problems/maximum-value-after-insertion/

You are given a very large integer n, represented as a string,​​​​​​ and an integer digit x. 
The digits in n and the digit x are in the inclusive range [1, 9], and n may represent a negative number.

You want to maximize n's numerical value by inserting x anywhere in the decimal representation of n​​​​​​. 
You cannot insert x to the left of the negative sign.

For example, if n = 73 and x = 6, it would be best to insert it between 7 and 3, making n = 763.
If n = -55 and x = 2, it would be best to insert it before the first 5, making n = -255.
Return a string representing the maximum value of n​​​​​​ after the insertion.

 

Example 1:

Input: n = "99", x = 9
Output: "999"
Explanation: The result is the same regardless of where you insert 9.
Example 2:

Input: n = "-13", x = 2
Output: "-123"
Explanation: You can make n one of {-213, -123, -132}, and the largest of those three is -123.
 

Constraints:

1 <= n.length <= 105
1 <= x <= 9
The digits in n​​​ are in the range [1, 9].
n is a valid representation of an integer.
In the case of a negative n,​​​​​​ it will begin with '-'.

*/

/*
Algorithm

1. Check if the number is negative or positive
2. If the number is positive, the position to add x will be when n[i]<x
3. If the number is negative, the position to add x will be when n[i]>x
4. Use stl insert function for string to insert x at index i.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maxValue(string n, int x) {
        int i=0;
        bool negative=false;
        int k=0;
        if (n[i]=='-'){
            i=1;
            negative=true;
        }
        
        while (i<n.length()){
            if (n[i] < x+'0' && negative==false){
                k=i;
                break;
            }
            if (n[i] > x+'0' && negative==true){
                k=i;
                break;
            }
            i++;
            
        }
        string s;
        s.push_back('0'+x);
        n.insert (i, s);
        
        return n;
            
    }
};

int main(int argc, char const *argv[])
{
    string s="74";
    int x=6;
    cout<<Solution().maxValue(s,x);
    return 0;
}



class Solution {
public:
    string maxValue(string n, int x) {
        int i=0;
        bool negative=false;
        if (n[i]=='-'){
            i=1;
            negative=true;
        }
        string s;
        s.push_back('0'+x);
        
        while (i<n.length()){
            if (n[i] < x+'0' && negative==false){
                break;
            }
            if (n[i] > x+'0' && negative==true){  
                break;
            }
            i++;
        }        
        n.insert (i, s);
        return n;
            
    }
};

