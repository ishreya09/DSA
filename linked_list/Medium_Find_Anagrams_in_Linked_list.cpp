/*
Find anagrams in linked list
Medium

https://practice.geeksforgeeks.org/problems/de6f6a196aecdfb3e4939ba7729809a5a4bdfe90/1?page=2&status[]=unsolved&status[]=attempted&category[]=Linked%20List&sortBy=submissions

Given a linked list of characters and a string S.Return all the anagrams of the string present 
in the given linked list.In case of overlapping anagrams choose the first anagram from left.

Example 1:

Input: a -> b -> c -> a -> d -> b -> c -> a
S = bac
Output: [a -> b -> c, b -> c -> a]
Explanation: In the given linked list,
there are three anagrams: 
1. a -> b -> c -> a -> d -> b -> c -> a
2. a -> b -> c -> a -> d -> b -> c -> a
3. a -> b -> c -> a -> d -> b -> c -> a
But in 1 and 2, a -> b -> c and b -> c-> a
are ovelapping.So we take a -> b -> c as it
comes first from left.So the output is:
[a->b->c,b->c->a]
Example 2:

Input: a -> b -> d -> c -> a
S = bac
Output: -1 
Explanation: There is no anagrams, so output is -1
Your Task:
You don't need to read input or print anything. Your task is to complete the function findAnagrams() 
which takes head node of the linked list and a string S as input parameters and returns an array of 
linked list which only stores starting point of the Anagram. If there is no anagram in the linked list, 
leave the Array empty.


Expected Time Complexity: O(N), where N is length of LinkedList
Expected Auxiliary Space: O(1)


Constraints:
1 <= N <= 105
1 <= |S| <= 105

 

*/

/*
Algorithm

Using the sliding window approach and map function to maintain the frequency of the string.
Traverse the linked list and check at each point whether it is an anagram or not. 

Steps involved in the implementation of code:

1. Create two maps and in one of them store the frequency of each character.
2. Start traversing the linked list. 
3. When we have traversed the length of string s. Check for an anagram is there or not.
4. If it is, move the head pointer to the end of the tail.
5. If not, move the head pointer by one step.
6. Clear the map at each step.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x){
        data =x;
        next = NULL;
    }
};


class Solution {
public:
    // Function to check whether sublink
    // list and are anagrams or not
    bool anagram(unordered_map<char, int>& smp,
                 unordered_map<char, int>& cmp)
    {
        if (smp.size() != cmp.size())
            return false;
        for (auto it : smp) {
            if (it.second != cmp[it.first]) {
                return false;
            }
        }
        return true;
    }
 
    // Function to find starting points
    // which are anagrams
    vector<Node*> findAnagrams(struct Node* head, string s)
    {
 
        // code here
        vector<Node*> ans;
        Node* prev = NULL;
        unordered_map<char, int> smp;
        unordered_map<char, int> cmp;
        struct Node* curr = head;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            smp[s[i]]++;
        }
        while (curr != NULL) {
            struct Node* temp = curr;
            for (int i = 0; i < n && temp != NULL; i++) {
                cmp[temp->data]++;
                prev = temp;
                temp = temp->next;
            }
            // If they both are anagrams
            // of each other
            if (anagram(smp, cmp)) {
                prev->next = NULL;
                ans.push_back(curr);
                curr = temp;
            }
            // If not
            else {
                curr = curr->next;
            }
            cmp.clear();
        }
        return ans;
    }
};

