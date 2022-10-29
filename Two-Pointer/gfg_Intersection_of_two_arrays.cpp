/*
Intersection of two arrays
Easy

https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1?page=1&difficulty[]=0&category[]=two-pointer-algorithm&sortBy=submissions

Given two arrays a[] and b[] respectively of size n and m, the task is to print the count of elements 
in the intersection (or common elements) of the two arrays.

For this question, the intersection of two arrays can be defined as the set containing distinct common 
elements between the two arrays. 

Example 1:

Input:
n = 5, m = 3
a[] = {89, 24, 75, 11, 23}
b[] = {89, 2, 4}

Output: 1

Explanation: 
89 is the only element 
in the intersection of two arrays.
Example 2:

Input:
n = 6, m = 5
a[] = {1, 2, 3, 4, 5, 6}
b[] = {3, 4, 5, 6, 7} 

Output: 4

Explanation: 
3 4 5 and 6 are the elements 
in the intersection of two arrays.
Your Task:
You don't need to read input or print anything. Your task is to complete the function NumberofElementsInIntersection() 
which takes two integers n and m and their respective arrays a[] and b[]  as input. The function should return the 
count of the number of elements in the intersection.

 

Expected Time Complexity: O(n + m).
Expected Auxiliary Space: O(min(n,m)).

Constraints:
1 ≤ n, m ≤ 105
1 ≤ a[i], b[i] ≤ 105
*/

/*
Algorithm

1. Create a hashmap of an array with minimum number of elements
2. Make sure that frequecy of any element is treated as 1 in the smaller array
3. Iterate through the another array and check through the map if the element exists and increase the freq
of that element (for counting only distinct elements)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        int i=0;
        int j=0;
        int count =0;
        map<int,int> f;
        if (n<m){
            for (int i=0;i<n;i++){
                if (f[a[i]]==0)
                    f[a[i]]++;
            }
            for(int i =0; i<m; i++){
                if (f[b[i]]==1){
                    f[b[i]]++;
                    count++;
                }
            }
        }
        else{
            for (int i=0;i<m;i++){
                if (f[b[i]]==0){
                    f[b[i]]++;
                }
            }
            for(int i =0; i<n; i++){
                if (f[a[i]]==1){
                    count++;
                    f[a[i]]++;
                }
            }
        }
        return count;
    }
};