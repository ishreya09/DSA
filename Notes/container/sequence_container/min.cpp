// C++ program to demonstrate the use of std::min
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Defining the binary function
bool comp(int a, int b)
{
return (a < b);
}
int main()
{

// Finding the smallest of all the numbers
cout << std::min({ 1, 2, 3, 4, 5, 0, -1, 7 }, comp) << "\n";

return 0;
}

// Time complexity :- O(n)
// Auxiliary Space :- O(1)