#include<iostream>
using namespace std;

// 367. Valid Perfect Square

/***************
Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. 
In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.

Example 1:
Input: num = 16
Output: true
    Explanation: We return true because 4 * 4 = 16 and 4 is an integer.

Example 2:
Input: num = 14
Output: false
    Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.
***************/


// to use the pow function
#include <cmath>

class Solution {
public:
    bool isPerfectSquare(int num)
    {
        if(num == 1) return true;

        // loop from 2
        int i = 2; 

        while(true)
        {
            // if i^2 == num then return true
            if(num == pow(i,2)) return true;

            // as square root of 2^31 that's the max is 46340.95
            if(i >= 46340) break;
            
            i += 1;
        }

        // if never true return false
        return false;
    }
};
