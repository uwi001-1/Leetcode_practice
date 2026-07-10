#include<iostream>
using namespace std;

// 172. Factorial Trailing Zeroes

/***************
Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.


Example 1:
Input: n = 3
Output: 0
    Explanation: 3! = 6, no trailing zero.

Example 2:
Input: n = 5
Output: 1
    Explanation: 5! = 120, one trailing zero.

Example 3:
Input: n = 0
Output: 0
***************/


class Solution {
public:
    // Trailing zeros come from factors of 10
    int trailingZeroes(int n) 
    {
        if(n == 0) return 0;

        int count = 0;
        
        // n/5 + n/25 + n/125 + n/625 + ...
        while(n >= 5)
        {
            n /= 5;
            count += n;
        }
        return count;     
    }
};
