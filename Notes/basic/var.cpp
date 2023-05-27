#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    unsigned int x=-1;
    cout<<x<<endl;
    int y=~0;
    cout<<y<<endl;

    if (x==y){ // typecasting is done here
        cout<<"Equal"<<endl;
    }
    else{
        cout<<"Not Equal"<<endl;
    }

    return 0;
}

// Output:
// 4294967295
// -1
// Equal
