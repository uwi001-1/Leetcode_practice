#include<iostream>
using namespace std;

// 172. Factorial Trailing Zeroes

/***************
Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.


Example 1:
Input: n = 3
Output: 0
    Explanation: 3! = 6, no trailing zero.

Example 2:
Input: n = 5
Output: 1
    Explanation: 5! = 120, one trailing zero.

Example 3:
Input: n = 0
Output: 0
***************/


class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        // first push the elements other than 0 into an array
        vector<int> arr;
        int count = 0; 

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0) arr.push_back(nums[i]);
            else count += 1;
        }

        while(count > 0)
        {
            arr.push_back(0);
            count--;
        }    

        nums = arr;
    }
};
