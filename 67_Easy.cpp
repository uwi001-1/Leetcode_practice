#include<iostream>
using namespace std;

// 14. Longest Common Prefix

/***************
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
    Explanation: There is no common prefix among the input strings.
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
