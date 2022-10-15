/*
832. Flipping an Image
Easy

https://leetcode.com/problems/flipping-an-image/

Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.

For example, flipping [1,1,0] horizontally results in [0,1,1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.

For example, inverting [0,1,1] results in [1,0,0].
 

Example 1:

Input: image = [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 

Constraints:

n == image.length
n == image[i].length
1 <= n <= 20
images[i][j] is either 0 or 1.

*/

/*
Algorithm

1. Traverse through the array and use two pointers for traversing the inner array
2. Also if j is even (length -1 of the array) then the middle element needs to be toggled as 
two pointer method will skip that step
3. For rest, first toggle the values in the image[i] and then swap the places.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (int i=0;i<image.size();i++){
            int it=0;
            int j=image[i].size()-1;
            if (j%2==0){
                // if the array is odd - then toggle the middle element
                int mid=(it+j)/2;
                image[i][mid]=!image[i][mid];
            }
            while(it<j){
                image[i][it]=!image[i][it];
                image[i][j]=!image[i][j];
                
                //swap
                int k=image[i][j];
                image[i][j]=image[i][it];
                image[i][it]=k;
                
                it++;
                j--;
            }
        }
        return image;
    }
};