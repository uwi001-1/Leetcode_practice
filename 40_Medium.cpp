#include<iostream>
using namespace std;

// 3737. Count Subarrays With Majority Element I

/***************
You are given an integer array nums and an integer target.

Return the number of subarrays of nums in which target is the majority element.

The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.

Example 1:
Input: nums = [1,2,2,3], target = 2
Output: 5
    Explanation:
    Valid subarrays with target = 2 as the majority element:
nums[1..1] = [2]
nums[2..2] = [2]
nums[1..2] = [2,2]
nums[0..2] = [1,2,2]
nums[1..3] = [2,2,3]
So there are 5 such subarrays.

Example 2:
Input: nums = [1,1,1,1], target = 1
Output: 10
    Explanation:
    ​​​​​​​All 10 subarrays have 1 as the majority element.

Example 3:
Input: nums = [1,2,3], target = 4
Output: 0
    Explanation:
    target = 4 does not appear in nums at all. Therefore, there cannot be any subarray where 4 is the majority element. Hence the answer is 0.
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
