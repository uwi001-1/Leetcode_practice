#include<iostream>
using namespace std;

// 3895. Count Digit Appearances


/***************
You are given an integer array nums and an integer digit.
Return the total number of times digit appears in the decimal representation of all elements in nums.

Example 1:
Input: nums = [12,54,32,22], digit = 2
Output: 4
    Explanation:
    The digit 2 appears once in 12 and 32, and twice in 22. Thus, the total number of times digit 2 appears is 4.

Example 2:
Input: nums = [1,34,7], digit = 9
Output: 0
    Explanation:
    The digit 9 does not appear in the decimal representation of any element in nums, so the total number of times digit 9 appears is 0.
***************/


class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) 
    {
        // sort the array in ascending order as that is the most reasonable
        // If you can't destroy a smaller asteroid, you definitely can't destroy a larger one. So sorting ascending and going left to right is optimal.
        std::sort(asteroids.begin(), asteroids.end()); 
        
        // use long long data type as it is 64-bit size as the mass size can be huge
        long long newMass = mass;

        // this is a for loop, in vectors, use .size() makes it complicated
        for(int i : asteroids)
        {
            // if ever can't be destroyed, then return false
            if(i > newMass) return false;
            else
            {
                // destroy and add to the mass of the planet
                newMass += i;
            }
        }
        return true;
    }
};
