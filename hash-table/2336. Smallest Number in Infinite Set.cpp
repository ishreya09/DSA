/*
2336. Smallest Number in Infinite Set
Medium

https://leetcode.com/problems/smallest-number-in-infinite-set/description/

You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

Implement the SmallestInfiniteSet class:

SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
int popSmallest() Removes and returns the smallest integer contained in the infinite set.
void addBack(int num) Adds a positive integer num back into the infinite set, if it is 
not already in the infinite set.
 

Example 1:

Input
["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
[[], [2], [], [], [], [1], [], [], []]
Output
[null, null, 1, 2, 3, null, 1, 4, 5]

Explanation
SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
smallestInfiniteSet.addBack(2);    // 2 is already in the set, so no change is made.
smallestInfiniteSet.popSmallest(); // return 1, since 1 is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 2, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 3, and remove it from the set.
smallestInfiniteSet.addBack(1);    // 1 is added back to the set.
smallestInfiniteSet.popSmallest(); // return 1, since 1 was added back to the set and
                                   // is the smallest number, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 4, and remove it from the set.
smallestInfiniteSet.popSmallest(); // return 5, and remove it from the set.
 

Constraints:

1 <= num <= 1000
At most 1000 calls will be made in total to popSmallest and addBack.

*/

/*
Algorithm

1. Take a start and a set for removed numbers. initialize set as clear and start to 1
2. Add all the poped elements in r and find the next start which is not present in r
3. For adding back - update start if num<start and remove that num from set r

*/

#include<bits/stdc++.h>
using namespace std;


class SmallestInfiniteSet {
public:
    int start;
    set<int> r; // removed numbers
    SmallestInfiniteSet() {
        start=1;
        r.clear();
    }
    
    int popSmallest() {
        int k=start;
        r.insert(k);
        while(r.find(start+1)!=r.end()){// its present in r
            start=start+1;
        }
        start=start+1; // to set to the correct start
        return k;

    }
    
    void addBack(int num) {
        if(r.empty() || r.find(num)==r.end()){ // already present in infinite set
            return;
        }

        if(num<start){
            start=num;
            r.erase(num);
        }
        else{
            r.erase(num); // remove from the removed number list
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */


class SmallestInfiniteSet {
public:
    int x = 1;
    set<int> s;
    SmallestInfiniteSet() {
        x = 1;
        s.clear();
    }
    
    int popSmallest() {
        if(s.empty()){
            return x++;
        }
        int y = *s.begin();
        s.erase(y);
        return y;
    }
    
    void addBack(int num) {
        if(num<x){
            s.insert(num);
        }
    }
};