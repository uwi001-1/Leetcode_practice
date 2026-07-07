#include<iostream>
using namespace std;

// 3754. Concatenate Non-Zero Digits and Multiply by Sum I

/***************
You are given an integer n.

Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.

Let sum be the sum of digits in x.

Return an integer representing the value of x * sum.

Example 1:
Input: n = 10203004
Output: 12340
    Explanation:
    The non-zero digits are 1, 2, 3, and 4. Thus, x = 1234.
    The sum of digits is sum = 1 + 2 + 3 + 4 = 10.
    Therefore, the answer is x * sum = 1234 * 10 = 12340.

Example 2:
Input: n = 1000
Output: 1
    Explanation:
    The non-zero digit is 1, so x = 1 and sum = 1.
    Therefore, the answer is x * sum = 1 * 1 = 1.
***************/


class Solution {
public:
    long long sumAndMultiply(int n) 
    {
        // base case
        if(n == 0) return 0;

        int digit;
        long long  sum = 0; 
        long long  x = 0;
        int i = 1; 

        while(n > 0)
        {
            // remainder
            digit = n % 10;

            // remove one digit from back 
            n = n / 10;

            // skip if zero
            if(digit == 0) continue;

            sum += digit; 
            x += digit * i;
            i *= 10;
        }
        
        long long ans = sum * x;

        return ans;
    }
};
