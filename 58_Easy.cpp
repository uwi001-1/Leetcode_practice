#include<iostream>
using namespace std;

// 383. Ransom Note

/***************
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true
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
