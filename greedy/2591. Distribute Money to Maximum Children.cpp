/*
2591. Distribute Money to Maximum Children
Easy

https://leetcode.com/problems/distribute-money-to-maximum-children/description/

You are given an integer money denoting the amount of money (in dollars) that you have and another integer children denoting the number of children that you must distribute the money to.

You have to distribute the money according to the following rules:

All money must be distributed.
Everyone must receive at least 1 dollar.
Nobody receives 4 dollars.
Return the maximum number of children who may receive exactly 8 dollars if you distribute the money according to the aforementioned rules. If there is no way to distribute the money, return -1.

 

Example 1:

Input: money = 20, children = 3
Output: 1
Explanation: 
The maximum number of children with 8 dollars will be 1. One of the ways to distribute the money is:
- 8 dollars to the first child.
- 9 dollars to the second child. 
- 3 dollars to the third child.
It can be proven that no distribution exists such that number of children getting 8 dollars is greater than 1.
Example 2:

Input: money = 16, children = 2
Output: 2
Explanation: Each child can be given 8 dollars.
 

Constraints:

1 <= money <= 200
2 <= children <= 30


*/

/*
Algorithm

1. We distribute 1 dollar to every child 
we initalise ans to -1
and then distribute money/7 among children - if children>= money/7 - 
It can be divided among children in min (children,money/7)
We adjust children and money according to that  
2. If left money was 3 and only one child was left - that child will have 4 which is not allowed
so we decrement ans and give that child 1 dollar and rest to the present child

If left children is 0 and money is still left- we pick a child- decrement ans and give that one
child all the money as money>8 
3. If its none of these cases as step 2 - then we can say that we can find a way to distribute the money among all 
children according to the rules and we can return the ans.

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int distMoney(int money, int children) {
        if(money<children){
            return -1;
        }
        money-=children; // dirtribute 1 dollar among all children
        cout<<money<<" "<<money/7<<endl;

        int ans=-1;
        if(children>=money/7){
            ans=money/7;
            children=children-ans;
            money=money%7;
            cout<<ans<<" "<<children<<" "<<money<<endl;
        }
        else if(money/7>0){
            ans=min<int>(children,money/7); // if money/7>children - 
            // so children to be distributed money were zero, but money is still left
            children=children-ans;
            money= money- 7*ans;
            cout<<ans<<" "<<children<<" "<<money<<endl;
        }

        if(money==3 && children==1){ // 4 can't be given to any child
            ans--;// increment one 8 and return ans
        }
        else if(children==0 && money>0){ // all children already have 8 - so we do ans-- so that we give rest of the
        // money to one child 
            ans--; // give rest money to one child only
        }

        return ans;
    }
};

// accepted - just removed if statements wherever unnecessary
class Solution {
public:
    int distMoney(int money, int children) {
        if(money<children){
            return -1;
        }
        money-=children; // dirtribute 1 dollar among all children
        cout<<money<<" "<<money/7<<endl;

        int ans=-1;
        ans=min<int>(children,money/7);
        children=children-ans;
        money= money- 7*ans;
        cout<<ans<<" "<<children<<" "<<money<<endl;
        

        if(money==3 && children==1){
            ans--;// increment one 8 and return ans
        }
        else if(children==0 && money>0){
            ans--; // give rest money to one child only
        }

        return ans;
    }
};