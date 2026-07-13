#include<iostream>
using namespace std;

// 1291. Sequential Digits

/***************
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

Example 1:
Input: low = 100, high = 300
Output: [123,234]

Example 2:
Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
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
