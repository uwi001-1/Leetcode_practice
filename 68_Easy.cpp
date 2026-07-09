#include<iostream>
using namespace std;

// 242. Valid Anagram

/***************
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
***************/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int first = strs[0].size();
        int i = 0;
        bool same = false;
        string newChar = "";
        char letter;

        while(i < first)
        {
            same = false;
            for(int j = 0; j < strs.size(); j++)
            {
                letter = strs[0][i];

                if(i >= strs[j].size())
                {
                    same = false;
                    break;
                }
                
                if(letter == strs[j][i]) same = true;
                else
                {
                    same = false; 
                    break;
                }
            }
            if(same) newChar = newChar + letter;
            else break;
            
            i++;
        }

        return newChar;  
    }
};
