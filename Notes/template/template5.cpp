// What is the difference between function overloading and templates? 

// Both function overloading and templates are examples of polymorphism features of OOP. Function overloading 
// is used when multiple functions do quite similar (not identical) operations, templates are used when multiple 
// functions do identical operations.

// What happens when there is a static member in a template class/function? 

// Each instance of a template contains its own static variable. 
// See Templates and Static variables for more details.

// What is template specialization? 

// Template specialization allows us to have different codes for a particular data type. 
// See Template Specialization for more details.

// Can we pass non type parameters to templates? 

// We can pass non-type arguments to templates. Non-type parameters are mainly used for 
// specifying max or min values or any other constant value for a particular instance of a template. 
// The important thing to note about non-type parameters is, that they must be const. The compiler 
// must know the value of non-type parameters at compile time. Because the compiler needs to create 
// functions/classes for a specified non-type value at compile time. In the below program, if we replace 
// 10000 or 25 with a variable, we get a compiler error.  Refer to the following link.


// A C++ program to demonstrate working of non-type
// parameters to templates in C++.
#include <iostream>
using namespace std;
 
template <class T, int max>
int arrMin(T arr[], int n)
{
   int m = max;
   for (int i = 0; i < n; i++)
      if (arr[i] < m)
         m = arr[i];
 
   return m;
}
 
int main()
{
   int arr1[]  = {10, 20, 15, 12};
   int n1 = sizeof(arr1)/sizeof(arr1[0]);
 
   char arr2[] = {1, 2, 3,-32};
   int n2 = sizeof(arr2)/sizeof(arr2[0]);
 
   // Second template parameter to arrMin must be a constant
   int x = 10000;
//    cout << arrMin<int, x>(arr1, n1) << endl; // this throws an error
   cout << arrMin<char, 256>(arr2, n2); // doubt on how it works
   return 0;
}