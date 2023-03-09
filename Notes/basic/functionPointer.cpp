#include <bits/stdc++.h>
using namespace std;

// 3rd argument is a function pointer
void sort(int a[], int n, bool (*compare)(int, int))
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (!compare(a[j], a[j + 1]))
                swap(a[j], a[j + 1]);
}

bool asc(int x, int y) { return x < y; }
bool desc(int x, int y) { return x > y; }

int main()
{
    int a[] = {0, 2, 5, 6, 9, 1, 3, 4, 8, 7};

    // pass ascending function
    sort(a, 10, asc);

    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;

    // pass descending function
    sort(a, 10, desc);

    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;
}