/*
1792. Maximum Average Pass Ratio
Medium

https://leetcode.com/problems/maximum-average-pass-ratio/

There is a school that has classes of students and each class will be having a final exam. 
You are given a 2D integer array classes, where classes[i] = [passi, totali]. 
You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are 
guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents 
students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the 
total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided 
by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the 
actual answer will be accepted.

 

Example 1:

Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
Output: 0.78333
Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal 
to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
Example 2:

Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
Output: 0.53485
 

Constraints:

1 <= classes.length <= 105
classes[i].length == 2
1 <= passi <= totali <= 105
1 <= extraStudents <= 105
*/

/*
Algorithm 

1.Since the change in the pass ratio is always decreasing with the more students you add,
then the very first student you add to each class is the one that makes the biggest change in the pass ratio.
2. Because each class's pass ratio is weighted equally, it's always optimal to put the student in 
the class that makes the biggest change among all the other classes.
3. Keep a max heap of the current class sizes and order them by the change in pass ratio. For each extra student, 
take the top of the heap, update the class size, and put it back in the heap. Also maintain the index of the element 
corresponding to classes array.
4. Go on adding students and update the change in pass ratio for the i th element and go on further
We add extraStudents to the top of the change in pass ratio's pq
5. Calculate the avg pass ratio by traversing through the array classes

*/

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        int n = classes.size();
        priority_queue<pair<double,int>> pq;
        
        for(int i=0 ; i<n; i++)
        {
            double d = (classes[i][0]+1)*1.0/(classes[i][1]+1) - (classes[i][0])*1.0/(classes[i][1]);
            pq.push({d,i});
        }
        double ans = 0;
        while(extraStudents>0)
        {
            auto p = pq.top();
            pq.pop();
            int id = p.second;
            classes[id][0]++;
            classes[id][1]++;
            
            double d = (classes[id][0]+1)*1.0/(classes[id][1]+1) - (classes[id][0])*1.0/(classes[id][1]);
            pq.push({d,id});
            extraStudents--;
        }
        for(int i=0 ; i<n ; i++)
            ans += classes[i][0]*1.0/classes[i][1];
        
        ans /= n;
        return ans;
    }
};


// Another
// not working
bool AreDoubleSame(double dFirstVal, double dSecondVal)
{
    return fabs(dFirstVal - dSecondVal) < 1E-5;
}

struct Compare{
    bool operator() (pair<int,int> a,pair<int,int> b){
        double ra = a.first/a.second;
        double rb = b.first/b.second;
        if(!AreDoubleSame(ra,rb)){
            return ra<rb;
        }
        else{
            return (a.second-a.first) < (b.second-b.first);
        }
    }
};

class Solution1 {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, Compare > p;
        for(int i=0;i<classes.size();i++){
            p.push(make_pair(classes[i][0],classes[i][1]));
        }
        while(extraStudents-- && !p.empty()){
            auto i= p.top();
            p.pop();
            i.first++;
            i.second++;
            // cout<<i.first<<"\t"<<i.second<<endl;
            p.push(i);
        }
        double sum=0;
        while(!p.empty()){
            auto i = p.top();
            cout<<i.first<<"\t"<<i.second<<"\t"<< (i.first/(double)i.second)<<endl;
            sum+=(i.first/(double)i.second);
            p.pop();
        }
        cout<<sum;
        sum= sum/classes.size();
        return sum;
    }
};