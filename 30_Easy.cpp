#include<iostream>
using namespace std;

// 1732. Find the Highest Altitude

/***************
There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

Example 1:
Input: gain = [-5,1,5,0,-7]
Output: 1
    Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.

Example 2:
Input: gain = [-4,-3,-2,-1,4,3,2]
Output: 0
    Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.
***************/


class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        // new array to push the value
        vector<int> arr;

        // first element is going to be 0
        arr.push_back(0);

        int val;

        for(int i = 0; i < gain.size(); i++)
        {
            // gain the altitude based on the array gain
            val = arr[i] + gain[i];

            arr.push_back(val);
        }
        
        // sort it in ascending order
        std::sort(arr.begin(), arr.end());

        // return the last element in the arr array as it will be the highest altitude the biker gained
        return arr[gain.size()];
    }
};
