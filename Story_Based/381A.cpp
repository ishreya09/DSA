/*

https://codeforces.com/problemset/problem/381/A
Two Pointer


*/

/*
Algorithm

1. Define k to check whose chance it is and then select the maximum from either side of the array using 2 pointers
and decrement or increment from the respective side accordingly

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> SerejaAndDima(vector<int> &cards){
    vector<int> ans={0,0};
    int i=0;
    int j=cards.size()-1;
    int k=0;
    while(i<=j){
        if (k%2==0){ //sereja's chance
            if (cards[i]>=cards[j]){
                ans[0]+= cards[i];
                i++;
            }
            else{
                ans[0]+= cards[j];
                j--;
            }
        }
        else{ // Dima's chance
            if (cards[i]>=cards[j]){
                ans[1]+= cards[i];
                i++;
            }
            else{
                ans[1]+= cards[j];
                j--;
            }
        }
        k++;
    }

    return ans;

}

int main(){
    int N;
	cin>>N;
    vector<int>A(N);
    for(auto&i :A){
        cin>>i;
    }
    vector<int> ans= SerejaAndDima(A);
    cout<<ans[0]<<" "<< ans[1]<<endl;
    return 0;
}