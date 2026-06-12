#include<iostream>
using namespace std;

// 2535. Difference Between Element Sum and Digit Sum of an Array

/***************
You are given a positive integer array nums.

The element sum is the sum of all the elements in nums.
The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
Return the absolute difference between the element sum and digit sum of nums.

Note that the absolute difference between two integers x and y is defined as |x - y|.

Example 1:
Input: nums = [1,15,6,3]
Output: 9
    Explanation: 
    The element sum of nums is 1 + 15 + 6 + 3 = 25.
    The digit sum of nums is 1 + 1 + 5 + 6 + 3 = 16.
    The absolute difference between the element sum and digit sum is |25 - 16| = 9.

Example 2:
Input: nums = [1,2,3,4]
Output: 0
    Explanation:
    The element sum of nums is 1 + 2 + 3 + 4 = 10.
    The digit sum of nums is 1 + 2 + 3 + 4 = 10.
    The absolute difference between the element sum and digit sum is |10 - 10| = 0.
***************/


class Solution {
public:
    int differenceOfSum(vector<int>& nums) 
    {
        // this data type as the element could be long 
        long long ele = 0;
        long long digit = 0; 

        for(int index : nums)
        {
            // add each element 
            ele += index;

            while(true)
            {
                if(index < 10) 
                {
                    digit += index;
                    break;
                }
                else
                {
                    // get the digit and also reduce the number
                    digit += index % 10;
                    index = index /10;
                }
            }
        }

        // this as we need to find the absolute difference
        long long diff; 
        if(ele >= digit) diff = ele - digit;
        if(ele < digit) diff = digit - ele;

        // could use this too abs(ele - digit);
        return diff;    
    }
};
