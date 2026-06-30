#include<iostream>
using namespace std;

// 1358. Number of Substrings Containing All Three Characters

/***************
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

Example 1:
Input: s = "abcabc"
Output: 10
    Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

Example 2:
Input: s = "aaacb"
Output: 3
    Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

Example 3:
Input: s = "abc"
Output: 1
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
