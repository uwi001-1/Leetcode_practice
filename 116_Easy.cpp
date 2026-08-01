#include<iostream>
using namespace std;

// 345. Reverse Vowels of a String

/***************
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:
Input: s = "IceCreAm"
Output: "AceCreIm"
Explanation:
The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:
Input: s = "leetcode"
Output: "leotcede"
***************/


class Solution {
public:
    string winningPlayer(int x, int y) 
    {
        // base case - when Alice can't play at first 
        if(y < 4) return "Bob";

        bool Alice = false;
        bool Bob = true;

        while(x >= 1 && y >= 4)
        {
            // reduce it by needed 
            x -= 1;
            y -= 4;

            if(Bob) 
            {
                Alice = true;
                Bob = false;
            }
            else 
            {
                Bob = true;
                Alice = false;
            }
        }

        if(Bob) return "Bob";
        return "Alice";   
    }
};
