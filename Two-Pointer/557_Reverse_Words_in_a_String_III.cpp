/*
557. Reverse Words in a String III
Easy

https://leetcode.com/problems/reverse-words-in-a-string-iii/

Given a string s, reverse the order of characters in each word within a sentence while 
still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"
 

Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.

*/

/*
Algorithm

1. Split all the words using istringstream
(istringstream gives Time complexity : O(n) and Auxiliary Space : O(n))

2. use two pointer method on each word to reverse the word and add the word to ans.


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // all words are seperated by a single space
        
        // Used to split string around spaces.
        istringstream ss(s);
        
        string word; // for storing each word
 
        // Traverse through all words
        // while loop till we get
        // strings to store in string word
        string ans="";
        while (ss >> word)
        {
            // print the read word
            int i=0;
            int j= word.length()-1;
            while(i<j){
                char t= word[i];
                word[i]=word[j];
                word[j]=t;
                i++;
                j--;
            }
            ans+=word+" ";
        }
        
        // to remove the last space
        ans.pop_back();
        
        return ans;
    }
};


class Solution2 {
public:
    string reverseWords(string s) {
        // all words are seperated by a single space
        string ans;
        
        int i=0;
        int j= s.length()-1;
        
        while(i<j){
            char t= s[i];
            s[i]=s[j];
            s[j]=t;
            i++;
            j--;
        }
        
        istringstream ss(s);
        string word;
        while(ss >> word){
            ans= word+" "+ans;
        }
        
        // removing the last space
        ans.pop_back();
        
        return ans;
    }
};