/*
1418. Display Table of Food Orders in a Restaurant
Medium

https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/description/

Given the array orders, which represents the orders that customers have done in a restaurant. 
More specifically orders[i]=[customerNamei,tableNumberi,foodItemi] where customerNamei is the 
name of the customer, tableNumberi is the table customer sit at, and foodItemi is the item customer orders.

Return the restaurant's “display table”. The “display table” is a table whose row entries denote 
how many of each food item each table ordered. The first column is the table number and the remaining columns correspond to each food item in alphabetical order. The first row should be a header whose first column is “Table”, followed by the names of the food items. Note that the customer names are not part of the table. Additionally, the rows should be sorted in numerically increasing order.

 

Example 1:

Input: orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]
Output: [["Table","Beef Burrito","Ceviche","Fried Chicken","Water"],["3","0","2","1","0"],["5","0","1","0","1"],["10","1","0","0","0"]] 
Explanation:
The displaying table looks like:
Table,Beef Burrito,Ceviche,Fried Chicken,Water
3    ,0           ,2      ,1            ,0
5    ,0           ,1      ,0            ,1
10   ,1           ,0      ,0            ,0
For the table 3: David orders "Ceviche" and "Fried Chicken", and Rous orders "Ceviche".
For the table 5: Carla orders "Water" and "Ceviche".
For the table 10: Corina orders "Beef Burrito". 
Example 2:

Input: orders = [["James","12","Fried Chicken"],["Ratesh","12","Fried Chicken"],["Amadeus","12","Fried Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]]
Output: [["Table","Canadian Waffles","Fried Chicken"],["1","2","0"],["12","0","3"]] 
Explanation: 
For the table 1: Adam and Brianna order "Canadian Waffles".
For the table 12: James, Ratesh and Amadeus order "Fried Chicken".
Example 3:

Input: orders = [["Laura","2","Bean Burrito"],["Jhon","2","Beef Burrito"],["Melissa","2","Soda"]]
Output: [["Table","Bean Burrito","Beef Burrito","Soda"],["2","1","1","1"]]
 

Constraints:

1 <= orders.length <= 5 * 10^4
orders[i].length == 3
1 <= customerNamei.length, foodItemi.length <= 20
customerNamei and foodItemi consist of lowercase and uppercase English letters and the space character.
tableNumberi is a valid integer between 1 and 500.
*/

/*
Algorithm

1. take a map f which stores table no as int and keep all the orders from that table in a vector of strings
2. We take a set and add all unique foods and then create another map pos
3. We initialize a 2D array with size as f.size()+1 * set.size()+1 - lets name it as ans and initialize all values to "0"
4. We add all the set's value to the ans[0][i>0]- for ans[0][0]= "Table"
5. We also set pos as i for that particular food. pos keeps track of the position of food in the table
6. We lastly iterate through the map f and add the table number in ans[i][0]
7. We iterate through each table's vector and add where it's position is present according to pos[food of that table] 
and increment the value by 1.
8. We return ans

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string a,string b){
        cout<<a<<" "<<b<<endl;
        int x=stoi(a)+stoi(b); // to convert from string to int
        return to_string(x);
    }
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int,vector<string>>f;
        set<string> food;
        for(int i=0;i<orders.size();i++){
            f[stoi(orders[i][1])].push_back(orders[i][2]);
            food.insert(orders[i][2]);
        }

        // way to initialize 2d array to zero
        vector<vector<string>>ans(f.size()+1,vector<string>(food.size()+1,"0")); 
        
        ans[0][0]="Table";
        int k=1;
        map<string,int> pos; // pos of food in table
        for (auto i:food){ // for upper label
            ans[0][k]=i;
            pos[i]=k++;
        } 

        int i=1;  
        for (auto &it:f){
            ans[i][0]=to_string(it.first); // to convert int to string
            int t=0;
            while(t<it.second.size()){
                ans[i][pos[it.second[t]]]=addStrings(ans[i][pos[it.second[t]]],"1");
                // cout<<ans[i][0]<<" "<<it.second[t]<<" "<<pos[it.second[t]]<<endl;
                t++;
            }
            i++;
        }

        return ans;
    }
};