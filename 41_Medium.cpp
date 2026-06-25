#include<iostream>
using namespace std;

// 7. Reverse Integer

/***************
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.    (## INT_MAX)

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21
***************/


class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) 
    {
        // we use brute force approach 
        // that is try every possible subarray, one by one. --> length of all possible chunks

        // count how many times target appears in the subarray
        int targetCount = 0;

        // count the number of valid subarray
        int total = 0;

        // To generate all chunks in code, you just need two indices — where the chunk starts (i) and where it ends (j)
        for(int i = 0; i < nums.size(); i++)        
        {
            for(int j = i; j < nums.size(); j++)
            {
                // check subarray nums[i..j]
                if(nums[j] == target) targetCount += 1;

                // if targetCount is greater than half the size of subarray then it has target as majority element
                if(targetCount > (j - i + 1) / 2) total += 1;
            }
            // change the targetCount to 0
            targetCount = 0;
        }
        return total;
    }
};
