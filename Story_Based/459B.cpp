// https://codeforces.com/problemset/problem/459/B

#include<bits/stdc++.h>
using namespace std;

void PashmankAndFlowers(vector<int> flower){
    int minEle = *min_element(flower.begin(),flower.end());
    int maxEle = *max_element(flower.begin(),flower.end());
    if (minEle==maxEle){ // array with all same numbers
        cout<<0 << " "<< (long long int) flower.size()*(flower.size()-1)/2<<endl;
    }
    else{

        map<long long,long long> f;
        for (int i=0; i<flower.size();i++){
            if (flower[i]==minEle){
                f[minEle]++;
            }
            else if (flower[i]==maxEle){
                f[maxEle]++;
            }
        }

        cout<<( maxEle-minEle) << " "<< (long long int)f[minEle]*f[maxEle] <<endl;
    }
    
}

int main(){
    int n;
    cin>>n;
    vector<int> f(n);
    for (auto &i : f){
        cin>>i;
    }
    PashmankAndFlowers(f);

    return 0;
}