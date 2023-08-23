#include <iostream>
using namespace std;

int& fun()
{
	static int x = 10;
	return x;
}

int main()
{
	fun() = 30;
	cout << fun()<<endl; //30
    int &y = fun(); //30 - y contains reference to x
    y=y+10;
    cout<<fun()<<endl; // 40
    cout<<y;// 40
	return 0;
}
