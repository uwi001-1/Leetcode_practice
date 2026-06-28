#include<iostream>
using namespace std;

// 55. Jump Game

/***************
You are given an integer array nums. 
You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
    Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
    Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
***************/


class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) 
    {
        // sort the array
        std::sort(arr.begin(), arr.end());

        // 1st element must be 1
        if(arr[0] != 1) arr[0] = 1;

        for(int i = 1; i < arr.size(); i++)
        {
            // if adjacent element is equal then just continue
            if(arr[i] == arr[i-1]) continue;

            if(arr[i] != arr[i-1] + 1)
            {
                // if the adjancent element is not just greater by 1
                // change it
                arr[i] = arr[i-1] + 1;
            }
        }

        // return the max element which will be the last element
        return arr[arr.size() -1];
    }
};
