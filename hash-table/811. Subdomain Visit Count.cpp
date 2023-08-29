/*
811. Subdomain Visit Count
Medium

https://leetcode.com/problems/subdomain-visit-count/description/

A website domain "discuss.leetcode.com" consists of various subdomains. 
At the top level, we have "com", at the next level, we have "leetcode.com" and
at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", 
we will also visit the parent domains "leetcode.com" and "com" implicitly.

A count-paired domain is a domain that has one of the two formats "rep d1.d2.d3" or "rep d1.d2" 
where rep is the number of visits to the domain and d1.d2.d3 is the domain itself.

For example, "9001 discuss.leetcode.com" is a count-paired domain that indicates that discuss.leetcode.com 
was visited 9001 times.
Given an array of count-paired domains cpdomains, return an array of the count-paired domains of each subdomain 
in the input. You may return the answer in any order.

 

Example 1:

Input: cpdomains = ["9001 discuss.leetcode.com"]
Output: ["9001 leetcode.com","9001 discuss.leetcode.com","9001 com"]
Explanation: We only have one website domain: "discuss.leetcode.com".
As discussed above, the subdomain "leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.
Example 2:

Input: cpdomains = ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
Output: ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
Explanation: We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times.
For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.
 

Constraints:

1 <= cpdomain.length <= 100
1 <= cpdomain[i].length <= 100
cpdomain[i] follows either the "repi d1i.d2i.d3i" format or the "repi d1i.d2i" format.
repi is an integer in the range [1, 104].
d1i, d2i, and d3i consist of lowercase English letters.
*/

/*
Algorithm

1. Write a func which removes till first dot in a string
2. Find the num from start of the string- then take substr after that and convert that num to integer
3. Now keep on removing till . and add in frequency of the string by adding the num calculated in step 2.
4. Once the map is completed- iterate through the map- covert integer num to string with a space and add the rest of 
subdomain string and add to ans.
5. Return ans

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string removeTillFirstDot(string s){
        int i=0;
        while(i<s.length() && s[i]!='.' ){
            i++;
        }
        i++;
        if(i>s.length()-1){
            return "";
        }
        string k=s.substr(i);
        // cout<<k<<endl;
        return k;
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string,int> f;
        for(int i=0;i<cpdomains.size();i++){
            int j=0;
            int k=0;
            while(cpdomains[i][j]!=' '){
                k=k*10+(cpdomains[i][j]-'0');
                j++;
            }
            // cout<<k<<endl;
            j++;
            string l= cpdomains[i].substr(j);
            while(removeTillFirstDot(l)!=""){
                f[l]+=k;
                // cout<<l<<endl;
                l=removeTillFirstDot(l);
            }
            if(l!=""){
                f[l]+=k;
                // cout<<l<<endl;
            }
        }
        vector<string> ans;
        for(auto &i:f){
            string count="";
            while(i.second!=0){
                int d=i.second%10;
                char n= '0'+d;
                count=n+count;
                i.second=i.second/10;
            }
            count+=' ';
            count+= i.first;
            cout<<count<<endl;
            ans.push_back(count);
        }
        return ans;

    }   
};