/*
914. X of a Kind in a Deck of Cards
Easy

https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/

You are given an integer array deck where deck[i] represents the number written on the ith card.

Partition the cards into one or more groups such that:

Each group has exactly x cards where x > 1, and
All the cards in one group have the same integer written on them.
Return true if such partition is possible, or false otherwise.

 

Example 1:

Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
Example 2:

Input: deck = [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.
 

Constraints:

1 <= deck.length <= 104
0 <= deck[i] < 104


*/

/*
Algorithm

1. if deck.size()<0 - return false as group of X cards where x>1 cannot be formed
2. Create a map with key as deck[i] and value as its frequency
3. Iterate through the map and keep n as f[deck[0]]. Now there are 2 conditions
a) If map's value%n !=0 - then calculate gcd of n and value (v) 
if v%n ==0 then we can directly continue for next iter
else if gcd is not 1 and v%gcd(n,v)==0 - then update n to gcd(n,v) and continue to next iteration
If both are false - then return false.
b) Check if v<2 as group of x can only contain cards with x>1
4. If all the above conditions are satisfied throughout the map- return true

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int gcd(int a,int b){
        if (b == 0) {
            return a;
        } 
        else {
            return gcd(b, a % b);
        }
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size()<=1){
            return 0;
        }
        map<int,int> f;
        for(auto i:deck){
            f[i]++;
        }
        int n= f[deck[0]];
        for(auto [k,v]:f){
            if(n!= v){
                int g=gcd(v,n);
                if(v%n==0){
                    continue;
                }
                else if(g!=1 && v%g==0){
                    n=g;
                    continue;
                }
                return false;
            }
            if( v<2){
                return false;
            }
        }
        return true;
    }
};