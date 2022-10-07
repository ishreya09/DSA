/*
2085. Count Common Words With One Occurrence
Easy

https://leetcode.com/problems/count-common-words-with-one-occurrence/

Given two string arrays words1 and words2, return the number of strings that appear exactly once in each of the two arrays.

 

Example 1:

Input: words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
Output: 2
Explanation:
- "leetcode" appears exactly once in each of the two arrays. We count this string.
- "amazing" appears exactly once in each of the two arrays. We count this string.
- "is" appears in each of the two arrays, but there are 2 occurrences of it in words1. We do not count this string.
- "as" appears once in words1, but does not appear in words2. We do not count this string.
Thus, there are 2 strings that appear exactly once in each of the two arrays.
Example 2:

Input: words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
Output: 0
Explanation: There are no strings that appear in each of the two arrays.
Example 3:

Input: words1 = ["a","ab"], words2 = ["a","a","a","ab"]
Output: 1
Explanation: The only string that appears exactly once in each of the two arrays is "ab".
 

Constraints:

1 <= words1.length, words2.length <= 1000
1 <= words1[i].length, words2[j].length <= 30
words1[i] and words2[j] consists only of lowercase English letters.

*/

/*
Algorithm

1. Add first array in one map and other array in other map
2. count if map's frequency is 1 and another map's frequency is same and value is same
3. increment a1 and b1 wrt to which is smaller.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWords(vector<string>& nums1, vector<string>& nums2) {
        map <string,int> a;
        map <string,int> b;
        for (int i=0;i<nums1.size();i++){
            a[nums1[i]]++;
        }
        for (int i=0;i<nums2.size();i++){
            b[nums2[i]]++;
        }
        int count=0;
        
        auto a1=a.begin();
        auto b1=b.begin();
        
        while (a1!=a.end() && b1!= b.end()){
            if (a1->first == b1->first && a1->second==1 && b1->second==1){
                count++;
                a1++;
                b1++;
            }
            else if(a1->first> b1->first ){
                b1++;
            }
            else{
                a1++;
            }
        }
        
        return count;
    }
};