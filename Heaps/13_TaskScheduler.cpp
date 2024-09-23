/*
621. Task Scheduler
Solved
Medium
Topics
Companies
Hint
You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. Each cycle or interval allows the completion of one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time.

​Return the minimum number of intervals required to complete all tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two cycles before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th cycle, you can do A again as 2 intervals have passed.

Example 2:
*/


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // use maxheap

        vector<int> mp(26 , 0);

        for(auto & c: tasks){
            mp[c - 'A']++;
        }

        priority_queue<int> maxh;

        for(int i =0 ; i< 26 ;i++){
            if(mp[i] >0){
                maxh.push(mp[i]);
            }
        }

        int time =0;

        while(!maxh.empty()){

            vector<int> task ; 

            for(int i = 1 ;i <= n+1;i++){

               if(!maxh.empty()){
                 int freq = maxh.top();
                freq--;
                maxh.pop();
                task.push_back(freq);
               }

            }

            for(int & f : task){
                if(f>0){
                    maxh.push(f);
                }
            }


            // add val to answer

            if(maxh.empty()){
                time += task.size();
            }else{
                time +=n+1;
            }
        }
            return time;                                                        
    }
};