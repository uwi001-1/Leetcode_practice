#include<iostream>
using namespace std;

// Q2. How Many Numbers Are Smaller Than the Current Number

/***************
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. 
That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

Example 1:
Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).

Example 2:
Input: nums = [6,5,4,8]
Output: [2,1,0,3]

Example 3:
Input: nums = [7,7,7,7]
Output: [0,0,0,0]
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
