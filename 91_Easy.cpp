#include<iostream>
using namespace std;

// 1260. Shift 2D Grid

/***************
Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

In one shift operation:
    Element at grid[i][j] moves to grid[i][j + 1].
    Element at grid[i][n - 1] moves to grid[i + 1][0].
    Element at grid[m - 1][n - 1] moves to grid[0][0].
    Return the 2D grid after applying shift operation k times.

Example 1:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[9,1,2],[3,4,5],[6,7,8]]

Example 2:
Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]

Example 3:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
Output: [[1,2,3],[4,5,6],[7,8,9]]
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
