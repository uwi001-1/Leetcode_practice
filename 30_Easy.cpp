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
    // array(nums) here is passed by reference
    void rotate(vector<int>& nums, int k) 
    {
        // to handle k > nums.size() cases
        k = k % nums.size();

        // to loop 
        int loop = nums.size() - k;
        
        // new array to push in elements in the order
        vector<int> arr;
        
        while(loop != nums.size())
        {
            // add values from nums.size()-k
            arr.push_back(nums[loop]);
            
            loop += 1;
        }

        // loop the rest of the array
        for(int i = 0; i<nums.size()-k; i++)
        {
            arr.push_back(nums[i]);
        }

        // as we are returning the nums array as it is passed by reference
        nums = arr;
    }
};
