/*
948. Bag of Tokens
Medium

https://leetcode.com/problems/bag-of-tokens/

You have an initial power of power, an initial score of 0, and a bag of tokens where tokens[i] is the value of the ith token (0-indexed).

Your goal is to maximize your total score by potentially playing each token in one of two ways:

If your current power is at least tokens[i], you may play the ith token face up, losing tokens[i] power and gaining 1 score.
If your current score is at least 1, you may play the ith token face down, gaining tokens[i] power and losing 1 score.
Each token may be played at most once and in any order. You do not have to play all the tokens.

Return the largest possible score you can achieve after playing any number of tokens.

 

Example 1:

Input: tokens = [100], power = 50
Output: 0
Explanation: Playing the only token in the bag is impossible because you either have too little power or too little score.
Example 2:

Input: tokens = [100,200], power = 150
Output: 1
Explanation: Play the 0th token (100) face up, your power becomes 50 and score becomes 1.
There is no need to play the 1st token since you cannot play it face up to add to your score.
Example 3:

Input: tokens = [100,200,300,400], power = 200
Output: 2
Explanation: Play the tokens in this order to get a score of 2:
1. Play the 0th token (100) face up, your power becomes 100 and score becomes 1.
2. Play the 3rd token (400) face down, your power becomes 500 and score becomes 0.
3. Play the 1st token (200) face up, your power becomes 300 and score becomes 1.
4. Play the 2nd token (300) face up, your power becomes 0 and score becomes 2.
 

Constraints:

0 <= tokens.length <= 1000
0 <= tokens[i], power < 104

*/

/*
Algorithm

1. If array size is 0, return 0
2. Sort the tokens vector and use 2 pointer approach using i and j as 0 and tokens.size()-1
3. Now set in for conditions where score==0 and power<tokens[0] - return 0 directly
4. if (score==0 && power>=tokens[i]), increment i and score and decrease power. Do the same 
when score==1 and power>tokens[i]
5. When score>0 && power<tokens[i] then check if the sum of power+tokens[j] is greater than tokens[i] or not, if not, 
then there's no use for decrementing our score, if true, then decrement j and increment i and make 
power+= power[j]-power[i]

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()<=0){
            return 0;
        }
        
        sort(tokens.begin(),tokens.end());
        int j= tokens.size()-1;
        int i=0;
        int score=0;
        
        if(score==0 && power<tokens[0]){
            return 0;
        }
        
        while(i<=j){
            if (score==0 && power>=tokens[i]){
                score++;
                power= power-tokens[i];
                i++;
            }
            else if(score>0 && power>=tokens[i]){
                score++;
                power=power-tokens[i];
                i++;
            }
            else if(score>0 && power<tokens[i]){
                if (power+tokens[j]>= tokens[i]){
                    power=power+tokens[j];
                    j--;
                    power=power-tokens[i];
                    i++;
                    
                }
                
            }
        }
        return score;
    }
};