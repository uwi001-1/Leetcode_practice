#include<iostream>
using namespace std;

// 3622. Check Divisibility by Digit Sum and Product

/***************
You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:
The digit sum of n (the sum of its digits).
The digit product of n (the product of its digits).
Return true if n is divisible by this sum; otherwise, return false.

Example 1:
Input: n = 99
Output: true
Explanation:
Since 99 is divisible by the sum (9 + 9 = 18) plus product (9 * 9 = 81) of its digits (total 99), the output is true.

Example 2:
Input: n = 23
Output: false
Explanation:
Since 23 is not divisible by the sum (2 + 3 = 5) plus product (2 * 3 = 6) of its digits (total 11), the output is false.
***************/


class Solution {
public:
    vector<int> resultArray(vector<int>& nums) 
    {
        vector<int> arr1;
        vector<int> arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int i1 = 0;
        int i2 = 0;

        for(int i = 2; i < nums.size(); i++)
        {
            if(arr1[i1] > arr2[i2]) 
            {
                arr1.push_back(nums[i]);
                i1++;
            }
            else
            {
                arr2.push_back(nums[i]);
                i2++;
            }
        }

        nums = arr1;

        nums.insert(nums.end(), arr2.begin(), arr2.end());

        return nums;
    }
};
