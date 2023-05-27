// Array Name as Pointers   

// An array name contains the address of first element of the array which acts like constant pointer. 
// It means, the address stored in array name can't be changed. For example, if we have an array named 
// val then val and &val[0] can be used interchangeably.

// C++ program to illustrate Array Name as Pointers in C++
#include <bits/stdc++.h>
using namespace std;
void geeks()
{
    // Declare an array
    int val[3] = { 5, 10, 20 };

    // declare pointer variable
    int* ptr;

    // Assign the address of val[0] to ptr
    // We can use ptr=&val[0];(both are same)
    ptr = val;
    cout << "Elements of the array are: ";
    cout << ptr[0] << " " << ptr[1] << " " << ptr[2];
}

// Driver program
int main()
{
    geeks();
}
// If pointer ptr is sent to a function as an argument, the array val can be accessed in a similar fashion.