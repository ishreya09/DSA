// CPP Program to demonstrate Priority Queue having min element at top
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int arr[]={1,2,3};
	
	priority_queue<int> pq1(arr, arr+3);	 // creating priority queue using array
	
	cout<<"Max priority queue: ";
	while(pq1.empty()==false){
	cout<<pq1.top()<<" ";
	pq1.pop();
	}
	cout<<endl;
	
	
	for(int i=0; i<3; i++){
	arr[i]=-arr[i];			 // multiplying each array element by -1
	}
	
	priority_queue<int> pq2(arr, arr+3);
	
	cout<<"Min priority queue: ";
	while(pq2.empty()==false){
	cout<<-pq2.top()<<" ";
	pq2.pop();
	}
	
}
