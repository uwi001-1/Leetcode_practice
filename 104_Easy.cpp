#include<iostream>
using namespace std;

// 628. Maximum Product of Three Numbers

/***************
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6

Example 2:
Input: nums = [1,2,3,4]
Output: 24

Example 3:
Input: nums = [-1,-2,-3]
Output: -6
***************/


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        if(n == 0) return true;
        
        int count = 0;
        int size = flowerbed.size();

        if(size == 1) 
        {
            if(flowerbed[0] == 0) return true;
            else return false;
        }

        // first check first and last
        if(flowerbed[0] == 0) 
        {
            if(flowerbed[1] == 0)
            {
                flowerbed[0] = 1;
                count++;
            }
        }
        if(flowerbed[size-1] == 0)
        {
            if(flowerbed[size-2] == 0)
            {
                flowerbed[size-1] = 1;
                count++;
            }
        }

        // and then loop around the array
        for(int i = 1; i < size; i++)
        {
            if(flowerbed[i] == 1) continue;

            if(flowerbed[i-1] == 1) continue;

            if(flowerbed[i+1] == 1) continue;

            if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0)
            {
                flowerbed[i] = 1;
                count++;
            }
        } 

        if(count >= n) return true;
        return false;  
    }
};
