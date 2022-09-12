#include <bits/stdc++.h>
using namespace std;

bool static isPalindrome(string s){
        // using constructor method to reverse the string
        string rev= string(s.rbegin(),s.rend());
        // rend () = This function returns a reverse iterator pointing at the end of the string.
        // rbegin() =This function returns a reverse iterator pointing at beginning of the string.   
        return rev == s;
}