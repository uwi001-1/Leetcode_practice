#include<iostream>
using namespace std;

// 13. Roman to Integer

/***************
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example 1:
Input: nums = [3,0,1]
Output: 2
    Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:
Input: nums = [0,1]
Output: 2
    Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
    Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
***************/

//With O(n2) --> it's too slow
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // there is exaclty one number missing between 0 and nums.size()
        bool found = false;

        for(int i = 0; i <= nums.size(); i++)     //select a number like 0 to nums.size()
        {
            for(int j =0; j < nums.size(); j++)     //to check with the selected number and the number in the array
            {
                if(nums[j] == i)       //check, if found then break
                {
                    found = true;
                    break;  
                }
                else
                {
                    found = false;
                }
            }
            if(found == false)   //if not found through out the array, then that is the missing number
                return {i};
        }
        return {};
    }
};
