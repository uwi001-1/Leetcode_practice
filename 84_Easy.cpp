#include<iostream>
using namespace std;

// 258. Add Digits

/***************
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

Example 1:
Input: num = 38
Output: 2
    Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.

Example 2:
Input: num = 0
Output: 0
***************/


class Solution {
public:
    bool isHappy(int n) {
        bool happy = false;
        int count = 0;
        
        if(n == 1) return true;

        while(happy == false && count < 50)
        {
            int sum = 0;

            while(n > 0)
            {
                // one of the digit
                int last = n % 10;
                
                sum = sum + (last * last);

                // reduce the number
                n = n / 10;
            }

            if(sum == 1) happy = true;

            count += 1;
            n = sum;
        }
        return happy;
    }
};
