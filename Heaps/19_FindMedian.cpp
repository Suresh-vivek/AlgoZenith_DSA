/*
295. Find Median from Data Stream
Solved
Hard
Topics
Companies
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.

*/

#include<bits/stdc++.h>
using namespace std;




class MedianFinder {
public:
    // maxheap for elements smaller than or equal to the median
    priority_queue<int> maxh;

    // minheap for elements larger than the median
    priority_queue<int , vector<int> , greater<int>> minh;

    MedianFinder() {}

    void addNum(int num) {
        // if maxheap is empty or num is less than or equal to the top of maxheap
        if(maxh.empty() || maxh.top() >= num){
            maxh.push(num);
        } else {
            minh.push(num);
        }

        // Balance the heaps to ensure maxh can only have at most one extra element
        if(maxh.size() > minh.size() + 1){
            minh.push(maxh.top());
            maxh.pop();
        } else if (minh.size() > maxh.size()){
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        // If the heaps are the same size, the median is the average of the two top elements
        if(maxh.size() == minh.size()){
            return (maxh.top() + minh.top()) / 2.0;
        } else {
            // If maxh has one more element, the median is the top of maxh
            return maxh.top();
        }
    }
};
