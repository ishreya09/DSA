/*
609. Find Duplicate File in System
Medium

https://leetcode.com/problems/find-duplicate-file-in-system/description/

Given a list paths of directory info, including the directory path, and all the files with 
contents in this directory, return all the duplicate files in the file system in terms of their paths. 
You may return the answer in any order.

A group of duplicate files consists of at least two files that have the same content.

A single directory info string in the input list has the following format:

"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
It means there are n files (f1.txt, f2.txt ... fn.txt) with content (f1_content, f2_content ... fn_content) 
respectively in the directory "root/d1/d2/.../dm". Note that n >= 1 and m >= 0. If m = 0, it means the directory 
is just the root directory.

The output is a list of groups of duplicate file paths. For each group, it contains all the file paths of the 
files that have the same content. A file path is a string that has the following format:

"directory_path/file_name.txt"
 

Example 1:

Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
Output: [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
Example 2:

Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)"]
Output: [["root/a/2.txt","root/c/d/4.txt"],["root/a/1.txt","root/c/3.txt"]]
 

Constraints:

1 <= paths.length <= 2 * 104
1 <= paths[i].length <= 3000
1 <= sum(paths[i].length) <= 5 * 105
paths[i] consist of English letters, digits, '/', '.', '(', ')', and ' '.
You may assume no files or directories share the same name in the same directory.
You may assume each given directory info represents a unique directory. A single blank space separates 
the directory path and file info.


*/

/*
Algorithm

1. Create a split function which splits by character c
2. split each paths[i] by space first and then from index i to end of list - again split every string by '('
3. Now add the file content as key in map and append file path of that file content.
4. At last - if for a key, the vector's size is greater than 1 - then add it to ans.
5. Return ans

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> split(string s,char c){
        // split by char c
        s=s+c;
        vector<string> ans;
        int p=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==c){
                string t= s.substr(p,i-p);
                cout<<t<<"/"<<endl;
                ans.push_back(t);
                p=i+1;
            }
        }
        return ans;
    } 
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string,vector<string>> f;
        for(int i=0;i<paths.size();i++){
            vector<string> p=split(paths[i],' ');
            p[0]=p[0]+'/';
            for(int j=1;j<p.size();j++){
                vector<string> t=split(p[j],'(');
                f[t[1]].push_back(p[0]+t[0]);
            }
        }
        vector<vector<string>> ans;
        for (auto &i:f){
            if(i.second.size()>1)
                ans.push_back(i.second);
        }
        return ans;
    }
};