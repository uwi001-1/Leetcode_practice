#include<iostream>
using namespace std;

// 605. Can Place Flowers

/***************
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, 
return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
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
