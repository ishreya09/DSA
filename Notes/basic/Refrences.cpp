// C++ References is a new language construct which was introduced to reduce the dependency
// over pointers for doing indirect memory access. Usage of pointers requires caution as the 
// programmer needs to manually deallocate them to avoid memory leaks. 
// A reference is an alternative name for a memory location. 
// References are useful in following situations -


// 1. Modify the passed parameters in a function

#include <bits/stdc++.h>
using namespace std;

void swap (int& first, int& second)
{
    int temp = first;
    first = second;
    second = temp;
}

int main()
{
    int a = 2, b = 3;
    swap(a, b);
    cout << a << " " << b;
    return 0;
}

// 2. Avoiding copy of large structures

struct Student {
   string name;
   string address;
   int rollNo;
};

void print(const Student &s)
{
    cout << s.name << "  " << s.address << "  " << s.rollNo;
}

// 3. In For-Each Loops to modify all objects

// #include <bits/stdc++.h> 
// using namespace std; 

int main2() 
{ 
    vector<int> vect{ 10, 20, 30, 40 }; 

    for (int &x : vect) 
        x = x + 5;

    for (int x : vect) 
       cout << x << " "; 

    return 0; 
}