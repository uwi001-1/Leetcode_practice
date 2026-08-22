#include<iostream>
using namespace std;

// Q3. Find All Numbers Disappeared in an Array

/***************
Given an array nums of n integers where nums[i] is in the range [1, n], 
return an array of all the integers in the range [1, n] that do not appear in nums.

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:
Input: nums = [1,1]
Output: [2]
***************/


// Hash Table O(n + K) --> 0ms
class Solution {
public:
    // Hash Table 
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        // frequency array 
        vector<int> freq(101, 0);

        // make the frequency array
        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        // cumilative frequency array
        int count = 0;
        for(int j = 0; j < 101; j++)
        {
            int temp = freq[j];

            freq[j] = count;

            count += temp;
        }

        vector<int> arr;
        for(int k = 0; k < nums.size(); k++)
        {
            arr.push_back(freq[nums[k]]);
        }

        return arr;
    }
};


// Brute Force O(n^2) --> 15ms
class Solution {
public:
    // Brute Force
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        vector<int> arr;

        for(int i = 0; i < nums.size(); i++)
        {
            int count = 0;

            for(int j = 0; j < nums.size(); j++)
            {
                if(j != i)
                {
                    if(nums[i] > nums[j]) count++;
                }
            }

            arr.push_back(count);
        }

        return arr;
    }
};
