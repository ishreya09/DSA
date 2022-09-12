// ordering by the second element of pairs
//  in the priority queue(max-heap)

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> p;

// Structure is created to sort the
// pairs by the second element
struct ele
{
    constexpr bool operator()(
        pair<int, int> const &x,
        pair<int, int> const &y)
        const noexcept
    {
        return x.second < y.second;
    }
};

// Function to show the elements
// of the priority queue
void show(
    priority_queue<p,
                   vector<p>, ele>
        pq)
{
    // while loop will work
    // till the priority queue is
    // not empty(!pq.isempty())

    while (!pq.empty())
    {

        // Printing the elements until the priority
        // queue is empty
        cout << pq.top().first
             << " " << pq.top().second
             << endl;
        pq.pop();
    }
    cout << endl;
}

// Driver Code
int main()
{
    priority_queue<p, vector<p>, ele> t;

    // pushing the elements in the priority queue
    t.push(make_pair(1, 9));
    t.push(make_pair(8, 4));
    t.push(make_pair(4, 5));
    t.push(make_pair(3, 3));
    t.push(make_pair(2, 7));

    // Make a function call to print the pairs
    // sorted by second element
    show(t);
    return 0;
}