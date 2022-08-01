// 680. Valid Palindrome II
/*
Easy

https://leetcode.com/problems/valid-palindrome-ii/

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.


*/

// Runtime: 85 ms, faster than 45.52% of C++ online submissions for Valid Palindrome II.
// Memory Usage: 19.5 MB, less than 96.08% of C++ online submissions for Valid Palindrome II.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPalindrome(string &s,int l,int r){
        while(l<r){
            if(s[l]!=s[r])
                return false;
            l++,r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        /*
        Algorithm
        
        We can at most delete one character for the string to make it palindrome, so directly return there
        
        1. Make a function to check Palindrome string within a range
        2. Traverse through the string from the start and the end (Two Pointer) and check if they are equal or not 
        3. If they are equal, do start ++, and end --
        4. If they are not equal, check for palindrome at by skipping and check from start +1  to end
        or check for palindrome by skiping and check from start to end -1
        5. Instead of using start and end- go with i and n 
        
        */
        int  i=0;
        // auto start= s.begin();
        int n= s.length();
        if (checkPalindrome(s,0,n-1)){
            return true;
        }

        while(i<n-i-1)
        {
            if (s[i] != s[n-i-1])
            {
                return checkPalindrome(s,i+1,n-i-1) || checkPalindrome(s, i,n-i-2); 
            }
            i++;
            
        }       
    }
};

int main(int argc, char const *argv[])
{
    string s= "eeccccbebaeeabebccceea";
    s= "abbca";
    s="aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    // s= "ebcbbececabbacecbbcbe";
    Solution a;
    cout<< a.validPalindrome(s);
    return 0;
}

