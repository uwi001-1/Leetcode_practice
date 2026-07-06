#include<iostream>
using namespace std;

// 1288. Remove Covered Intervals

/***************
Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.

Example 1:
Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
    Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.

Example 2:
Input: intervals = [[1,4],[2,3]]
Output: 1
***************/


class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        // sort from the first index in ascending order 
        // then sort the second index if same first index in descending order 
        std::sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b)
        {
            if(a[0] == b[0]) return a[1] > b[1]; // same start → longer end first
            return a[0] < b[0]; // sort by start ascending
        });

        int maxEnd = 0;
        int count = 0;

        for(int i = 0; i < intervals.size(); i++)
        {
            if(intervals[i][1] <= maxEnd)
            {
                // covered! don't count it
            }
            else
            {
                // not covered
                maxEnd = intervals[i][1];
                count += 1;
            }
        } 

        return count;
    }
};
