#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    extern int i; // extern var is only declared- so no actual memory gets allocated
    cout<<i; // gives compilation error
    {
        int i=10;
        cout<<i;
    }
    return 0;
}
