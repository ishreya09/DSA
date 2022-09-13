/*
692. Top K Frequent Words
Medium

https://leetcode.com/problems/top-k-frequent-words/

Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same 
frequency by their lexicographical order.

 

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 

Constraints:

1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]
 

Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
*/

/*
Algorithm 

1. create a struct ele to compare and sort the priority queue according to given conditions as above
2. We create a map and get the tract of frequency
3. we store this map into the priority queue and then pop out k elements and add into another vector(ans)
4. return the ans

*/

#include<bits/stdc++.h>
using namespace std;

struct ele { // doubts to ask
    constexpr bool operator()(
    pair<int, string> const& x,
    pair<int, string> const& y)
    const noexcept
    {
        return (x.first==y.first)? x.second>y.second : x.first<y.first; // need more clarity here
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> f; //frequency
        for(int i=0;i<words.size();i++){
            f[words[i]]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,ele> p;
        for (auto i=f.begin();i!=f.end();i++){
            p.push(make_pair(i->second,i->first));
        }
        vector<string> ans;
        while (k-- && !p.empty()){
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};