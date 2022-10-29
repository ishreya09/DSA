/*
Palindrome Sentence 
Easy

https://practice.geeksforgeeks.org/problems/string-palindromic-ignoring-spaces4723/1?page=1&difficulty[]=0&category[]=two-pointer-algorithm&sortBy=submissions


Given a single sentence s, check if it is a palindrome or not. Ignore white spaces and any 
other character you may encounter. 

Example 1:

Input:
s = race car.
Output: 1 
Explanation: processing str gives us
"racecar" which is a palindrome.

Example 2:

Input:
s = hello world.
Output: 0
Explanation: processing str gives us
"helloworld" which is not a palindrome.

Your Task:  
You dont need to read input or print anything. Complete the function sentencePalindrome() which 
takes a string s as input parameter and returns a boolean value denoting if sentence is a palindrome or not.

Note: The driver code prints 1 if the returned value is true, otherwise 0.


Expected Time Complexity: O(N) where N is length of s.
Expected Auxiliary Space: O(1)


Constraints:
1<= s.length() <= 104
All the alphabets used in the sentence are in lower case.

*/

/*
Algorithm

1. Use isalpha to check if the character is a alphabet or not.
2. Use two pointers- one at start and one at end of the string
and compare the alphabets.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
	bool sentencePalindrome(string s) 
	{
	    // code here 
	    int i=0; 
	    int j=s.length()-1;
	    while (i<j){
	        if(!isalpha(s[i])){
	            i++;
	            continue;
	        }
	        if(!isalpha(s[j])){
	            j--;
	            continue;
	        }
	        if (s[i]!=s[j]){
	           // cout << s[i]<< s[j]<<endl;
	            return false;
	        }
	        else{
	           // cout << s[i]<< s[j]<<endl;
	            i++;
	            j--;
	        }
	    }
	    return true;
	}
};