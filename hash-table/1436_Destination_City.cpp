/*
1436. Destination City
Easy

https://leetcode.com/problems/destination-city/

You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. 
Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

 

Example 1:

Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo" 
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: 
"London" -> "New York" -> "Lima" -> "Sao Paulo".
Example 2:

Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are: 
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
Clearly the destination city is "A".
Example 3:

Input: paths = [["A","Z"]]
Output: "Z"
 

Constraints:

1 <= paths.length <= 100
paths[i].length == 2
1 <= cityAi.length, cityBi.length <= 10
cityAi != cityBi
All strings consist of lowercase and uppercase English letters and the space character.

*/

/*
Algorithm

1. Store the arival and destination as pairs in map and traverse the first element nd map it.
2. Eventually, you will reach a city with no path outgoing, this is the destination city. 
If u encounter f[i] as null string - then we return the i there.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // the destination city will have freq only once
        // so can be the arrival city
        map<string,string> f;
        for (int i=0; i<paths.size();i++){
            f[paths[i][0]]=paths[i][1];
        }
        auto i= f.begin()->first;
        while(true){
            if(f[i].size()){
                i= f[i];
            }
            else{
                return i;
            }
        }
        return "\0";
    }
};
