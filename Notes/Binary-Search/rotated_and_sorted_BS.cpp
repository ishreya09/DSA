#include<bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int>&nums, int key){
    int low=0;
    int high= nums.size()-1;
    while(low<=high){
        int mid = (low +high)/2;
        if (nums[mid]==key){
            return mid;
        }
        if (nums[low]<nums[mid]){ // left part sorted
            if (key >= nums[low ] && key<mid){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{ // right part sorted
            if (key >nums[mid] && key<= nums[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}


int main(){
    vector<int> a ={90,100,110,50,65,80};
    cout<<BinarySearch(a,90)<<endl;
    cout<<BinarySearch(a,100)<<endl;
    cout<<BinarySearch(a,110)<<endl;
    cout<<BinarySearch(a,50)<<endl;
    return 0;
}