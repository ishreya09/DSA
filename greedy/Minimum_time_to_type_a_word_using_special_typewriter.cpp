/*
1974. Minimum Time to Type Word Using Special Typewriter
Easy

https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/

There is a special typewriter with lowercase English letters 'a' to 'z' arranged in a circle with a pointer.
A character can only be typed if the pointer is pointing to that character. The pointer is initially
pointing to the character 'a'.


Each second, you may perform one of the following operations:

Move the pointer one character counterclockwise or clockwise.
Type the character the pointer is currently on.
Given a string word, return the minimum number of seconds to type out the characters in word.



Example 1:

Input: word = "abc"
Output: 5
Explanation:
The characters are printed as follows:
- Type the character 'a' in 1 second since the pointer is initially on 'a'.
- Move the pointer clockwise to 'b' in 1 second.
- Type the character 'b' in 1 second.
- Move the pointer clockwise to 'c' in 1 second.
- Type the character 'c' in 1 second.
Example 2:

Input: word = "bza"
Output: 7
Explanation:
The characters are printed as follows:
- Move the pointer clockwise to 'b' in 1 second.
- Type the character 'b' in 1 second.
- Move the pointer counterclockwise to 'z' in 2 seconds.
- Type the character 'z' in 1 second.
- Move the pointer clockwise to 'a' in 1 second.
- Type the character 'a' in 1 second.
Example 3:

Input: word = "zjpc"
Output: 34
Explanation:
The characters are printed as follows:
- Move the pointer counterclockwise to 'z' in 1 second.
- Type the character 'z' in 1 second.
- Move the pointer clockwise to 'j' in 10 seconds.
- Type the character 'j' in 1 second.
- Move the pointer clockwise to 'p' in 6 seconds.
- Type the character 'p' in 1 second.
- Move the pointer counterclockwise to 'c' in 13 seconds.
- Type the character 'c' in 1 second.


Constraints:

1 <= word.length <= 100
word consists of lowercase English letters.

*/

// Runtime: 3 ms, faster than 44.26% of C++ online submissions for Minimum Time to Type Word Using Special Typewriter.
// Memory Usage: 6.1 MB, less than 85.69% of C++ online submissions for Minimum Time to Type Word Using Special Typewriter.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTimeToType(string word)
    {
        /*
        Algorithm

        1. Find the difference between the character at a pointer to the character we have to move towards to
        2. If the difference is less than 13- then we will add that many seconds directly and count one more second
        to type the character
        3. If the difference is greater than 13- then we will add (26- number ) seconds and then add one second
        to type the character
        4. Set the pointer to the current letter typed and check again
        */
        char p= 'a'; //pointer is pointing to a initially
        int t = 0; // time in seconds
        int d;
        for (int i=0; i< word.length();i++){
            d= p>=word[i] ? p- word[i] : word[i]-p; // keeping d positive all the time
            t += d <= 13 ? d : 26-d ; // seconds required to move to pointer
            t++; // to count typing second
            p= word[i]; // setting the pointer to the current word typed

        }
        return t;
    }
};



