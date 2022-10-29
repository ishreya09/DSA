// C++ program to demonstrate the use of std::max
#include<iostream>
#include<algorithm>
using namespace std;

// Defining the binary function
bool comp(int a, int b)
{
return (a < b);
}
int main()
{

// Finding the largest of all the numbers
cout << std::max({1, 2, 3, 4, 5, 10, -1, 7},comp) << "\n";

return 0;
}

// Time complexity :- O(n)
// Auxiliary Space :- O(1)