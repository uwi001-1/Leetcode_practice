#include<iostream>
using namespace std;

// 739. Daily Temperatures

/***************
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.
 
Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:
Input: temperatures = [30,60,90]
Output: [1,1,0]
***************/


// this uses two array 
class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int total = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
        }

        vector<int> sumLeft(nums.size());
        vector<int> sumRight(nums.size());

        int left = 0;
        int right = total;

        for(int i = 0; i < nums.size(); i++)
        {
            // Remove current element from the right side
            right -= nums[i];

            sumLeft[i] = left;
            sumRight[i] = right;

            // Add current element to the left side
            left += nums[i];
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(sumLeft[i] == sumRight[i])
                return i;
        }

        return -1;
    }
};


// this is 900ms 💀
// as we calculate each time 
class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        for(int i = 0; i < nums.size(); i++)
        {
            int sumLeft = 0;
            if(i == 0) sumLeft = 0;
            else
            {
                int left = i - 1;
                while(left >= 0)
                {
                    sumLeft += nums[left];
                    left--;
                }
            }

            int sumRight = 0;
            if(i == nums.size()-1) sumRight = 0;
            else
            {
                int right = i + 1;
                while(right < nums.size())
                {
                    sumRight += nums[right];
                    right++;
                }
            }

            if(sumLeft == sumRight) return i;
        }

        return -1;
    }
};
