#include<iostream>
using namespace std;

// 58. Length of Last Word

/***************
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5
    Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
    Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
    Explanation: The last word is "joyboy" with length 6.
***************/


class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int started = false;
        int count = 0;

        // loop from back of s 
        for(int i = s.size()-1; i >=0; i--)
        {
            // if letter was counted
            if(started == true)
            {
                // and we reach a space, then we need to finsih counting
                if(s[i] == ' ') break;
            }
            else
            {
                // word hasn't been reached, avoid all the spaces before the last word
                if(s[i] == ' ') continue;
            }

            // if it's not space, then count all the words
            if(s[i] != ' ')
            {
                started = true;
                count += 1;
            }
        }
        
        return count;
    }
};
