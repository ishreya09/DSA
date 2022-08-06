/*
455. Assign Cookies
easy

https://leetcode.com/problems/assign-cookies/

Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at
most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with;
and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content.
Your goal is to maximize the number of your content children and output the maximum number.



Example 1:

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:

Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2.
You have 3 cookies and their sizes are big enough to gratify all of the children,
You need to output 2.


Constraints:

1 <= g.length <= 3 * 104
0 <= s.length <= 3 * 104
1 <= g[i], s[j] <= 231 - 1

*/
/*
        Algorithm
        1. Check the size of g and s- if its greater than 0, only then we proceed.
        2. Sort both g and s vectors
        3. Start checking simentanously for greed factor <= size of cookie (2 loops- one for g and one for s)
        4. the value of j need not be written as j=i or set to 0 as it while checking simentaneously, 
         the next child with greater greed would also need a greater j and also it would cause repitions in giving the cookie which we don't want
        

*/


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {

        if (g.size() == 0 or s.size() == 0)
        {
            return 0;
        }
        cout << g.size () <<"\t"<< s.size()<<endl;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());


        int j = 0, i = 0;
        int c = 0;
        bool f = true;
        while (f)
        {
            bool flag = true;
            // j=i;
            // the value of j need not be written as j=i or set to 0 as it while checking simentaneously, 
            // the next child with greater greed would also need a greater j and also it would cause repitions in giving the cookie which we don't want
            while (flag)
            {
                if (g[i] <= s[j])
                {
                    // cout<< "hello\n";
                    c++;
                    cout<< g[i]<< "\t"<< s[j]<<"\t"<< c << endl;
                    flag = false;
                }

                j++;
                if (j >= s.size())
                {
                    // cout<< g[i]<< "\t"<< s[j]<< endl;
                    flag = false;
                    f = false; // if we can't find the cookie for the current child with greed g[i]
                    // then we also can't find a match for rest of the children as well
                }
            }
            i++;
            if (i >= g.size())
            {
                f = false;
            }
        }

        return c;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    Solution a;
    cout << a.findContentChildren(g, s); // expected 70 but coming 73 for this test case
    return 0;
}
