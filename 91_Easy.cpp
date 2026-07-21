#include<iostream>
using namespace std;

// 136. Single Number

/***************
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1
***************/


class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) 
    {
        // covert the 2D into 1D
        vector<int> arr; 
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                arr.push_back(grid[i][j]);
            }
        }

        // handle k
        k = k % arr.size();

        // base case where k == 0, then we don't need to anything
        if(k == 0) return grid;

        // now push into another 1D aray, after moving it based on k
        vector<int> flat;
        for(int m = arr.size() - k; m < arr.size(); m++)
        {
            flat.push_back(arr[m]);
        }
        // now push the rest of the array
        for(int n = 0; n < arr.size() - k; n++)
        {
            flat.push_back(arr[n]);
        }

        // convert 1D array to 2D array
        int idx = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                grid[i][j] = flat[idx];
                idx++;
            }
        }

        return grid;
    }
};
