/*
763. Partition Labels
Medium * #

https://leetcode.com/problems/partition-labels/


You are given a string s. We want to partition the string into as many parts as possible so that each
letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, 
the resultant string should be s.

Return a list of integers representing the size of these parts.



Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]


Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/
/*

Hint :
Try to greedily choose the smallest partition that includes the first letter.
If you have something like "abaccbdeffed", then you might need to add b.
You can use an map like "last['b'] = 5" to help you expand the width of your partition.

Algorithm:

1. Find the last position of each character using unordered map
2. we mark the start and the end and take it zero initially 
3. As we traverse through the string, compare the end with each character's last index in the string
4. When we do the above process, as we traverse through the string, we get our end at the index at 
the last character where we have to partition 
5. Store end-start+1 in the vector
6. We set the start to end +1 and and then again repeat the same while going ahead. 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int i=0;
        unordered_map <char,int> last;
        vector <int> ans;
        while (s[i]!=0){
            last[s[i]]= i; // adding the last character postion in the map
            i++;
        }
        int start=0, end =0; // marks the starting  and ending of a partition
        for (i=0; i<s.length();i++){  // ababcbacadefegdehijhklij
            end = max(end, last[s[i]]);
            if (i==end){
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s= "ababcbacadefegdehijhklij";
    Solution a;
    vector<int> p= a.partitionLabels(s);
    for (int i=0; i<p.size();i++){
        cout<< p[i]<< endl;
    }
    return 0;
}

