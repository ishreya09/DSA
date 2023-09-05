/*
Min and Max number of candies gfg

In a candy store, there are N different types of candies available and the prices of all 
the N different types of candies are provided to you.
You are now provided with an attractive offer.
You can buy a single candy from the store and get at most K other candies ( all are different types ) for free.
Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money 
you have to spend to buy all the N different candies. Secondly, you have to find what is the maximum 
amount of money you have to spend to buy all the N different candies.
In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.

Input:
N = 4
K = 2
candies[] = {3 2 1 4}

Output:
3 7


*/

/*
Algorithm

1.for minimum number of candies, sort first in accending order and get the free candies from the end of the array and
buy from the start.
2. for maximum number of candies, we buy the candy from the end and get the free candies from the start of the array 

*/

#include <bits/stdc++.h>
using namespace std;

void max_and_min_no_of_candies(vector<int > candies, int k ){
    int N= candies.size();
    sort (candies.begin(), candies.end());
    int max=0;

    int min=0;
    int i=0;
    while (N>=i)
    {
        min= min+candies[i];
        N= N-k;
        i++;
    }

    N= 0;
    i = candies.size()-1;
    while (N<=i)
    {
        max= max+candies[i];
        N= N+k;
        i--;
    }

    cout << min <<endl<< max<<endl;


}

int main(){
    vector<int> a= {3,2,1,4};
    int k=2;
    max_and_min_no_of_candies(a,k);
    return 0;
}