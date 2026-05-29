#include<iostream>
#include <string> 
using namespace std;

// 2396. Strictly Palindromic Number

/***************
An integer n is strictly palindromic if, for every base b between 2 and n - 2 (inclusive), the string representation of the integer n in base b is palindromic.
Given an integer n, return true if n is strictly palindromic and false otherwise.
A string is palindromic if it reads the same forward and backward.

Example 1:
Input: n = 9
Output: false
    Explanation: In base 2: 9 = 1001 (base 2), which is palindromic.
    In base 3: 9 = 100 (base 3), which is not palindromic.
    Therefore, 9 is not strictly palindromic so we return false.
        Note that in bases 4, 5, 6, and 7, n = 9 is also not palindromic.

Example 2:
Input: n = 4
Output: false
    Explanation: We only consider base 2: 4 = 100 (base 2), which is not palindromic.
    Therefore, we return false.
***************/


// This is supposed to be a famous troll Leetcode problem
// The answer will always be false for n>3; could have just done return false
// Because with the base n-2 for any number it will be 12 and it is never a palindrome. 

class Solution {
public:
    bool checkPalindrome(int n)
    {
        int org = n;
        int ne = 0;
        for(int i=0; i<to_string(n).length(); i++)
        {
            ne = ne * 10 + (n % 10);
            n = n/10;
        }
        if(ne == org)
            return true;
        return false;
    }

    bool isStrictlyPalindromic(int n) 
    {
        for(int i=2; i<=n-1; i++)
        {
            int check = 0;
            int x = n;
            while(x > 0)
            {
                check = check * 10 + (x % i);
                x = x/i;
            }
            if(!checkPalindrome(check))
                return false;
        }
        return true; 
    }
};
