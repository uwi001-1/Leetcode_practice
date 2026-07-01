#include<iostream>
using namespace std;

// 1780. Check if Number is a Sum of Powers of Three

/***************
Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.

Example 1:
Input: n = 12
Output: true
    Explanation: 12 = 31 + 32

Example 2:
Input: n = 91
Output: true
    Explanation: 91 = 30 + 32 + 34

Example 3:
Input: n = 21
Output: false
***************/


// to use the pow function
#include <cmath>

class Solution {
public:
    // The number can not be represented as a sum of powers of 3 if it's ternary presentation has a 2 in it
    bool checkPowersOfThree(int n) 
    {
        int value = -1;

        // try the ternary presentation
        // till n becomes 0
        while(true)
        {
            // get the remainder
            value = n % 3;

            // divide the number
            n = n / 3;

            // if the remainder is ever 2 then it's not a sum of powers of three
            if(value == 2) return false;

            // if number reaches 0 break
            if(n == 0) break;
        }

        // if never 2 then it's true
        return true;
    }
};
