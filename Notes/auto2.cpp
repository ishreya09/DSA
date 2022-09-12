#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    // declaring the name variables as auto
    auto name1 = "komal";
    auto name2 = "yashi";
    auto name3 = "rashi";
    // pushing the names defined above in vector
    vector<string> vec1;
    vec1.push_back(name1);
    vec1.push_back(name2);
    vec1.push_back(name3);
    // printing the values of vector on console using 'i' as an auto variable to iterate
    cout << "Here is the vector data" << endl;
    for (auto i = vec1.begin(); i != vec1.end(); i++)
    {
        cout << *i << endl;
    }
    return 0;
}