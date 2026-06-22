#include<iostream>
using namespace std;

// 1189. Maximum Number of Balloons

/***************
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

Example 1:
Input: text = "nlaebolko"
Output: 1

Example 2:
Input: text = "loonbalxballpoon"
Output: 2

Example 3:
Input: text = "leetcode"
Output: 0
***************/


class Solution {
public:
    int maxNumberOfBalloons(string text) 
    {
        int b = 0, a = 0, l = 0, o = 0, n = 0;

        // count the number of times the ballon letters appear in the string
        for(int i = 0; i < text.size(); i++)
        {
            if(text[i] == 'a') a += 1;
            if(text[i] == 'b') b += 1;
            if(text[i] == 'l') l += 1;
            if(text[i] == 'o') o += 1;
            if(text[i] == 'n') n += 1;
        }

        // min() takes two values and returns the smaller one
        return min({b, a, l/2, o/2, n});
    }
};
