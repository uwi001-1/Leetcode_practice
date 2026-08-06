#include<iostream>
using namespace std;

// 3345. Smallest Divisible Digit Product I

/***************
You are given two integers n and t. 
Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.

Example 1:
Input: n = 10, t = 2
Output: 10
Explanation:
The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.

Example 2:
Input: n = 15, t = 3
Output: 16
Explanation:
The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.
***************/


class Solution {
public:
    int smallestNumber(int n, int t) 
    {
        int num = n;

        while(true)
        {
            int pro = 1;
            int x = num; 

            if (x == 0)
                pro = 0;
            else 
            {
                while(x > 0)
                {
                    pro *= x % 10;
                    x = x / 10;
                }
            }

            if(pro % t == 0) return num;

            num++;
        }
    }
};
