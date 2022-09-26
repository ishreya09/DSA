/*
CodeChef
Save Konoha
Problem Code: SAVKONO

https://www.codechef.com/problems/SAVKONO

Problem
Pain is the leader of a secret organization whose goal is to destroy the leaf village(Konoha). 
After successive failures, the leader has himself appeared for the job. Naruto is the head of the 
village but he is not in a condition to fight so the future of the village depends on the soldiers 
who have sworn to obey Naruto till death.

Naruto is a strong leader who loves his villagers more than anything but tactics is not his strong area. 
He is confused whether they should confront Pain or evacuate the villagers including the soldiers 
(he loves his villagers more than the village). Since you are his advisor and most trusted friend, 
Naruto wants you to take the decision.

Pain has a strength of ZZ and is confident that he will succeed. Naruto has NN soldiers under his 
command numbered 11 through NN. Power of ii-th soldier is denoted by A_iA 
i. 

When a soldier attacks pain, his strength gets reduced by the corresponding power of the soldier. 
However, every action has a reaction so the power of the soldier also gets halved i.e. A_iA 
i changes to [A_i/2][A i /2]. Each soldier may attack any number of times (including 0). 
Pain is defeated if his strength is reduced to 0 or less.

Find the minimum number of times the soldiers need to attack so that the village is saved.

Input:
First line will contain TT, number of test cases. Then the test cases follow.
The first line of each test case contains two space-separated integers NN and ZZ.
The second line contains NN space-separated integers A_1,A_2,…,A_NA 
1
​
 ,A 
2
​
 ,…,A 
N
​
  the attacking power of the soldiers.
Output:
For each test case, print a single line. If Pain cannot be defeated, this line should contain the string "Evacuate" 
(without quotes). Otherwise, it should contain the minimum number of times the soldiers need to attack.

Constraints
1 \leq T \leq 101≤T≤10
1 \leq N \leq 10^51≤N≤10 
5
 
1 \leq Z \leq 10^81≤Z≤10 
8
 
1 \leq A_i \leq 10^41≤A 
i
​
 ≤10 
4
 
Sample Input:
1
5 25
7 13 8 17 3

Sample Output:
2
### EXPLANATION:
Soldier with power 17 hits Pain, The new powers of soldiers become [7, 13, 8, 8, 3][7,13,8,8,3] 
and the strength of pain is reduced to 8, after that any soldier with a power greater than equal 
to 8 can hit Pain and thus defeat him, hence answer is 2.
*/

/*
Algorithm

1. Make a pq for Naruto's Army. 
2. Count the number of moves and go on decreasing the power of Z, and halfing the top value of the priority_queue.
3. if Z becomes zero or negative, return count, else -1.
*/

#include<bits/stdc++.h>
using namespace std;

// function to return the number of attacks or -1 if the number of soldiers fails
int minSoldierAttacks(int Z,int N, vector<int> &A){
    if(N==0 && Z!=0){
        return -1;
    }
    if(Z==0){
        return 0;
    }
    
    priority_queue<int> pq;
    for (int i=0;i<N; i++){
        pq.push(A[i]);
    }
    int count=0;
    while (!pq.empty()){
        int power= pq.top();
        pq.pop();
        Z-=power;
        
        count++;
        power/=2;
        if (power>0){
            pq.push(power);
        }
        if (Z<=0){
            return count;
        }
    }
    return -1;
}

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	    int N,Z;
	    cin>>N>>Z;
	    vector<int>A(N);
	    int x;
	    for(auto&i :A){
	        cin>>i;
	    }
	    int k= minSoldierAttacks(Z,N,A);
	    if (k>=0){
	        cout<<k<<endl;
	    }
	    else{
	        cout<<"Evacuate"<<endl;
	    }
	}
	
	return 0;
}
