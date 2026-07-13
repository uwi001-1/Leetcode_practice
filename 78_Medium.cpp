#include<iostream>
using namespace std;

// 1276. Number of Burgers with No Waste of Ingredients

/***************
Given two integers tomatoSlices and cheeseSlices. The ingredients of different burgers are as follows:

Jumbo Burger: 4 tomato slices and 1 cheese slice.
Small Burger: 2 Tomato slices and 1 cheese slice.

Return [total_jumbo, total_small] so that the number of remaining tomatoSlices equal to 0 and the number of remaining cheeseSlices equal to 0. If it is not possible to make the remaining tomatoSlices and cheeseSlices equal to 0 return [].

Example 1:
Input: tomatoSlices = 16, cheeseSlices = 7
Output: [1,6]
    Explantion: To make one jumbo burger and 6 small burgers we need 4*1 + 2*6 = 16 tomato and 1 + 6 = 7 cheese.
    There will be no remaining ingredients.

Example 2:
Input: tomatoSlices = 17, cheeseSlices = 4
Output: []
    Explantion: There will be no way to use all ingredients to make small and jumbo burgers.

Example 3:
Input: tomatoSlices = 4, cheeseSlices = 17
Output: []
    Explantion: Making 1 jumbo burger there will be 16 cheese remaining and making 2 small burgers there will be 15 cheese remaining.
***************/


class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) 
    {
        vector<int> arr;

        // if both are zero
        if(cheeseSlices == 0 && tomatoSlices == 0)
        {
            arr.push_back(0);
            arr.push_back(0);

            return arr;
        }

        // when cheeseSlices is greater than tomatoSlices
        if(cheeseSlices >= tomatoSlices) return arr;

        // when tomatoSlices is odd number
        if(tomatoSlices % 2 == 1) return arr;

        
        // check out other cases

        // 4jumbo + 2small = tomatoslices
        // jumbo + small = cheeseSlices

        int jumbo;
        int small;

        int result = (tomatoSlices - (2*cheeseSlices)) / 2;

        if(result != (int)result) return arr;

        else if(result < 0) return arr;
        
        else
        {
            jumbo = result;
            small = cheeseSlices - jumbo;
        }

        if(small < 0) return arr;

        arr.push_back(jumbo);
        arr.push_back(small);
        
        return arr;
    }
};
