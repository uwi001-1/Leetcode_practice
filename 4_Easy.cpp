#include<iostream>
using namespace std;

// 9. Palindrome Number

/***************
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
Input: x = 121
Output: true
    Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
    Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
    Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
***************/

class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0)    //negative num is never palindrome
            return false;

        long long rev = 0;  //use long long to avoid INTEGER OVERFLOW
        int org = x;

        while(x > 0)
        {
            int a = x % 10;
            rev = rev * 10 + a;
            x = x /10;
        }

        return rev == org;
    }
};