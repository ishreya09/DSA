/*


*/

/*
Algorithm

1. Happy number will result in 1, but unhappy no. will not and will lead to infinite loop
2. So we make a set which keeps a track of all the values which we have encountered and if there is 
any time we insert the same number back into the set, we break from the loop.
3. once we are out of loop, we check if number is equal to 1 or not.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int squareNum(int n){
        if (n==0){
            return 0;
        }
        else{
            return ((n%10)*(n%10)) + squareNum(n/10); 
        }
    }
    bool isHappy(int n) {
        set<int> a;
        while(n!=1){
            n=squareNum(n);
            auto it= a.emplace(n); // emplace checks and then create a block
            if(!it.second) // element already exists
                break;
        }
        return n==1;
    }
};