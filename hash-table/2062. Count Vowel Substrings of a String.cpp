/*
2062. Count Vowel Substrings of a String
Easy

https://leetcode.com/problems/count-vowel-substrings-of-a-string/description/

A substring is a contiguous (non-empty) sequence of characters within a string.

A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') 
and has all five vowels present in it.

Given a string word, return the number of vowel substrings in word.

 

Example 1:

Input: word = "aeiouu"
Output: 2
Explanation: The vowel substrings of word are as follows (underlined):
- "aeiouu"
- "aeiouu"
Example 2:

Input: word = "unicornarihan"
Output: 0
Explanation: Not all 5 vowels are present, so there are no vowel substrings.
Example 3:

Input: word = "cuaieuouac"
Output: 7
Explanation: The vowel substrings of word are as follows (underlined):
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
 

Constraints:

1 <= word.length <= 100
word consists of lowercase English letters only.

*/

/*
Algorithm

I'm  maintaing a hashmap to map a vowel to it's frequency and a count variable for 
the number of vowels in a particular sub string
My intuition is that as a substring must contain only all the vowels with no consonants 
and for a substring (j,i) containing only vowels,if first prefix vowels are also present 
in (j+prefix,i) then 1+prefix number of substrings are valid substrings to our given asked condition

Whenever I encounter a consonant ,I make the values of count,prefix to be zero and clearing the 
hashmap thereby conveying the idea that we need to start again fresh to find the required substrings 
containing only vowels

*/

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int countVowelSubstrings(string word) {
        
        unordered_map<char,int>m;
        int n=word.size();
        int ans=0;
        
        for(int i=0,cnt=0,j=0,pref=0;i<n;i++){
            if((word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'))
            {
                if(m[word[i]]++==0)
                     cnt++;
                
                while(m[word[j]]>1)
				m[word[j++]]--,pref++;
                
            if(cnt==5)ans+=(1+pref);
            }
            else{
               
               cnt=0;
               pref=0;
               m.clear();
               j=i+1;
            }
                   
            
            
        }
        return ans;
    }
};

